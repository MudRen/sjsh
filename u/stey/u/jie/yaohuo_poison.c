// snake_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
	object where=environment(this_player());
	me->receive_wound("kee", 20+random(10));
	me->receive_wound("sen", 20+random(10));
	me->set_temp("death_msg","�𶾷������ˡ�\n");
	me->apply_condition("yaohuo_poison", duration - 1);
	tell_object(me, HIG "��Ȼһ��ѣ�Σ�������һƬ�հף�\n" NOR );
         message("vision", me->name() + "ͻȻ������ҵĶ�������������Ҫ�赹��\n",environment(me), me);       
	if( duration < 1 ) return 0;
	return 1;
}
