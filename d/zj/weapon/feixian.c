// ���ɽ� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"���ɽ�"NOR, ({ "feixian sword", "feixian","jian", "sword" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("no_sell", "���������ֵ����,������С���������\n");
                set("material", "steel");
                set("long", "����һ�ѵ��з��ɵľ�ɫ�ý���\n");
                set("wield_msg", "һ���Ϲ�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(100);
        setup();
}
