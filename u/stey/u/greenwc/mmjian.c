#include <weapon.h>
inherit SWORD;
void create()
{
          set_name("郎情妾意剑", ({"mm sword", "sword"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把青色的长剑，看起来异常华丽．\n");
                set("value", 0);
                set("material", "crimsonsteel");
                set("wield_msg",
"$N「唰」地一声抽出一把$n握在手中．\n");
                set("unwield_msg",
"$N将手中的$n插入腰间，嘴角露出一丝坏笑．\n");
        set("weapon_prop/int", 2);
        }
        init_sword(110);
        setup();
}
