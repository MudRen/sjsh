#include <ansi.h>
inherit NPC;
string dh();
string wx();
string gold();
string potential();
string force();
string mana();
void create()
{
set_name("��ҧ��", ({ "cheng yaojin", "cheng", "yaojin", "master", "shifu" }));
  set("title", "����Ԫѫ");
  set("gender", "����");
  set("long","
��ҧ���Ǵ��ƿ��������ĸ�������������ѧ��һ��������ƥ��
�������������������ݵ���һ����졣̸�����ĸ����������
������Ľ��
");
  set("inquiry", ([
 "dh"     : (: dh :),
 "wx"     : (: wx :),
 "force"   : (: force :),
 "mana"     : (: mana :),
 "gold" :  (: gold :),
 "potential"     : (: potential :),
]) );
string dh()
{
    this_player()->add("daoxing",100000+random(50000));
}
string wx()
{
    this_player()->add("combat_exp",100000+random(50000));
}
string force()
{
    this_player()->add("max_force",100);
}
string mana()
{
    this_player()->add("max_mana",100);
}
string gold()
{
    this_player()->add("deposit",1000000);
}
string potential()
{
    this_player()->add("potential",10000+random(5000));
}
void init()
{
  add_action("do_yao", "yao");
}
int do_yao(string arg)
{
  object me=this_player();
    int i;
  i=me->query_skill(arg);
   me->set_skill(arg,i+100+random(20));
    return 1;
}
