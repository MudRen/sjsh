// lifeheal.c

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string target)
{
        int lv;
        lv=me->query_skill("medical",1);
	if( !target )
		return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        
        if(this_player()->is_busy())
           return notify_fail("����æ���أ�����\n");
	
        if( me->is_fighting() || target->is_fighting())
		return notify_fail("ս�����޷��˹����ˣ�\n");
 
        if((int)me->query_skill("medical",1)<200)
		return notify_fail("���ҽ����Ϊ������,���ܸ����������ˡ�\n");

	if( (int)me->query("force") - (int)me->query("max_froce") < 150 )
		return notify_fail("�������������\n");

	if( (int)target->query("eff_kee") < (int)target->query("max_kee") / 5 )
		return notify_fail( target->name() + "�Ѿ����˹��أ����ܲ���������������\n");

	message_vision(
		HIY "$N�������������ڹ�������������$n���ģ������ؽ���������$n����....\n\n"
		"���˲��ã�$N��ͷ��ð������ĺ��飬$n�³�һ����Ѫ����ɫ������������ˡ�\n" NOR,
		me, target );

	target->receive_curing("kee", 10 + lv/3 );
	me->add("force", -150);
	me->set("force_factor", 0);

	return 1;
}
