#include <armor.h>
inherit ARMOR;
void create()
{
        set_name("У���Ʒ�", ({"junfu", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��ո�µ�У�ټ����Ʒ������ϵ����������ܿ�������һλ��У��\n");
                set("material", "steel");
                set("value", 10000);
                set("armor_prop/armor", 600);
                set("armor_prop/dodge", -5);
        }
        setup();
}

