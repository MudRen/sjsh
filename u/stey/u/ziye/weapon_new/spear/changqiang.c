// changqiang.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SPEAR;

void create()
{
	set_name("��ǹ", ({ "chang qiang","qiang","changqiang" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 1000);
		set("material", "wood");
              set("keenness", 10);
		set("long", "һ�˳�ǹ��\n");
		set("wield_msg", "$N����һ��$n��˳�ֶ��˸�ǹ����\n");
	//	set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_spear(30);
	setup();
}
