// sanshou.c by piao
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
                return notify_fail("��Ҫ��˭ʩչ��һ�С����������֡���\n");

        if(!me->is_fighting())
                return notify_fail("�����������֡�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

	i=(int)me->query_skill("jueqingbian",1)+(int)me->query_kar();

        if( i < 120)
                return notify_fail("��ľ���޷����𻹲�����ʹ����һ�л������ѣ�\n");

        message_vision(HIR"\n����������Ϊ���ֱ������������$N����һ��������޷���Ȼ����鶯�쳣��\n"NOR,me);

	me->delete("env/brief_message");
	target->delete("env/brief_message");

        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

             if( (int)me->query_skill("jueqingbian", 1) > 150 )   {
        me->set_temp("QJB_perform", 17);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->set_temp("QJB_perform", 18);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); }

             if( (int)me->query_skill("jueqingbian", 1) > 180 )   {
        me->set_temp("QJB_perform", 19);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); }

        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3+random(1));
        return 1;
}

