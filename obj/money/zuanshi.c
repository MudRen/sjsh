// zuanshi.c

inherit MONEY;

void create()
{
        set_name("��ʯ", ({"zuanshi", "zuan", "zuanshi_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "zuanshi");
                set("long", "����������ʯ�������Ķ�������\n");
                set("unit", "Щ");
                set("base_value", 500000 );
                set("base_unit", "��");
                set("base_weight", 37);
        }
        set_amount(1);
}
