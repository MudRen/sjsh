#include <ansi.h>
inherit ITEM;
void init();
void init()
{
if (!wizardp(this_player())) {
  set("no_drop","��ô����Ķ�������������! \n");
  set("no_give","��ô����Ķ����������Լ����Ű�! \n");
}
add_action("do_eat", "eat");
}
void create()
{
set_name(HIR"���˵�" NOR, ({HIY"yuren dan"NOR, "dan"}));
set_weight(20);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
 set("long", "һ�����˵�����xlqy��ʦ�鷢����ҵ����˽�����!\n");
set("value", 0);
}
setup();
}
int do_eat(string arg)
{
object victim = this_player();
if (!id(arg))
return notify_fail("��Ҫ��ʲô��\n");
 victim->add("potential",1);
 victim->add("combat_exp",1);
 victim->add("daoxing",1);
victim->save();
 message_vision(HIM "\n$N����һ�����˵�,������ϵ����ϵ�!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
