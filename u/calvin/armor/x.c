#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("��ȵ�", ({"mahuang dao", "dao"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
                set("material", "stone");
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ò���˶��ģ�\n");
                set("unwield_msg", "$N�����е�$n����ʯͷ���ĵ����\n");
        set("weapon_prop/courage", 15);
        }
        init_blade(50);
        setup();
}
