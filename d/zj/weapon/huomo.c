// 火魔枪 by Calvin

#include <ansi.h>
#include <weapon.h>
inherit SPEAR;
void create()
{
           set_name(HIR "火魔枪" NOR, ({"huomo spear", "huomo","qiang","spear"}));
           set_weight(1500);
           if( clonep() )
           set_default_object(__FILE__);
        else {
           set("long","一支全身通红像是刚出炉还为成型的兵器,它是紫静的护身神兵。\n");
           set("unit", "支");
           set("replace_file", "/d/obj/weapon/spear/tieqiang");
           set("value", 10000);
           set("no_sell", 1);
           set("wield_msg", "$N头上一阵红云翻过,手中无意间却多出了一把全身通红的神兵。\n");
           set("unwield_msg", "一阵紫气翻过,$N手中的$n化作一丝红紫相映的烟气消失了。\n");
           set("weapon_prop/strength", 10);
                   }
           init_spear(100);
           set("is_monitored",1);
           setup();
}
