// zhujian.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("��",({ "zhu jian","zhujian", "jian", "sword" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 100);
		set("material", "wood");
              set("keenness", 4);
		set("long", "����һ�����������������Ƴɵ����񽣣��䲻������ȴ�����ˡ�\n");
		set("wield_msg", "$N�ó�һ��$n���������С�\n");
		set("unequip_msg", "$N�������е�$n��\n");
	}
	init_sword(10);
	setup();
}
