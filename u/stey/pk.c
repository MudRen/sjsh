// huanyang.c ������

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "�ٺ٣����ΰ�! \n");
                set("no_drop","��ô����Ļ���������������! \n");
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "pk��" NOR, ({"pk dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ��pk������˵����������֮Ч��\n");
                set("value", 100000);
        }

        set("is_monitored", 1);
        setup();
}

int do_eat(string arg)
{
        object victim = this_player();

        if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        victim->add("combat_exp", (int)victim->query("combat_exp") / 40);

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();

        if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N����һ��pk����Ӳ�ǴӰ��޳��������ѣ������һ��С����\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}
