
#include <weapon.h>
#include <ansi.h>
//   inherit SWORD;
inherit "/d/xueshan/obj/anqi-jian.c";

void create()
{
        set_name(HIW"����������"NOR, ({"changsheng sword", "sword", "changsheng", "jian"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "������ħ���ñ���֮һ��\n");
                set("orilong", "������ħ���ñ���֮һ��\n");
                set("value", 30000);
                set("material", "crimsonsteel");
                set("wield_msg", "$N��Цһ�����ӱ���γ���$n��\n");
                set("unwield_msg", "$N�����е�$n������У���Ƕ���һ˿Ц�⡣\n");
                set("weapon_prop/int", 1);
                set("anqi/max", 60);
                set("anqi/now", 0);

        }
        init_sword(130);
        setup();
}

