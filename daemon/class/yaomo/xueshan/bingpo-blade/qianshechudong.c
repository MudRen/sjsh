// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_DBASE;

inherit SSERVER;

int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("bingpo-blade",1);
	if ( extra < 150) return notify_fail("��ģ۱��Ǻ����ݻ��������죡\n");
               if(me->query("family/family_name")!="��ѩɽ")
                return notify_fail("��ѩɽ�����á�ǧ�߳�������\n");
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "xiaoyaoyou")
			return notify_fail("��ǧ�߳�������Ҫ����ң�Σݵ���ͣ�\n");
	tmp = me->query_skill("xiaoyaoyou",1);
	if ( tmp < 150 )return notify_fail("��ģ���ң�Σݻ��������죡\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ǧ�߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	message_vision( HIR  "\n\n$N���е�"+weapon->query("name")+"�ó�ǧ�䵶��ʹ�����Ǻ����Ĳ�����ѧ ---ǧ-��-��-��--- ����\n\n\n������̽ͷ��\n$N����"+weapon->query("name")+"ֱ��$n��" NOR,me,target);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIY  "����΢��о��\n$N����"+weapon->query("name")+"б��$n��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIG  "���߷�����\n$N����"+weapon->query("name")+"����$n��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIM  "�������˷���\n$N����"+weapon->query("name")+"����$n��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIC  "���������Σ�\n$N����"+weapon->query("name")+"����$n��" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
          me->start_busy(2);
        me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra);
	return 1;
}
