// repoo
#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"����"NOR, ({ "hei long", "long", "dragon" }) );
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
        set("mana",5000);
        set("max_mana",3000);
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
                "name" : "���º��������Ͱ��غ����ǡ�",
                        ]) );
        set("chat_chance_combat", 50);
              set("chat_msg_combat", ({
                (: perform_action,"unarmed","sheshen" :),
       //         (: cast_spell, "dragonfire" :),                
        }) );
              setup();
        carry_object("/d/sea/obj/longpao")->wear();
   //     carry_object("/d/obj/weapon/hammer/jingua")->wield();
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  call_out ("huo",5+random(5),me,ob);  
  ::
kill_ob(ob);
}
void huo (object me, object ob)
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
  message_vision ("$N"HIC"�ӿ����³�"HIR"��"HIB"ζ"HIM"���� "HIC"���ڿ��У�����һ��"HIW"��ǽ"
       HIR+"ֻ�����˹�������$n������\n"NOR,me,ob);
  if ( (ob->query("force")+random(1000)) > 4000 )
     message_vision (HIY"$N���һ����ȥ��\n"
       +HIR"�����ǽ"+HIY" ��ʱ������ɢ��\n"NOR,ob,me);
  else 
    {
     message_vision (HIR"���$N����ǽ��ȫ��û�ˣ�\n"NOR,ob,me);
     damage=(me->query("force"))/2; 
     if ( ob->query("kee") < damage ) ob->unconcious();
     else ob->add("kee",-damage);
    } 
  remove_call_out ("huo");  
  call_out ("huo",random(10)+9,me,ob);  
}
void die ()
{
    object me = this_object();
   object ob = query_temp("my_killer");
  object zhua;
  string zhua_given;
  zhua_given = "/u/repoo/mofamen/obj/longzhua.c";
      ob->set_temp("heilong_killed",1);
   if (!zhua_given->in_mud())
    {
  zhua = new("/u/repoo/mofamen/obj/longzhua");
  zhua->move(ob);
 message_vision ("\n$N"HIY"�������ߣ�$n�ӻ����ͳ�һ�����������䣬������������צ....\n\n"NOR,me,ob);
message("channel:rumor",YEL+"\n��"+HIB" �˲����� "NOR+YEL"��ĳ�ˣ�"+ob->query("name")+"�õ�"+HIB"����"+HIR"֮צ"NOR+YEL"�ˣ�\n\n"+NOR,users() );
  destruct (this_object());
  return ;
  }
else
  {
  message_vision ("$N"HIY"��ʧ�ڻ����......\n"NOR,me);
  destruct (this_object());
  return ;
}
}
