//add keenness by ziye 2001/3

#include <weapon.h>

inherit MACE;

void create()
{
        set_name("��ڱ�", ({"bamboo mace", "mace"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500);
              set("keenness", 0);
                set("material", "wood");
        }

        init_mace(15);
        setup();
}

