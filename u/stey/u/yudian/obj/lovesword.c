#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
            set_name(HIC"����"HIR"���"NOR"��", ({"love sword", "sword"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ɫ�ĳ������������쳣������\n");
                set("value", 0);
                set("material", "crimsonsteel");
                set("wield_msg",
    "$N��ৡ���һ�����һ��$n�������У����������������������һ����Ҹ�ʱ��.\n");
                set("unwield_msg",
    "$N�����е�$n�������䣬�۽���¶��һ˿��Թ��\n");
          set("weapon_prop/cor", 10);
        }
            init_sword(110);
        setup();
}
