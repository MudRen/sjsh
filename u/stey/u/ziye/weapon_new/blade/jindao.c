#include <weapon.h>
//add keenness by ziye 2001/3

inherit BLADE;

void create()
{
        set_name("��", ({"jin dao", "dao"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�ѽ��������Բͷ��������������Ƕ�а���\n");
                set("value", 2500);
                set("material", "purplegold");
                            set("keenness", 30);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������У����������\n");
                set("unwield_msg", "$N�����е�$n�����ɫ���ʡ�\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(50);
        setup();
}

