
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"����������"NOR, ({"langzi jian", "youxia jian",  "langzi sword", "youxia sword", "sword", "jian"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "���������еı�����\n");
                set("orilong", "���������еı�����\n");
                set("value", 10000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��Цһ�����ӱ���γ���$n��\n");
                set("unwield_msg", "$N�����е�$n������У���Ƕ���һ˿Ц�⡣\n");
                set("weapon_prop/int", 1);
                        }
        init_sword(80);
        setup();
}

