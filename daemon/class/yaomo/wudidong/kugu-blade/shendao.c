// shendao.c stey Ѫ������Ѫ�񵶡�

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail(RED"װ��������ʹ�á��ݹǼ�Ѫ�񵶡���\n"NOR);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("���ݹǼ�Ѫ�񵶡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("kugu-blade", 1) < 100 )
        return notify_fail(WHT"��ݹǵ�����������죬ʹ�������ݹǼ�Ѫ�񵶡���\n"NOR);
    if ((int)me->query_skill("huntian-qigong", 1) < 100 )
        return notify_fail(RED"�����������򲻹���ʹ�������ݹǼ�Ѫ�񵶡���\n"NOR);
    if ((int)me->query("max_force") < 600)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);
    if ((int)me->query("force") < 600)
    {
        return notify_fail(HIC"����������������û�ܽ����ݹǼ�Ѫ�񵶡�ʹ�꣡\n"NOR);
    }
    msg = HIC "$N���ֳֵ������һ�գ�һ��Ѫ�齦�����棬�������ұ��ճ���һƬѪ��
��ס��Ӱ��$n��ͷ���䣬\n"NOR;
    if ( random(me->query("combat_exp")) > (int)target->query("combat_exp")/10 )
    {
        damage = random((int)(me->query("sen")/20))+(int)(me->query("sen")/50);
        me->add("force", -300);
        me->receive_wound("kee", me->query("kee")/20);
        me->start_busy(1);
        target->start_busy(random(3));
        target->receive_damage("kee", damage);
        target->receive_wound("kee", damage/2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
msg += HIC"$n��æ������ã���Ѫ��������ֻ����ǰһ��Ѫ�죬����������£���Ѫ��
���������󺿣�\n"NOR;
    } else
    {
        me->start_busy(2);
        me->receive_wound("kee", me->query("kee")/20);
msg += HIY"����$n������ã����Ĳ�æ�������$N��Ѫ����\n"NOR;
        me->add("force", -200);
    }
    message_vision(msg, me, target);
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}
