// repoo
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"����"NOR, ({ "chi long", "long", "dragon" }) );
        set("gender", "����" );
        set("long",HIC
                "������������\n"NOR);
 
        set("age",50);
         set("nickname", HIW"�����ǻ�����"NOR);
         set("title", HIB"�˲�����"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
        set("combat_exp",2500000);
      set("daoxing",4500000);
        set("force",5000);
        set("max_force",3000);
        set("mana",5000);
        set("max_mana",3000);
   set("force_factor",150);
        set("mana_factor",120);
        set("eff_dx", 4500000);
        set("nkgain", 1500);
        set_skill("unarmed",180);
        set_skill("dragonfight", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
              set_skill("dragonstep",180);
        set_skill("fork",180);
        set_skill("fengbo-cha",180);
        set_skill("force",180);
              set_skill("dragonforce",200);
        set_skill("spells", 180);
        set_skill("seashentong", 180);
              map_skill("force","dragonforce");
              map_skill("spells", "seashentong");
        map_skill("dodge", "dragonstep");
        map_skill("parry", "fengbo-cha");
        map_skill("fork","fengbo-cha");
        map_skill("unarmed", "dragonfight");
        set("inquiry", ([
                "name" : "���³��������Ͱ��س����ǡ�",
                        ]) );
    //    set("chat_chance_combat", 50);
        //      set("chat_msg_combat", ({
       //         (: perform_action,"unarmed","sheshen" :),
      //          (: cast_spell, "dragonfire" :),                
     //   }) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
   //     carry_object("/d/obj/weapon/hammer/jingua")->wield();
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("xue",8+random(8),me,ob);  
  ::
kill_ob(ob);
}
void xue (object me, object ob)
{
  object huobing;
  int damage;
  if (! me)
    return;
  if( !living(me) )
    return;
  if (! ob)
    return;
  if (environment(ob) != environment(me))
    return;
  message_vision ("$N"HIW"�ſ����죬�������˼��������ʱ������ӿ��һƬ��ѩ��$n������\n"NOR,me,ob);
  if ( ((int)ob->query_skill("dodge", 1)+ random(100)) > 240 )
     message_vision (HIC"$N����Ծ������У���������һ����\n"NOR,ob);
 else 
    {
     message_vision (HIW"���$N����ס�����ж���\n"NOR,ob,me);
     ob->start_busy(3+random(5));
    } 
  remove_call_out ("xue");  
  call_out ("xue",random(10)+10,me,ob);  
}
void die ()
{
  object me = this_object();
   object ob = query_temp("my_killer");
  object yi;
  string longyi_given;
  longyi_given = "/u/repoo/mofamen/obj/longyi.c";
     ob->set_temp("chilong_killed",1);
   ob->delete_temp("chilong_killing");
   if (!longyi_given->in_mud())
         {
  yi = new("/u/repoo/mofamen/obj/longyi");
  yi->move(ob);
   message_vision ("$N"HIY"�����Ӵܣ���������Ǵ���....\n"+HIM"һ�Գ�������$n���ϡ�\n"NOR,me,ob);
 message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+ob->query("name")+"�õ�"+HIY"����"+HIB"֮��"NOR+YEL"�ˣ�\n\n"+NOR,users() );
  destruct (this_object());
  return ;
       }
    else
       {
  message_vision ("$N"HIY"����һ�����......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
