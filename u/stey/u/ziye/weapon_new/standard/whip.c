// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("Ƥ��", ({"pi bian", "pibian", "bian", "whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ��������Ƥ�ޣ�\n");
                set("unit", "��");
              set("keenness", 0);
                set("value", 500);
        }
        init_whip(15);
        setup();
}

