// thousand.c

#include <ansi.h>
inherit MONEY;

void create()
{
    set_name(HIY"���Ԫ��"NOR, ({ "gold", "big gold" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("money_id", "biggold");
        set("long", "һ����������Ĵ�Ԫ����\n");
        set("unit", "��");
        set("base_value", 1000000);
        set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

