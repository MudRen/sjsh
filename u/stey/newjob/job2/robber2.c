// robber1 for dart

#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
        set_name("ħ��������",({"mojie jiangling"}));
        set("long","����һλ�ַ�����칬��ħ�������졣\n");
        set("gender", "����" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("attitude", "peaceful");    
        set("bellicosity", 100000);
        set("max_kee", 2000);
        set("eff_kee", 2000);
        set("max_sen", 2000);
        set("shen", 2000);
        set("froce", 2500);
        set("max_force", 2500);
        set("force_factor", 100);
        set("mana", 500); 
	set("max_mana", 2500);
	set("mana_factor", 100);
        set("shen_type", -10);
        set("combat_exp", 900000);
        set("doxing", 900000);
  

        set_skill("force", 180); 
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
   
        setup();
        carry_object(__DIR__"wandao")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player(); 
      
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

      if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
                  if(sname[i]=="force")i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }
        me->set_skill("zileidao", temp-random(50));
        me->set_skill("unarmed",temp-random(50));
        me->set_skill("huxiaoquan",temp-random(50));
        me->set_skill("dodge", temp-random(50));
        me->set_skill("blade", temp-random(50));
        me->set_skill("parry", temp-random(50));

        me->map_skill("blade","zileidao");
        me->map_skill("parry","zileidao");
        me->map_skill("unarmed","huxiaoquan");
//        prepare_skill("unarmed", "huxiaoquan");



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("cps", hp_status["cps"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*5/4);
            me->set("ygjg",ob);

}

void die()
{
            object ob;
              object robber;
              object room;
             ob=query_temp("last_damage_from");
               room = environment(ob);   

                  if(ob->query_temp("start_job")==1)
                  {
                        ob->add_temp("killed_mgb",1);
                  }
                  else
                        ob->add_temp("help_killed",1);
                 switch( random(3) ) {
                        case 0:
                        message_vision(HIR"������������һ��ħ�������ʿ��\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(HIR"������������һ��ħ�������졣\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 2:
                        message_vision(HIR"������������һ��ħ��������֡�\n" NOR,ob); 
                        robber=new(__DIR__"robber3");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        }       
              message_vision("$N���ڵ��������˼��£������������"HIR"��Ѫ"NOR"�����ˣ�\n",this_object());
                   destruct(this_object());
            return;
}

