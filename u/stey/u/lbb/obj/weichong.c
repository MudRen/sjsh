#include <weapon.h>
inherit SPEAR;
void create()
{
        set_name("΢�ͳ��ǹ", ({"wei chong", "qiang"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��΢�ͳ��ǹ�����ɵ�������ʾ�Ų�һ��Ļ�����\n");
                set("value", 500);
                set("material", "iron");
                set("wield_msg", "$N��������һ��$n������һ��������ǹ˨����׼���㡣\n");
                set("unwield_msg", "$N�����е�$n���ϱ��գ����������\n");
        }
        init_spear(25);
        setup();
}
