// xihuo.c Ϣ��

#include <ansi.h>

int exert(object me, object target)
{

	if ( !target
      ||      !userp(target)
      ||      target->is_corpse()
      ||      target==me)
		return notify_fail("������˭�������\n");
	if (!target->query_condition("yaohuo_poison"))
        return notify_fail("û������Ϲ����ʲô��\n");
	if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");

	if( (int)me->query("force") - (int)me->query("max_force") <  600 )
		return notify_fail("�������������\n");

    if ((int)me->query_skill("huomoforce",1)<80)
		return notify_fail("����ڹ���Ϊ���������˽������\n");
	
	message_vision(
		HIY "$N�����񹦣���$n�����ʹ��һ�ġ�\n\n"NOR,
		me, target );
    if (random(me->query_skill("huomoforce", 1)-60)>10){
		target->apply_condition("yaohuo_poison",0);
		message_vision(
		HIY "$N��ָ���㣬$n�ſڿ����һ̲��Ѫ��\n"NOR,
		me, target );
			}
	else {
		message_vision(
		HIY "$NͻȻ��ɫ�԰ף��ƺ�������֧����Ż��һ��Ѫ������\n"NOR,
		 me, target );
	}	
 
	target->receive_cuiring("kee", 10 + (int)me->query_skill("force")/3 );
	me->add("force", -150);
	me->set("force_factor", 0);
	return 1;
}
