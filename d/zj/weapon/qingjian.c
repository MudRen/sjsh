// �ལ by Calvin

#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
        set_name(HIG"�ལ"NOR, ({"qing sword", "sword"}));
        set_weight(14000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ�����������ı�����\n");
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_put", 1);
                set("no_break", 1);
                set("value", 30000);
                set("replace_file", "/d/obj/weapon/sword/qingfeng");
                set("material", "crimsonsteel");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У�\n");
                set("unwield_msg", "$N�����е�$n�������䡣\n");
            set("weapon_prop/int", 2);
        }
        init_sword(100);
        set("is_monitored",1);
        setup();
}
