// scythe.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("��������", ({ "scythe", "blade", "dao", "lian dao", "lian" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 300);
		set("material", "wood");
                        set("keenness", 2);
		set("long", "����һ��ũ����õĳ���������\n");
		set("wield_msg", "$N���һ��$n�������У������ϻ����ŵ��ݡ�\n");
		set("unwield_msg", "$N�����е�$n��������С�\n");
	}
	init_blade(10, TWO_HANDED);
	setup();
}
