// lingzhi.c ǧ�����
//����(lywin)2000/4/22

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
        set_name(HIR"�������"NOR, ({"pan tao", "tao"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��������ʿ���������������ң���˵��һ�ÿɵ�10����С�\n");
                set("value", 10000);
        }
        setup();
}

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("��Ҫ��ʲô��\n");

        this_player()->add("daoxing", 10000);
        message_vision("$N����һ��������ң�ֻ�����Լ���������һЩ !\n", this_player());
        destruct(this_object());
        return 1;
}


