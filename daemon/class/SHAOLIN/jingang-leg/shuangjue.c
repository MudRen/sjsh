// shuangjue.c  ����˫��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("jingang-leg",1);
        
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) || !living(target))
                return notify_fail("��"HIC"����˫��"NOR"��ֻ����ս����ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á�"HIC"����˫��"NOR"����\n");

        if (me->query_skill_mapped("force")!="yijinjing")
                return notify_fail("��"HIC"����˫��"NOR"����������׽����ʹ�á�\n");

        if( (int)me->query_skill("banruo-zhang", 1) < 1 )
                return notify_fail("��"HIC"����˫��"NOR"��������ϰ����Ʋ���ʹ�á�\n");
        
                if( (int)me->query_skill("unarmed", 1) < 120 )
                return notify_fail("��Ļ���������ʵ���޷�ʩչ��"HIC"����˫��"NOR"����\n");
                if( (int)me->query_skill("yijinjing", 1) < 120 )
                 return notify_fail("����׽δ�ɣ�����ʹ�á�"HIC"����˫��"NOR"����\n");

                if( (int)me->query_skill("jingang-leg", 1) < 120 )
                return notify_fail("��Ĵ�������Ȳ�����죬�޷�ʩչ��"HIC"����˫��"NOR"����\n");
        if ((int)me->query("max_force") < 1500)
                return notify_fail("����������㣬�޷�ʩչ����"HIC"����˫��"NOR"����\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("�������������\n");
        if( (int)me->query_str() < 20)
                return notify_fail("����������㣬�޷����ӡ�"HIC"����˫��"NOR"�������ơ�\n");
        if( (int)me->query_con() < 20)
                return notify_fail("��ĸ���Ƿ�ѣ��޷����ӡ�"HIC"����˫��"NOR"�������ơ�\n");

	                 me->add_temp("apply/strength", extra);
                         me->add_temp("apply/attack", extra);

                 msg = HIR "\n$Nһ����Х��ȭ����ʩ��ʹ�����־�ѧ"HIC"������˫����"HIR"Ѹ�����׵ع���$n��\n" NOR;
       	         message_vision(msg, me, target);                
message_vision(HIC"$Nȭ����ʩ����һȭ��\n"NOR,me,target); 
	if (! present(target,environment(me))) return 1;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"$Nȭ����ʩ����һ�ȣ�\n"NOR,me,target); 
        if (! present(target,environment(me))) return 1;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
//--------------------------------------------------------------------

        if( (int)me->query_skill("jingang-leg", 1) > 150 
        && (int)me->query_skill("yijinjing", 1) > 150 ){
message_vision(HIC"$Nȭ����ʩ����һȭ��\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
message_vision(HIC"$Nȭ����ʩ����һ�ȣ�\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        }
//----------------------------------------------------------
        if( (int)me->query_skill("jingang-leg", 1) > 179 
        && (int)me->query_skill("yijinjing", 1) > 179 ){
       message_vision(HIC"$Nȭ����ʩ���м�����һ�ȣ�\n"NOR,me,target); 
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

       }
//-----------------------------------------------------------

        me->add_temp("apply/strength", -extra);
        me->add_temp("apply/attack", -extra);
        me->receive_damage("sen", 100+random(100));
         me->add("force", -500);
        me->start_busy(2+random(1));
        return 1;
}
