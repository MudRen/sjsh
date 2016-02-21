// robber1 for dart

#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
        set_name("ħ���������",({"mojie gaoshou"}));
        set("long","����һλ�ַ�����칬��ħ�������书���֡�\n");
        set("gender", "����" );
        set("age", random(30)+14);
        set("vendetta/authority", 1);
        set("attitude", "peaceful");    
        set("bellicosity", 100000);
        set("max_kee", 2500);
        set("eff_kee", 2500);
        set("max_sen", 2500);
        set("shen", 2500);
        set("froce", 3500);
        set("max_force", 3500);
        set("force_factor", 150);
        set("mana", 3500); 
	set("max_mana", 3500);
	set("mana_factor", 150);
        set("shen_type", -10);
        set("combat_exp", 1200000);
        set("doxing", 1200000);
  
        

        set_skill("force", 220); 
        set_skill("unarmed", 220);
        set_skill("dodge", 220);
        set_skill("parry", 220);
	set("chat_chance_combat", 60);  
	set("chat_msg_combat", ({
        (: perform_action,"blade", "tulong" :),	
        (: perform_action,"blade", "tulong" :),	
        (: perform_action,"sword", "pili" :),
        (: cast_spell, "zhui" :),
        (: cast_spell, "sishi" :),
        (: cast_spell, "sishi" :),         
        }) );

     
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

        me->set_skill("zileidao", temp+random(10));
        me->set_skill("unarmed",temp+random(10));
        me->set_skill("huxiaoquan",temp+random(10));
        me->set_skill("dodge", temp+random(10));
        me->set_skill("blade", temp+random(10));
        me->set_skill("parry", temp+random(10));
        me->set_skill("spells", temp+random(10));
        me->set_skill("huxiaojian", temp+random(10));
        me->set_skill("tianyaofa", temp+random(10));
        me->set_skill("huntianforce", temp+random(10));
//        me->set_skill("huntian-qigong", temp+random(10));

        me->map_skill("force", "huntianforce");
        me->map_skill("dodge", "shenkong-xing");
        me->map_skill("spells", "tianyaofa");
        me->map_skill("parry", "zileidao");
        me->map_skill("blade", "zileidao");
        me->map_skill("sword", "huxiaojian");
        me->map_skill("unarmed","huxiaoquan");
        me->set_temp("apply/damage", 150);
if (random(20)>15)
{
        me->set_temp("apply/attack", 200);
        me->set_temp("apply/defense", 200);
        me->set_temp("apply/armor", 200);
        me->set_temp("apply/damage", 200);
}
        
//        me->map_skill("blade","wuhu-duanmendao");
//        me->map_skill("parry","wuhu-duanmendao");
        me->map_skill("unarmed","huxiaoquan");
//        prepare_skill("unarmed", "huxiaoquan");



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("cps", hp_status["cps"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]*5/4);
        me->set("daoxing",hp_status["daoxing"]*5/4);
        me->set("ygjg",ob);
        me->set("max_mana",    hp_status["max_mana"]*3/4);
//	me->set("eff_mana",    hp_status["max_mana"]*3/4);
	me->set("mana",        hp_status["max_mana"]*3/4);
	me->set("max_sen",  hp_status["max_sen"]*3/4);
	me->set("eff_sen",  hp_status["eff_sen"]*3/4);
	me->set("sen",      hp_status["eff_sen"]*3/4);
	me->set("max_kee",  hp_status["max_kee"]*3/4);
	me->set("eff_kee",  hp_status["eff_kee"]*3/4);
	me->set("kee",      hp_status["eff_kee"]*3/4);
	me->set("max_force", hp_status["max_force"]*3/4);
	me->set("force",     hp_status["max_force"]*3/4);
	me->set("force_factor", hp_status["force_factor"]*3/4);
	me->set("mana_factor", hp_status["mana_factor"]*3/4);

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
                 switch( random(5) ) {
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
                        case 3:
                        message_vision(HIR"������������һ��ħ�������ʿ��\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 4:
                        message_vision(HIR"������������һ��ħ�������졣\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
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

