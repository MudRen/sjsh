// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("��ľ��", ({"taomu jian", "sword", "jian"}));
	set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

set("long","һ����ľ�Ƴɵĳ�����һ��������д�仭���ģ�\n");
                set("unit", "��");
                set("value", 200);
              set("keenness", 5);
                        set( "material", wood);

        }
        init_sword(15);
        setup();
}

