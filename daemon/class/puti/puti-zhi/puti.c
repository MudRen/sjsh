#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
string msg;
int extra;
object weapon;
if(me->is_busy())
                return notify_fail("������û�գ���\n");
extra = me->query_skill("unarmed");
if (extra = me->query_skill("puti-zhi",1)<100)return notify_fail("�������ָ���������죡\n");
if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
me->add("force_factor",extra/5);
me->set("force",extra/5*10);
me->add_temp("apply/attack",extra/10);
weapon = me->query_temp("weapon");
msg = HIY  "$Nʹ�����ֳ�ȭ�еģ���ԧ��ȭ�ݣ�һ��������ʽ��$n������\n" NOR;
message_vision(msg,me,target);
msg = HIY  "��һȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "��һȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "��һȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "��һȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "ǰһȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "��һȭ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIY  "�����һȭ����" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->start_busy(5);
me->set("force_factor",0);
me->set("force",0);
me->add_temp("apply/attack",-extra/10);
return 1;
}
