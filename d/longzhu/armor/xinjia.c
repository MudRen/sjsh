// ��Ҷ�� by Calvin

#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name(HIG"��Ҷ��"NOR, ({"xinye jia","jia", "xinye", "armor"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ҷ����Ҷ����������,�Ǵ�˵����Ҷͯ�ӵı��\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 120);
                set("armor_prop/dodge", 100);
                set("armor_prop/parry", 100);
                set("armor_prop/force", 100);
                set("armor_prop/spells", 100);
        }
        setup();
}
