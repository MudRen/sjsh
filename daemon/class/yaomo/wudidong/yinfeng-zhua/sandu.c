// sandu.c ����צɢ�� edited by peaceful

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;

	if( !target ) target = offensive_target(me);

	if( !(int)me->query_condition("poison_sandu"))
		return notify_fail("������û����ɢ��\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

	if( !userp(target) || wizardp(target) )
		return notify_fail("ɢ��ֻ�ܶ����ʹ�á�\n");

	if( (int)target->query("combat_exp") < (int)me->query("combat_exp")/2 )
		return notify_fail("������ɢ����û�õġ�\n");

	if( (int)me->query_skill("huntian-qigong", 1) < 180 )
		return notify_fail("��Ļ��������󷨲�����죬����ɢ����\n");

	if( (int)me->query_skill("yinfeng-zhua", 1) < 180 )
		return notify_fail("�������צ������죬����ɢ����\n");

	msg = GRN "ֻ����$N�Ĺǽڸ�����죬$N�����͵س��˰�ߣ���Ȼһ��ץס$n��
�󣬽������������ģ�ԴԴ���ϴ���$n���ڡ�\n";

	me->start_busy(1);
	if( random( (int)me->query_skill("yinfeng-zhua",1))
          > random(target->query_skill("dodge") ) ) {
		msg += CYN " ���$p����������$P�ı�����������ɢ��$n���ڣ�\n" NOR;
            target->receive_damage("kee",200);
            target->receive_wound("kee",100 + random(80));
            target->apply_condition("poison_sandu", 1000);
            me->clear_condition();
            target->start_busy(random(2));
	} else {
		msg += "����$p������������һ�𣬽�$N�������˿�ȥ��\n" NOR;
		me->start_busy(3);
	}
	message_vision(msg, me, target);
	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}
