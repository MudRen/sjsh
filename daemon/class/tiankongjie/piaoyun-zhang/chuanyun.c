// lost
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
        if((int)me->query_skill("mtl-force", 1) <100)
                return notify_fail("�����٢���ķ�������������\n");
        extra = me->query_skill("unarmed");
        if ( extra < 200) return notify_fail("���Ʈ���ƻ��������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۴����ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",extra);me->add_temp("apply/damage",extra*2);

        weapon = me->query_temp("weapon");
        msg = HIC  "$N�Ųȶ��֣����ƶ�����˫�ֻ���̧�𣬰���������٢���ľ���\n" NOR;
        msg += HIB "��ʱһ��������$N������ɢ������
$n������ͻȻ�ı�Ļ������ɵ�Ŀ�ɿڴ�����ڵ�����
$N�˻����಻�������������С�\n" NOR;
                  message_vision(msg,me,target);
        message_vision(HIM"\n$N��˫���������������������У�Ծ����С�\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIC"\n$N�������������ڿ����������أ��ֶ���$n���������ơ�\n"NOR,me,target);

        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      message_vision(HIW"\n$N���Ÿ�Ũ�������ӿ���ֱ���������$n���ó�������Ӱѹ��$n��\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIB"\n$N��ӯ������һ�ԣ�Ȼ������Ʈ����������Եø�������ˡ�\n"NOR,me,target);
me->start_busy(4);
me->add("force", -350);
        me->add_temp("apply/attack",-extra);me->add_temp("apply/damage",-extra*2);

        return 1;
}
