#include <ansi.h>
inherit ITEM;
void init();
void init()
{
if (!wizardp(this_player())) {
  set("no_drop","��ô����Ķ�������������! \n");
}
add_action("do_eat", "eat");
}
void create()
{
set_name(HIM "�����Ƶ�" NOR, ({"lyy dan", "dan"}));
set_weight(20);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "��");
 set("long", "һ�������Ƶ������ݵĺ�!\n");
set("value", 100);
}
setup();
}
int do_eat(string arg)
{
object victim = this_player();
if (!id(arg))
return notify_fail("��Ҫ��ʲô��\n");
 victim->add("potential",300000);
victim->save();
 message_vision(WHT "\n$N����һ�������Ƶ�,��У����ݣ�����!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
