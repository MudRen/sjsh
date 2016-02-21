// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit WAIST;

void create()
{
	set_name(HIW"��ѩ���ƴ�"NOR , ({ "icy girth", "girth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 7000);
		set("material", "cloth");
		set("armor_prop/armor", 5);
		set("armor_prop/dodge", 5);
	}
	setup();
}
