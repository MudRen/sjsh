// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(HIY "����ָ��" NOR, ({"doushen zhihuan", "ring"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long",
"ս����������ָ������˵�����ܴ�Ŷ��\n");
                set("value", 0);
                set("material", "diamond");
                set("wield_msg",
"$N����һֻ$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        set("weapon_prop/dodge", 40);
        set("weapon_prop/unarmed", 40);
        }

        init_unarmed(10);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int dam = 0;

    if( (string)me->query("class") == "fighter"
)
    dam = me->query_skill("unarmed");
    dam = (dam+random(dam))/2;

    victim->receive_damage("kee",dam);
    victim->receive_wound("kee",dam/2);
}

