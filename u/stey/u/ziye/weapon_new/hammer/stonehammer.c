// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ʯ��", ({"stone hammer","stone", "hammer"}));
        set_weight(5000);
              set("keenness", 0);
              set("material" , iron);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�ѳ��ص�ʯ����\n");
        }
        init_hammer(25);
        setup();
}

