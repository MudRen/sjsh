// drift_sense.c

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        if( me->query("mana") < 200 )
                return notify_fail("��ķ���������\n");
        if( me->query("sen") < 100 )
                return notify_fail("��ľ���̫�\n");
	if( me->is_ghost())
		return notify_fail("����޷�ʹ���¹ⱦ�ϣ�\n"); 	
	if( target )
		return notify_fail("�¹ⱦ��ֻ�ܶ��Լ�ʹ�ã�\n");
	write("��Ҫ�ƶ�����һ������ߣ�");
	input_to( (: call_other, __FILE__, "select_target", me :));
	return 1;
}

void select_target(object me, string name)
{
	object ob;

	if( !name || name=="" ) {
		write("��ֹʩ����\n");
		return;
	}

	ob = find_player(name);
	if( !ob || !me->visible(ob) || wizardp(ob) )
		ob = find_living(name);
	if( !ob || !me->visible(ob) || wizardp(ob) || !environment(ob)) {
		write("���޷����ܵ�����˵����� ....\n");
		write("��Ҫ�ƶ�����һ������ߣ�");
		input_to( (: call_other, __FILE__, "select_target", me :));
		return;
	}
//	if( me->is_fighting() ) {
//		write("ս�����޷�ʹ����ʶ��ͨ��\n");
//		return;
//	} else 
	if( me->query("mana") < 200 ) {
		write("��ķ���������\n");
		return;
	}

	me->add("mana", -100);
	me->receive_damage("sen", 30);
	
	message_vision( HIW "$N��ͷ��Ŀ�����в�������:���������� ....\n" NOR, me);
	if( random(ob->query("sen")) < (int)me->query("sen") / 10 ) {
		write("����ܵ��Է������������ǲ���ǿ�ҡ�\n");
		return;
	}
	   if( random(50) > 
	(int)(me->query_skill("pansi-dafa",1))){
                write("����Ϊ����������ʧ���ˡ�\n");
                return;
	if( random(me->query_skill("spells")) < (int)ob->query("mana") / 500 ) {
		write("����Ϊ����������ʧ���ˡ�\n");
		return;
	}
        }
	message( "vision", HIW "\nһ��ҫ�۵Ĺ�â��Ȼ��ס" + me->name() 
		+ "���������ᣬ��â����һ����ʧ����Ӱ���٣�\n\n", environment(me), ({ me }) );
	me->move(environment(ob));
	message( "vision", HIY "\n�����ǰͻȻ����һ��ҫ�۵Ĺ�â����â�и��ֳ�һ����Ӱ��\n\n" NOR,
		environment(ob), ({ me }) );
	me->start_busy(2+random(2));
}

