// qimeigun.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
	set_name("��ü��", ({ "qimeigun","gun", "bang" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
		set("material", "wood");
              set("keenness", 0);
		set("long", "һ���ǳ���ʵ����ü����\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_stick(18);
	setup();
}
