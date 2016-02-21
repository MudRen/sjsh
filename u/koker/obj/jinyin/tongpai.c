#include <ansi.h>

inherit ITEM;

int do_wear(string);
void create()
{
  set_name(HIC "ͭ��" NOR, ({"tong pai", "pai"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "������ˮ½���õ�������ҵġ�\n");
    set("value", 5000);
    set("no_sell", 1);
       set("no_drop", 1);
       set("no_put", 1);
       set("no_get", 1);
  }
  
  setup();
}

void init()
{
        add_action("do_wear", "wear");
}

int do_wear(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

        message_vision(HIC"$N����һ�����ƣ�����ʵ��������\n"NOR, me);  
  
        me->add("potential", 10000);
        me->add("daoxing", 10000);
        me->add("combat_exp", 10000);

  destruct(this_object());
  return 1;
}

