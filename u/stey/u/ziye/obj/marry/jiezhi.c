#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW"������"NOR, ({"zhuanjie", "jiezhi"}) );
        set("long", "��ʯ���ɵĽ�ָ�������㰮����������\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else { 
                set("armor_type", TYPE_FINGER);
                set("unit", "ֻ");
                set("armor_prop/per", 20);
                set("value", 0);

        }
        setup();
}

