// ����ǹ 
#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE; 
inherit SPEAR;
void create()
{
        set_name(HIY "����ǹ" NOR, ({"longshen spear","longshen", "spear"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","���ǰ�����С����Ƴɵĳ�ǹ��\n");
                set("value", 0);
                set("material", "gold");
                set("wield_msg","$N�ó�һ��$n�������У���ǰ����һ�����⣮\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_spear(10);
        setup();
}
