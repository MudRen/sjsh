// mihoutao.c �Ƶ�

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
set_name(YEL "�Ƶ�" NOR, ({"yun dan","yuandan","dan"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���е㵭�Ƶ�С����,����ȥûʲô���á�\n");
set("value", 1000000);
    set("drug_type", "��Ʒ");
  }

  setup();
}

int do_eat(string arg)
{
  object me = this_player();

  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");

  me->set("food", (int)me->max_food_capacity());
me->add_maximum_force(300);
me->add_maximum_mana(300);
me->add_maximum_mana(300);
  message_vision(HIG "$N����һ���Ƶ����̲�ס����,������ôҲ�²����� \n" NOR, me);

  destruct(this_object());
  return 1;
}
