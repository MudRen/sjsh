
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
       if(me->query("family/family_name")!="��������")
       return notify_fail("����������ֻ�н������˵��Ӳſ���ʹ�ã�\n");
	if( (int)me->query_skill("feitian-sword", 1) < 120 ) 
	return notify_fail("��ķ����������ȼ���������ʹ������������\n");
       if( (int)me->query("force") < 600 )      
       return notify_fail("�������������\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("sword");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
       me->add("force", -100);
	message_vision(HIG  "\n$NͻȻ����Ծ���������������죬���е�"+ weapon->name() +"Ю�������֮�ƣ������Ĵ���$n��\n" NOR,me,target);
             
        if(me->query("swordman/jiulong_perform",1) != 100000)
        {
        me->add("swordman/longxiang_perform",1);
        tell_object(me,HIY"������Լ��Է������������������ˡ�\n"NOR);
        }
        if(me->query("swordman/longxiang_perform",1) > 300)
        {
        me->set("swordman/jiulong_perform",1);
        tell_object(me,HIY"���ڲ�֪�����������ˡ���ͷ��������Ҫ�졣\n"NOR);
        me->delete("swordman/longxiang_perform");
        }

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
          me->start_busy(1);
	return 1;
}
