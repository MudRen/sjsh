#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
extra = me->query_skill("deisword",1);
if( !target ) target = offensive_target(me);
if( !target
||      !target->is_character()
||      !me->is_fighting(target) )
       return notify_fail("�۲ʵ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
weapon = me->query_temp("weapon");
message_vision(HIC  "\n$Nʹ����ɽ�Ľ��еĵ�һ��---�ʵ�����\n\n"+ "һ���������������е�"+ weapon->name()+  "�������$n������һ����" NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N�ڶ���---�ɵ��˻�!"NOR,me,target);
if (extra = me->query_skill("mindsword",1)<100) return notify_fail("��ĵ������������������죡\n");
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg
);
message_vision(HIC"\n$N������---Ⱥ������"NOR,me,target);
COMBAT_D->do_attack(me,target, me->query_temp("weapon"+10),TYPE_REGULAR,msg
);
me->start_busy(2);
return 1;
}
