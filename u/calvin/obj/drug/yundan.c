// mihoutao.c 云丹

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
set_name(YEL "云丹" NOR, ({"yun dan","yuandan","dan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗有点淡黄的小珠子,看上去没什么大用。\n");
set("value", 1000000);
    set("drug_type", "补品");
  }

  setup();
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("你要吃什么？\n");

  me->set("food", (int)me->max_food_capacity());
me->add_maximum_force(300);
me->add_maximum_mana(300);
me->add_maximum_mana(300);
  message_vision(HIG "$N吃下一颗云丹，忍不住想吐,可是怎么也吐不出！ \n" NOR, me);

  destruct(this_object());
  return 1;
}
