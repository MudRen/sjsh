#include <ansi.h>

inherit ITEM;

void create()
{
set_name( HIC "�ɻ�" NOR , ({"feiji"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ֻ");
    set("value", 0);
  }
  setup();
}
void init()
{
  add_action("do_fang", "fang");
}

int do_fang(string arg)
{
  object me = this_player();
  object ob;

  message_vision ("$Nһ�����еķɻ����ɻ��ڷ��з���������\n",me,ob);
  call_out("fly",5,ob);  
  return 1;
}
void fly (object ob)
{
  object me = this_player();
  message_vision (HIC"�ɻ��ڷ��з��š�\n" NOR,me,ob);
}

