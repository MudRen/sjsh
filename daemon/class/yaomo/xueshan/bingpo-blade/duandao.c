#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���ʯ��١���\n");

        if(!me->is_fighting())
                return notify_fail("����ʯ��١�ֻ����ս����ʹ�ã�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

	if (me->query_skill_mapped("force")!="ningxie-force")
                return notify_fail("��ʯ��ٱ�����ϱ�����Ѫ������ʹ�á�\n");
  if((int)me->query("force") < 500 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("bingpo-blade", 1) < 100)
                return notify_fail("��ı��ǵ����𻹲�����ʹ����һ�л������ѣ�\n");

        me->delete("env/brief_message");
	target->delete("env/brief_message");

message_vision(HIC"\n$N�������ӶԷ������������μ�ת�������������ܲ��������$nһ�����������У�\n"NOR,me,target);

        me->set_temp("QJB_perform", 4);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

 
me->set_temp("QJB_perform", 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

 
me->set_temp("QJB_perform", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

         me->set_temp("QJB_perform", 1);  
        COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 

        me->set_temp("QJB_perform", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("sen", 20);
        me->add("force", -50);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->start_busy(3);
        return 1;
}


