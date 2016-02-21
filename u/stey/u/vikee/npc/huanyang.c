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
        set_name(HIG "����ҩ��" NOR, ({"wan", "yao"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ������������˵����������֮Ч��\n");
                set("value", 100000);
        }

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


       message_vision(HIR "\n$N����һ������ҩ�裬�о��������˵�ʲô��\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}

