#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
if (extra = me->query_skill("xuanhu-blade",1)<100) return notify_fail("�����������������������죡\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("�۶̸賤�Σ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
weapon = me->query_temp("weapon");
message_vision(HIY  "\n$Nʹ��������������һ��----������������е�"+ weapon->name()+  "�������$n������һ����" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(HIC"\n$N�ڶ��С��������ʳ��"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N�����С����������"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
me->start_busy(3);
return 1;
}
