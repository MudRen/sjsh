#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        weapon = me->query_temp("weapon");

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���Է��񡹣�\n");

        if(!me->is_fighting())
                return notify_fail("����Է���ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	i=(int)me->query_skill("wugou-jian",1)+(int)me->query_kar();

        if( i < 200)
                return notify_fail("����⹳�������𻹲�����ʹ����һ�л������ѣ�\n");

      message_vision(HIW"$N����," + weapon->query("name") +
"���ƻ�Ԫ�޼�֮����������"HIR"��Է���"NOR""HIW"������$n \n "NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        COMBAT_D->report_status(target, 0);
        me->receive_damage("sen", 100+random(100));
        me->add("force", -500);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3+random(2));
        return 1;
}

