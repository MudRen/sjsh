// pao.c

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("���깬��", ({ "jin pao","pao","gongpao" }) );
set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "��");
                set("value", 500);
set("armor_prop/armor", 1);

        }
        setup();
}
