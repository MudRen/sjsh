#include <weapon.h>

inherit STICK;


void create()
{
        set_name("����", ({"shehun bang", "bang"}));
        set_weight(21000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", "һ�Ѱ���İ��ӣ���ʱ����˿˿������\n");
                set("value", 500000);
                set("material", "steel");
                set("wield_msg", "$N��������һ�����һ��$n�������У�һ�ɹ����鲼��Ұ��\n");
				set("replace_file", "/d/obj/weapon/stick/qimeigun");
        }
        init_stick(120);
        setup();
}

