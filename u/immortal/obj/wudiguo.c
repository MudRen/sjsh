#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
  if (!wizardp(this_player())) {
    set("no_give","��ô����ҩ�����������ˣ�\n");
    set("no_drop","��ô����ĵ�ҩ�����˶��ϧѽ��\n");
    set("no_sell","��������֪��"+this_object()->query("name")+"�ļ�ֵ�������Լ����Űɡ�\n");
  }
  add_action("do_eat", "eat");
}
void create()
{
  set_name(RED "�޵й�" NOR, ({"wudi guo","guo"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("long", "һö���Ժ�����ɽ��ɫ���������档\n");
    set("value", 0);
    set("drug_type", "��Ʒ");
  }
  set("is_monitored",1);
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  int mana_add, howold;
  howold= (int)me->query("mud_age") + (int)me->query("age_modufy");
  if (!id(arg))
    return notify_fail("��Ҫ��ʲô��\n");  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  if( howold > 864000 ) {
    me->add("maximum_force", 1000);
    me->add("max_force", 1000);
    me->add("force", 1000);
    me->add("maximum_mana", 1000);
    me->add("max_mana", 1000);
    me->add("max_mana", 1000);
    me->add("mana", 1000);
  message_vision(HIC "$N����һ��"NOR+HIR"�޵й�"NOR+HIC"��ֻ������Ѫ�����ڣ�������̣�\n"NOR,me);
  destruct(this_object());
  }
  return 1;
}
