// qimeigun.c

#include <weapon.h>

inherit STICK;

void create()
{
    set_name("����", ({ "bugun","gun", "bang" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 5);
        set("material", "???");
        set("long", "һ���ò�մˮš�ɵĹ��ӡ�\n");
		set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
		set("unwield_msg", "$N����һ������$n��غ�����\n");
	}
	init_stick(18);
	setup();
}
