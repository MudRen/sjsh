// blade.c
//add keenness by ziye 2001/3

#include <weapon.h>

inherit STICK;

void create()
{
        set_name("�޳���", ({"wuchang bang", "bang"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ�Ѿ��ɵĶ̰���һͷ�ǰ�ɫ��һͷ�Ǻ�ɫ��\n");
                set("unit", "��");
		set("material", "steel");
              set("keenness", 0);
		set("wield_msg", "$N��Цһ���������Ѷ���һ��$n��\n");
                set("value", 3000);
        }
        init_stick(40);
        setup();
}
