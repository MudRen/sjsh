// ��������

#include <weapon.h>
#include <ansi.h>

inherit WHIP;
inherit F_UNIQUE;

void create()
{
        set_name(HIC"����"HIY"����"NOR, ({"yinsuo jinling", "whip"}));
        set_weight(5000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","һ������ɫ�ĳ�����ϸ������׺���˽��壬����������Ȼ����һ��������\n");
                set("unit", "��");
		set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 20000);
                set("wield_msg", HIY"$N���������������һ������һ����ɫ�������˦�˳�����\n"NOR);
		set("unwield_msg", HIY"$N������$n��������\n"NOR);
		set("weapon_prop/courage", 20);
		}
        init_whip(150);
        setup();
}

mixed hit_ob(object me, object victim)
{
    int damage_bonus = 0;
    
    if( (string)me->query("family/family_name") == "��˿��"
    		&& me->query_skill("yinsuo-jinling",1) > 1)
    damage_bonus = me->query_skill("yinsuo-jinling",1);
    damage_bonus = (damage_bonus+random(damage_bonus))/2;

    victim->receive_wound("kee",damage_bonus);
    return HIC"����"+HIY"����"+HIW"��ϼ��ӳ�䣡\n" NOR;

}
