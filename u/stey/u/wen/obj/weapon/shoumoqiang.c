//shoumoqiang.c
//weiwei
#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
        set_name("��ħǹ", ({ "shoumoqiang", "spear" }));
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��" CYN "��ħǹ" NOR "����������������������ע������֮����͡�\n");
                set("value",      500000);
                set("material", "blacksteel");
                set("wield_msg","$N������ǹ�������У�ɲʱ�䣬һ��������ǹ�������\n");
                set("unwield_msg", "$N�����е�$nϵ���������ܵ��˶���������һ������\n");
		set("weapon_prop/courage", 4);
        }
        init_spear(100);
        setup();
}

