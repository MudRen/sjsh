// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("������", ({"guanyin staff", "zhang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�����ɵ��������ʿ����֮�ȣ��������森\n");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg","$N�ó�һ��$n����������,���е��������ʿ�����ơ�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }

        init_staff(125);
        setup();
}

