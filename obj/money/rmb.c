// thousand.c

inherit MONEY;

void create()
{
        set_name("һ��Ԫ�����", ({"rmb", "rmb_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "rmb");
                set("long", "һ����ֵΪһ��Ԫ�Ĵ��Ž�����ҡ�\n");
                set("unit", "��");
		set("base_value", 100000);
		set("base_unit", "��");
		set("base_weight", 3);
	}
	set_amount(1);
}

