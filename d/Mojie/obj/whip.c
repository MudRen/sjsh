
#include <weapon.h>

inherit WHIP;
#include <ansi.h>
void create()
{
        set_name(HIR"�ֻ��һ��"NOR, ({"shen whip","whip"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "������ħ���ñ���֮һ��\n");
                set("unit", "��");
                set("value", 30000);
        }
        init_whip(100);
        setup();
}

