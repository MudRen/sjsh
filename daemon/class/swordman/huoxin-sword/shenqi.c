
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���������֡�ֻ����ս���в���ʹ�á�\n");
	if( (int)me->query_skill("huoxin-sword", 1) < 60 ) 
		return notify_fail("�����Ȼ������ȼ���������ʹ������һ�У�\n");
        if( (int)me->query("force") < 300 )      
                return notify_fail("�������������\n");


	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ���æ�ˣ�����ûע�⵽��Ľ��С�\n");

	message_vision(HIG"$N�������еĳ������������콣����ֻ�������н�Ӱ����������ʵʵ�������ۻ����ҡ�\n\n"NOR,me);

	me->add("force", -50);

	mypot=(int)me->query_skill("sword");
//	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
//	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIR"$N��Ȼ����Ŀ�ɿڴ�����֪���룬����ֵ���ʲô��ʵ��\n"NOR,target);
		target->start_busy(5);
	}else {
	message_vision(HIR"$N�����������Ϊ����������$n���������˸����ֲ�����\n"NOR,target,me);
            me->start_busy(3);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        me->kill_ob(target);
        }
	return 1;
}
       