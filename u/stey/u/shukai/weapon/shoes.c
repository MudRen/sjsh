// shoes.c

#include <armor.h>
#include <ansi.h>

inherit BOOTS;


void create()
{
    set_name(HIY "����Ь" NOR, ({ "shoes" }) );
	set_weight(900);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ˫Ь��  \n");
		set("material", "cloth");
		set("unit", "˫");
//		set("value", 300);
        set("armor_prop/armor", 50 );
        set("armor_prop/dodge", 50 );
	}
	setup();
}
//int query_autoload() { return 1; }

