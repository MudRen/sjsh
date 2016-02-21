
#include <ansi.h>
 
inherit F_DBASE;
inherit SSERVER;
 
void delay_effect(object me, object target, object weapon,int power);
 
int perform(object me, object target)
{
        int delay,skill;
        object weapon=me->query_temp("weapon");
        if (!target) return notify_fail("��˭��\n");
        if (!me->is_fighting(target))
        return notify_fail("���ǲ��ڴ�ܡ�\n");
        if(me->query("family/family_name")!="��������")
        return notify_fail("[��ͻ����ʽ��ֻ�н������˵��Ӳſ���ʹ�ã�\n");
        skill=me->query_skill("lixin-sword",1);        
        if (skill<100) return notify_fail("����Ȼ�������ĵȼ��������޷�ʹ��[��ͻ����ʽ]��\n");
        if( (int)me->query("force") < 600 )      
        return notify_fail("�������������\n");
        if( (int)me->query_temp("ling_delay") )
        return notify_fail("������ʩչ[��ͻ����ʽ]�ˡ�\n");    
        me->add("force", -200);
        delay=3;
        message_vision(WHT"\n$N����ͻȻ�˺�������ǰ΢̤һ��������ǰƽָ������΢���£�������ָ
ƽ���ڽ���֮�ϣ�������Ҳ��ͬ���ʵ����������ƴ�����\n\n"NOR, me);
        me->set_temp("ling_delay", 1);
        me->start_busy(delay);
        me->start_call_out( (: call_other, __FILE__, "delay_effect", me, target,weapon,delay:), delay);
         return 1;
}
 
void delay_effect(object me,object target,object weapon,int power)
{
        mapping action;
        mapping new_act=([]);
	 int extra;    
        me->delete_temp("ling_delay");
        if (!target) return;
        if (environment(me)!=environment(target)) return;
        if (me->query_temp("weapon")!=weapon) return;
        message_vision(WHT"\nֻ��$N����"+weapon->name()+"����һ�������Ľ��⣬�������$n��Ҫ��������\n"NOR,me,target);
        me->set("actions", (: call_other, SKILL_D("lixin-sword"), "query_pfm_action" :) );
	 extra = me->query_skill("sword");
	 me->add_temp("apply/attack", extra);	
	 me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me, target, weapon);
	  me->add_temp("apply/attack", -extra);
	  me->add_temp("apply/damage", -extra);
         me->reset_action();
         target->start_busy(2);
         me->start_busy(1);
}