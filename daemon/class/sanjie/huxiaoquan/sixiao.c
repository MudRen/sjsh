// sixiao.c 虎王四啸

#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
	int i,j;

	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「虎王四啸」？\n");
        if(me->query("class") != "sanjie")
                return notify_fail("“虎王四啸”只有三界山门人才可以用！\n");
        if(!me->is_fighting())
                return notify_fail("「虎王四啸」只能在战斗中使用！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("huxiaojian", 1) < 100)
                return notify_fail("你的虎啸皇剑级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("huxiaoquan", 1) < 100)
                return notify_fail("你的虎啸皇拳级别还不够，使用这一招会有困难！\n");

        weapon=me->query_temp("weapon");

	if( me->query("env/brief_message") ){
		i=1;
	} else {
		i=0;
	}
	if( target->query("env/brief_message") ){
		j=1;
	} else {
		j=0;
	}	

	me->delete("env/brief_message");
	target->delete("env/brief_message");

	message_vision(RED"\n$N张口就是一声虎啸，震天动地，使出一招「虎王四啸」。\n"NOR, me);

	message_vision(RED"\n虎王四啸——一啸红尘惊！"NOR, me);
	me->set("SaneJie", 1);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n虎王四啸——再啸湖海翻！"NOR, me);
	me->set("SaneJie", 2);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

	message_vision(RED"\n虎王四啸——三啸鬼神辟！"NOR, me);
	me->set("SaneJie", 3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	message_vision(RED"\n虎王四啸——绝啸穹苍灭！"NOR, me);
	me->set("SaneJie", 4);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->delete("SaneJie");

	if( i ) me->set("env/brief_message", 1);
	if( j ) target->set("env/brief_message", 1);



	me->receive_damage("kee", 100);
	me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
