// shugan.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit STAFF;

void create()
{
	set_name("����", ({ "shugan", "staff" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
              set("keenness", 0);
		set("long", "����һ���ֳ�����֦��\n");
		set("weapon_prop/courage", -4);
	}
	init_staff(5);
	setup();
}
