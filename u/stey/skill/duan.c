//duan.c -������ǹ֮������ǹ��
// Modified by stey 2001
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ǹ����\n");
    if( (int)me->query_skill("huoyun-qiang",1) < 70)
    return notify_fail("��Ŀǰ������ʹ����������ǹ����\n");
    if( (int)me->query("force") < 200 )
    return notify_fail("�������������\n");
    me->add("force", -60);
msg = HIC"$NͻȻ����һ���������о�ǹб���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб�±���$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;
    me->start_busy(1);

    if( random(me->query("combat_exp")) >
      (int)target->query("combat_exp")/4 ) {
    target->start_busy( (int)me->query_skill("huoyun-qiang") / 20 );
    damage = (int)me->query_skill("huoyun-qiang", 1)+(int)me->query_skill("spear", 1
)/2;
    damage = damage/2 + random(damage);

    target->receive_damage("kee", damage);
    target->receive_wound("kee", damage/2);
   msg += RED
"ֻ��$n��$Nһǹ���У���ǰ�ѿ�һ��������˿ڣ�Ѫ��������������\n"NOR;
    } else {
    msg += HIC "����$p��æ����㿪��$P����û�еóѡ�\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}

