// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("�л��", ({"zhaohun", "stick"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 300);
              set("keenness", 0);
        }
        init_stick(15);
        setup();
}
