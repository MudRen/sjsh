// changjian.c ����

#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
    set_name(HIG "ԧ�������" NOR, ({"dao", "blade"}));
    set_weight(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
        set("unit", "��");
        set("long", "����һ�Լ�������˫����\n");
        set("value", 1);
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
        set("unwield_msg", "$N�����е�$n������С�\n");
	}
    init_blade(12345);
	setup();
}
