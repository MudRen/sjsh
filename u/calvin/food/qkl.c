// xueli.c 巧克力

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("巧克力", ({"qiaokeli", "qkl"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这种巧克力来自未来的中国。\n");
                set("unit", "块");
                set("value", 80);
                set("food_remaining", 4);
                set("food_supply", 30);
        }
}
