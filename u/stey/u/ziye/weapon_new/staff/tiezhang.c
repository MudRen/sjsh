// staff.c
//add keenness by ziye 2001/3

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( "����", ({ "tie zhang", "zhang", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "һ�����ص����ȡ�\n");
		set("value", 1000);
		set("no_sell",1);
              set("keenness", 0);
		set("material", "steel");
	}

	init_staff(20);
	setup();
}
