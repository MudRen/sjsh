// xuan-cloth.c   ����������(Jia sha)
// writed by piao 2001-10-04

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIR"��������"NOR, ({ "jia sha", "cloth" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 50);
        }
        setup();
}

