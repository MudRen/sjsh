#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
set_name(HIY"���յ���", ({"birthday cake"}) );
set_weight(1);
set("unit", "��");
set("long", "�̻�ɫ�ĵ��⣬����������ģ������ϻ���׺�����ſɰ��ĺ�ӣ�ҡ�\n");
set("value",100000);
setup();
}
void init()
{
add_action("do_eat","eat");
if (!query("owner")) add_action("do_celebrate","celebrate");
else {
add_action("do_cut","cut");
} 
}
int do_eat(string arg)
{
object me = this_player();
if (!id(arg))
return notify_fail("��Ҫ��ʲô��\n");
write(HIY"��С������İ�С��ӣ�ҷŵ�������𰡡������������͵ĵ��⣬���ɵ������ʿ�ˮ�������˵�ף��������appy Birthday�������̻��ʵĳ�����������յ��⡣\n"NOR,me);
 return 1;
}
setup();
