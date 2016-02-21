// lingzhi.c 千年朱果
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIR"糖葫芦"NOR, ({"tang hulu", "hulu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "棵");
                set("long", "这是一个武林人士梦寐以求的糖葫芦，据说吃一棵可得2000武学。\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        this_player()->add("combat_exp", 2000);
        message_vision("$N吃下一个糖葫芦，只觉得自己变利害了一些 !\n", this_player());
        destruct(this_object());
        return 1;
}


