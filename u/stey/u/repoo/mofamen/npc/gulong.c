// repoo
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"����"NOR, ({ "gu long", "long", "dragon" }) );
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
      set("combat_exp",1800000);
        set("daoxing",3500000);
        set("force",5000);
        set("max_force",3000);
       set("mana",200);
        set("max_mana",200);
    set("force_factor", 20);
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
                "name" : "���¹��������Ͱ��ع����ǡ�",
                        ]) );
        set("chat_chance_combat", 50);
              set("chat_msg_combat", ({
       //         (: perform_action,"unarmed","sheshen" :),
                (: cast_spell, "dragonfire" :),                
        }) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
   //     carry_object("/d/obj/weapon/hammer/jingua")->wield();
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("gu",5+random(5),me,ob);  
  ::
kill_ob(ob);
}
void gu (object me, object ob)
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
  message_vision ("$N"HIW"�ͳ�һ��"+HIB"����֮��"+HIW"����ಡ���һ�������ⶪȥ��������\n"NOR,me);
  if ( (ob->query("mana")+random(1000)) > 3500 )
     message_vision (HIR"$N"HIC"����΢�����㿪��һ����\n"NOR,ob);
  else 
    {
     message_vision (HIW"$N"HIM"��������ħһ�����ٸ�ͷ�����ǣ�\n"NOR,ob);
     damage=(me->query("mana"))/3; 
     if ( ob->query("sen") < damage ) ob->unconcious();
     else ob->add("sen",-damage);
    } 
  remove_call_out ("gu");  
  call_out ("gu",random(10)+9,me,ob);  
}
void die ()
{
  object me = this_object();
 object ob = query_temp("my_killer");
  object bone;
  string bone_given,gujian_given;
  bone_given = "/u/repoo/mofamen/obj/gujian.c";
 gujian_given = "/u/repoo/mofamen/obj/bone.c";
      ob->set_temp("gulong_killed",1);
   if ((!bone_given->in_mud()) && (!gujian_given->in_mud()))
         {
  bone = new("/u/repoo/mofamen/obj/bone");
  bone->move(ob);
   message_vision ("$N"HIY"���һ��:�б���,���⸱�Ϲ�ͷ,������......\n"NOR,me);
  destruct (this_object());
  return ;
       }
    else
       {
 message_vision ("$N"HIY"��ͷɢ��һ��......\n"NOR,me);
 destruct (this_object());
 return ;
         }
  return ;
}
