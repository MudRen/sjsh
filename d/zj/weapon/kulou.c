// ����ǹ by Calvin

#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE; 
inherit SPEAR;
void create()
{
        set_name(HIW "����ǹ" NOR, ({"kulou spear","kulou","qiang", "spear"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ�����С�����Ƴɵĳ�����\n");
                set("value", 10000);
                set("material", "gold");
                set("replace_file", "/d/obj/weapon/spear/tieqiang");
                set("wield_msg","$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_spear(100);
        setup();
}
