// hunyuan.c

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "��Ԫ��" NOR, ({"hunyuan dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ����Ԫ��,��˵�н�θ��Ƣ֮��Ч��\n");
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
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points") );
	victim->skill_death_recover();

   victim->add("daoxing",victim->query("death/dx_loss"));
        victim->save();

	if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision("\n$N����һ����Ԫ��,��ʱ�泩����ࡣ\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}

