#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name( HIW"ˮ��Ь"NOR, ({ "shoes", "boot" }) );
set_weight(1000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "˫");
set("long", "ѩ��ɫ��ˮ��Ь����˵�ǻҹ����������ġ�\n");
set("value", 140);
set("material", "boots");
set("armor_prop/dodge", 200);
}
setup();
}
