// created 19/3/2001 by Repoo and Xuexu
inherit NPC;
string try_me();
inherit F_MASTER;
#include <ansi.h>
void create()
{
set_name(HIW"����֮��"NOR, ({"shen","shenpan shen"}));
set("long","һ������������������Ȩ����������ش�����һ��һ�佫��Ϊ�����Ĺؼ���\n");
set("title", HIR"��������"NOR);
set("gender", "����");
set("age", 80);
set("class", "yaomo");
set("attitude", "friendly");
set("rank_info/respect", "����֮��");
set("per", 30);
set("int", 30);
set("max_kee", 3500);
//       set("max_gin", 3500);
set("max_sen", 3500);
set("force", 10000);
set("max_force", 5000);
set("force_factor", 500);
set("max_mana", 5000);
set("mana", 10000);
set("mana_factor", 500);
set("combat_exp", 5000000);
set("daoxing", 6000000);
set("eff_dx", 200000);
set("nkgain", 350);
set_skill("literate", 180);
set_skill("dodge", 220);
set_skill("force", 220);
set_skill("parry", 220);
set_skill("sword", 220);
set_skill("spells", 400);
set_skill("dengxian-dafa", 400);
set_skill("ningxie-force", 400);
set_skill("bainiao-jian", 230);
set_skill("xiaoyaoyou", 220);
map_skill("spells", "dengxian-dafa");
map_skill("force", "ningxie-force");
map_skill("dodge", "xiaoyaoyou");
map_skill("sword", "bainiao-jian");
map_skill("parry", "bainiao-jian");
    set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                   (: cast_spell, "jieti" :),   
        }) );
set("inquiry", ([
      "�����": (: try_me :),
]));
create_family("��ѩɽ", 2, "����");
setup();
carry_object("/d/obj/armor/jinjia")->wear();
}
void init()
{
        add_action("do_answer", "answer");
        add_action("do_look", "look");
}
int do_answer(string arg)
{
    object me = this_object();
     object ob = this_player();
        if( !arg ) return notify_fail("�Ϸ�����������answer yes or no\n");
        message_vision("$N�����" + arg + "\n", this_player());
        if( arg== "yes" ) {
           if(this_player()->query("PKS") == 0)
          {
message_vision("$N�������˵�������ڵĻѻ�����������ʥ������֮���Ҫ�������ۡ�\n", me);
         command("kill " + ob->query("id"));
       return 1;
          }
          {
message_vision("$N�����������ʵ����ͨ���Ϸ�������ˡ�\n", me);
        return 1;
           }
          }
          else
          {
       if( arg== "no" ) {
         if(this_player()->query("PKS") != 0 )
         {
message_vision("$N��Цһ������˵�������ڵĻѻ������ھͰ�������˵�Ļ����������۰ɣ�\n", me);
         command("kill " + ob->query("id"));
        return 1;
         }
          }
          else
          {
command("say �Ϸ����޻�̸֮���������ء�\n");
       return 1;
          }
command("say �����Ϸ��������ǰȥ������֮���޲T��\n");
          return 1;
}
}
string try_me()
{
          return "������ɱ����û��(answer)��\n";
}
int do_look(string arg)
{
     object me = this_player();
     if(arg == me->query("id"))
   {
command("say ��ʲô�����Լ�ɱûɱ���˲�֪����?\n");
   return 1;
   }
   else
   {
    return 0;
}
}
