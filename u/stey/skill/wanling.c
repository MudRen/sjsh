#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int kee_wound;
	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�����ħ������\n");

        if(!me->is_fighting())
                return notify_fail("������ħ����ֻ����ս����ʹ�ã�\n");

        if((int)me->query("force") < 500 )
                return notify_fail("�������������\n");
	if(me->query("family/family_name")!="��˿��")
                return notify_fail("�������˼䡱ֻ����˿�����˲ſ����ã�\n");
        if((int)me->query("kee") < 300 )
                return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

        if((int)me->query_skill("yinsuo-jinling", 1) < 150)
                return notify_fail("����������弶�𻹲�����ʹ����һ�л������ѣ�\n");
        if (me->query_skill_mapped("whip") != "yinsuo-jinling")
        return notify_fail("�������޷�ʹ�á�����ħ������������\n");
	if(random((int)me->qurey("PKS")) >5 )
	 return notify_fail("�����а��֮�����������������������\n");
	 if(random(60) > (int)me->query("kar"))
	 return notify_fail("���������岻�����ʹ���ˡ�\n");	 
	me->delete("env/brief_message");

	message_vision(HIC"\n$N���㾫�����������˴�С���죬ͻȻ��Цһ����"HIR"����ħ��"NOR+HIC"������ʱ�����ذ��������������ض���ҡ��\n"NOR, me);


//	me->set_temp("yinsuojinling_per", 8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

//	me->delete_temp("yinsuojinling_per");
        
        kee_wound = me->query("eff_kee")/(2+random(5));
	me->receive_damage("kee", 50);
	target->add("kee", -kee_wound);	
	target->add("eff_kee", -(kee_wound));
	me->add("force", -100);
	message_vision(HIW"$n������������ħ�������񲻶��������帩���ˣ������ڵء�\n"NOR,me, target);
	target->start_busy(3);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
