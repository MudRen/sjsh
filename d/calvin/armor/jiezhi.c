// yinyangring.c ������ָ

#include <armor.h>

inherit FINGER;

void create()
{
        set_name("������ָ", ({ "yinyang jiezhi", "jiezhi", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("value", 0);
                set("material", "gold");
                set("armor_prop/armor", 35);
        }
        setup();
}       
