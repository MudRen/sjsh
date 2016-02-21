// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("观音杖", ({"guanyin staff", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是由当年观音大士所持之杖，仙气扑面．\n");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg","$N拿出一把$n，握在手中,大有当年观音大士的气势。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_staff(125);
        setup();
}

