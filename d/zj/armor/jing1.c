// ���ľ� by Calvin

#include <ansi.h>
#include <armor.h>
inherit NECK;

void create()
{
  set_name(HIM"���ľ�"NOR, ({ "huxin jing", "huxin", "jing" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
    else {
    set("unit", "ֻ");
    set("long","һֻ���ľ���\n");
    set("value", 100000);
    set("no_sell", 1);
    set("material", "gold");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 10);
  }
  setup();
}
