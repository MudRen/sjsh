
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get", 1);
    set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set_name( HIY "�����������������ò��" NOR , ({"dan", "rongmao dan"}));
     set("long", "һ�ŵ���ɫ���޸���ò�ĵ��裬��΢���ŵ�Щ��������\n");
       set("value",1000000);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
   if (arg!="dan" && arg!="rongmao dan") return 0;
  
me->add("per",1);

    message_vision(HIG "$N��������һ����ò���������У�һʱ���������硣
    ֻ��$N�ݹ�����������������ĺÿ��ˣ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

