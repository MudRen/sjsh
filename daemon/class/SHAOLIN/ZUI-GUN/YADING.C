// dading.c 罗汉压顶
//writed by piao 2001 10-04
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「"HIY"罗汉压顶"NOR"」？\n");

        if(!me->is_fighting())
                return notify_fail("「"HIY"罗汉压顶"NOR"」只能在战斗中使用！\n");

        if( (int)me->query_skill("yijinjing", 1) < 100 )
                return notify_fail("你的易筋经神功不够娴熟，无法施展「"HIY"罗汉压顶"NOR"」！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        i=(int)me->query_skill("zui-gun",1)+(int)me->query_kar();

        if( i < 100)
                return notify_fail("你的少林醉棍不够娴熟，无法施展「"HIY"罗汉压顶"NOR"」！\n");

        message_vision(HIY"\n$N现出罗汉真身，高高跳起，幻出一招「罗汉压顶」向$n砸去！\n"NOR,me,target);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(1);
        return 1;
}

