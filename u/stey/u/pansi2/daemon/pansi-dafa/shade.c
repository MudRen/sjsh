// void_sense.c

#include <ansi.h>

inherit SSERVER;
int cast(object me, object target)
{
	int lvl,i;
	object env, *inv;
	lvl = (int) me->query_skill("spells");
	lvl += (int) me->query("spi");
        if ( lvl <= 120)
                return notify_fail("�㷨�������ߣ�\n");
	if( me->query("mana") < 300 )
		return notify_fail("��ķ���������\n");
        if( me->query("sen") <= 300 )
                return notify_fail("��ľ����㣡\n");
		if (me->query_temp("pansi_shade_busy")) return notify_fail("�����о�õ�̫��Ͳ����ˡ�\n");
	me->add("mana", -100);
	me->receive_damage("sen", 50);
	message_vision(HIW "$N����������һ�Ű�âէ�����ڣ��������Ƽ���Ϩ��ĵ�оһ�������黯������\n" NOR, me);
	        me->set("env/invisibility", 1);
		    me->set_temp("pansi_shade_busy",1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), lvl/10);
		me->start_call_out( (: call_other, __FILE__, "remove_shade", me :), 5+random(lvl/10));
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
//		      me->set_temp("pansi_shade_busy",1);
//        call_out("remove_shade",5+random(lvl/10),me);
//        return 1;
}
void remove_effect(object me)
{
        me->set("env/invisibility", 0);
        tell_object(me, HIB"�����ʶʧЧ�ˡ�\n"NOR);
}
void remove_shade(object me) {
  if (!me) return;
  me->delete_temp("pansi_shade_busy");
}
