
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
//    set("no_get", 1);
 //   set("no_give", 1);
    set("no_drop", 1);
    set("no_sell", 1);
  }
    if(this_player()==environment())
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIY "�𱦱�����ѡ��" NOR , ({"chongxuan dan", "dan"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ�Ž��ɫ�Ľ𱦱���pk ��ѡ���裬��΢���ŵ�Щ��������\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="huanhun dan")	return 0;
  
  me->delete("ziyouchoose");
  me->delete("pk");
  me->delete("ziyou");

  message_vision(HIG "$N��������һ�Ž𱦱���pk ��ѡ���������У�һʱ���������硣
ֻ��$N�Դ��տ���Ҳ���������е�����ģ�\n" NOR, me);
  destruct(this_object());
  return 1;
}

