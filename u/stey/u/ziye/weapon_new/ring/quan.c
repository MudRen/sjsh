// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit UNARMED;

void create()
{
        set_name(HIW "��ȭ" NOR, ({"tie quan", "quan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "ֻ");
                set("long",
"ȭʦר�á�\n");
                set("value", 5000);
                set("material", "diamond");
                set("wield_msg",
"$N����һ��$n��\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_unarmed(50);
        setup();
}

