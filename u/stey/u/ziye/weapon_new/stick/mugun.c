//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("ľ��", ({"bang"}));
        set_weight(1400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
              set("keenness", 0);
                set("value", 100);
                set("material", "wood");
                set("wield_msg", "$N��������һ�����һ��$n�������С�\n");
        }
        init_stick(15);
        setup();
}

