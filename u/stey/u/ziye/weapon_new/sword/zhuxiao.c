//Cracked by Roath
// created by ajax on 7/8/1999

#include <weapon.h>


inherit SWORD;

void create()
{
    set_name("����", ({ "zhu xiao","xiao","zhuxiao"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "wood");
        set("long", "�����ӵ��Ͻ�����ˣ�ֻ����������������һ����\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("value", 0);
                set("wield_msg", "$N����һ��$n���ڴ�������һ����\n");
                set("unwield_msg", "$NЦ��һЦ����$n������䡣\n");
                set("weapon_prop/int", 1);
                set("music/type", "xiao");
	}
    init_sword(5);
	setup();
}
