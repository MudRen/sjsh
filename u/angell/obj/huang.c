#include <armor.h>;
#include <ansi.h>
inherit HANDS;

void create()
{
        set_name(HIW"����ָ��"NOR,({"huan"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long","һ����ɫ��ָ����\n");        
                set("material", "cloth");
                set("armor_prop/armor", 5);

        }
        setup();
}

