// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(RED "ڤ��צ" NOR, ({"mingwang zhua", "zhua"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long",
"��˵���ֱ�������ǿ������Ĺ���������֪�������Ǽ١�\n");
                set("value", 0);
                set("material", "diamond");
                set("wield_msg",
"$N����һֻ$n����Χ���˵�ʱ����������\n");
                set("unwield_msg", "$N�������е�$n�����˿�����\n");
        }

        init_unarmed(50);
        setup();
}
mixed hit_ob(object me, object victim)
{
    int dam = 0;

    if( (string)me->query("family/family_name") == "���޵ظ�"
                && me->query_skill("jinghun-zhang",1) > 1)
    dam = me->query_skill("unarmed");
    dam = (dam+random(dam))/2;

    victim->receive_damage("kee",dam);
    victim->receive_wound("kee",dam/2);
    return HIR"��ͷ��ץ��ĸо���ˬ��\n" NOR;
}

