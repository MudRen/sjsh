// whip.c

#include <weapon.h>
//  inherit F_UNIQUE;

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIC"��������"NOR, ({"yinsuo jinling", "whip"}));
        set_weight(5000);
if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","һ������ɫ�ĳ�����ϸ������׺���˽��壬����������Ȼ����һ��������\n");
                set("unit", "��");
//	set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 12000);
		set("wield_msg", "$N���������������һ������һ����ɫ�������˦�˳���\n");
		set("unwield_msg", "$N������$n��������\n");
		set("weapon_prop/courage", 20);
		}
        init_whip(150);
        setup();
}

