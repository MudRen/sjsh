//   added to adm
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("����æ���أ���Ӧ����ǰ���°ɡ�\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("��ķ��������ˣ�\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("�㾫��̫����Լ��о������䡣\n");

	if( (int)me->query_skill("yuxu-spells", 1) < 60)
		return notify_fail("�㻹ûѧ���ݡ�\n");

	if(environment(me)->query("under_water"))
		return notify_fail("����ˮ�У�û��ʩ�û�ݣ�\n");


	if(!me->is_fighting() )
	{
		message_vision(HIR"$NͻȻ��ʧ��һƬ������ˡ�\n"NOR,me);
		me->add("sen", 50);
		me->add("mana", -100);
		me->move("/d/kunlun/dadian");
		message("vision", HIR+me->name()+"ͻȻ��һƬ�������˳�����\n"NOR,
				  environment(me), me);
		tell_object(me, HIR"�����ӰͻȻ������һƬ���С�\n"NOR);
		return 1; 
	}
        return 1;
}

