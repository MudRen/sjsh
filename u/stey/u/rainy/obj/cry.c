#include <ansi.h>
inherit MONEY;

void create()
{
    set_name(HIW"����"NOR, ({ "gold" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("money_id", "gold");
        set("long", "������ˮ����߻���һ˿�����Ĺ⣬���������ϣ���˿˿�ģ�ԭ����һ���ᡣ\n");
        set("unit", "��");
        set("base_value", 1000000);
        set("base_unit", "��");
                set("base_weight", 3);
        }
        set_amount(1);
}

