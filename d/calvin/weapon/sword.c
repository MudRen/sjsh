// Īаʥ�� by Calvin

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIW"Īаʥ��"NOR, ({"moxie sword", "moxie","sword"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
               set("no_sell", "��?����,���ֺ����Ķ�������������!\n");
//                 set("no_get", "ʲô,�����? ���Σ�\n");
                set("material", "steel");
                set("long", "�ഫΪĪаר�õı���������͸��,�����ޱȡ�\n");
                set("wield_msg", "һ���Ϲ�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(60);
        setup();
}
