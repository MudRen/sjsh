// bintiegun.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("������", ({ "bintiegun","tiegun","gun", "bang" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 2000);
		set("material", "steel");
              set("keenness", 0);
		set("long", "һ���������������������\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_stick(35);
	setup();
}
