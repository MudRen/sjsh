#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
if (extra = me->query_skill("kusang-bang",1)<100) return notify_fail("�����Ŀ�ɥ�������������죡\n");
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
return notify_fail("��׷����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
weapon = me->query_temp("weapon");
message_vision(HIY  "\n$Nʹ����ɥ��������һ��----С���꣬���е�"+ weapon->name()+  "�������$n������һ����" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
message_vision(HIC"\n$N�ڶ��С�������������"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N�����С�������ŭ�⣡"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
 me->start_busy(1);
return 1;
}
