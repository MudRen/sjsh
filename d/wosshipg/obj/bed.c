#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIC"寒玉床"NOR, ({ "bed" }) );
set_weight(500000);
set("unit", "张");
set("long", "一张用万年寒冰制成的床，周边还有栩栩如生的龙凤雕花。\n");
set("value", 0);
setup();
}
