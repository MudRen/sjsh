#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
	extra = me->query_skill("doom-sword",1);
           if(me->query("family/family_name")!="��������")
           return notify_fail("������ն��ֻ�н������˵��Ӳſ���ʹ�ã�\n");
	if ( extra < 150) return notify_fail("��ģ�ɱ�˽����ݻ��������죡\n");	
       if(me->query("swordman/wuxiang_perform")!=1)
                return notify_fail("�㻹ûѧ�ᡸ����ն����\n");
        if( (int)me->query("force") < 1000 )      
                return notify_fail("�������������\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ն��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",extra);
//	me->add_temp("apply/damage",extra);
       me->add("force", -300);
	weapon = me->query_temp("weapon");
	message_vision(RED  "\n\n$N�ڿ�Խ�𣬱任���У����е�"+ weapon->name() +"����ɭȻ������һ�С�����ն��һ���ǳ� ����\n\n" NOR, me, target);
        message_vision(HIC  "�����������$N����"+ weapon->name() +"����һ����ֱ��$n��" NOR, me, target);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n��Ⱥħҹ�硹��$N����"+ weapon->name() +"��������Ľ���б��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n���ٹ�ҹ�С���$N����"+ weapon->name() +"��Ҷ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n��ʮ����ħ����$N����"+ weapon->name() +"������ʹ�$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n��Ⱥħ���衹��$N����"+ weapon->name() +"��������Ľ���б��$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIY  "\n��ʮ����롹��$N����"+ weapon->name() +"��Ҷ����$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\n��������ħ����$N����"+ weapon->name() +"������ʹ�$n��" NOR, me, target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(3);
        me->add_temp("apply/attack",-extra);
//      me->add_temp("apply/damage",-extra);
	return 1;
}
