#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage;
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��"HIR"Ѫɱ"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("xueling-jian", 1) < 70 )
		return notify_fail("���Ѫ�齣��������죬����ʹ�á�"HIR"Ѫɱ"NOR"����\n");;

	if( (int)me->query_skill("heilianforce", 1) < 70 )
		return notify_fail("��ĺ����ķ������ߣ��������������˵С�\n");;

        if( (int)me->query("force", 1) < (int)me->query("max_force")/50)
		return notify_fail("��������������������ʹ�á�"HIR"Ѫɱ"NOR"����\n");

	msg = CYN "$N΢΢һЦ������һ��������ʹ������Ԧ����������$n��\n"NOR;
        if( !target->is_killing(me) ) target->kill_ob(me);
	if (random(me->query_skill("force")) > target->query_skill("force")/5 )
{
                target->start_busy( (int)me->query_skill("xueling-jian") / 30 + 1);

                damage = (int)me->query_skill("sword", 1);
                damage = damage +  (int)me->query_skill("heilian-jian", 1);
		target->receive_damage("kee", damage);
		target->receive_wound("kee", damage/2);
		me->add("force", -damage);
                msg += HIR"ֻ��$N���н������һ����Ѫ���ڿն���ٿ������$n��\n"NOR;
		msg += HIR"$nֻ��һ�ɴ�������ǵذ�ѹ��,��ʱ��ǰһ������������,�۵����һ����Ѫ����\n"NOR;
		me->start_busy(2);
	} else 
{
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->add("force", -(int)me->query("max_force")/50);
		me->start_busy(3);
}
	message_vision(msg, me, target);

	return 1;
}

