//manglong.c
//weiwei
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("ç����", ({ "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����ç������֮������ǧ�أ����˸������\n");
                set("value", 500000);
                set("material", "iron");
                set("wield_msg", "$N�ó�һ��$n�����һ������ʱ������˸��ϼ�����ɡ�\n");
                set("unwield_msg", "$N�������е�$n��ϼ�������$n��\n");
        }
        init_hammer(105);
        setup();
}

