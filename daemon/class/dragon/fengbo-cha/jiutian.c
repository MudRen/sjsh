// writted by leox
// 2001/7

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{       
        string msg="";
        int damage,wound;
        object weapon=me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����Х���졹��\n");

        if(!me->is_fighting())
                return notify_fail("����Х���졹ֻ����ս����ʹ�ã�\n");
        
        if(me->query("family/family_name")!="��������")
                return notify_fail("�������ʹ��������Х���졹��\n");
                
        if (me->query_skill_mapped("force")!="dragonforce")
                return notify_fail("����Х���졹�����������ķ�Ϊ���ӣ�\n");
                
        if((int)me->query("max_force") < 500 )
                return notify_fail("�������������\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 300 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("dragonforce", 1) < 120)
                return notify_fail("��������ķ���Ϊ��������ʹ����һ�л������ѣ�\n");
        if((int)me->query_skill("fengbo-cha", 1) < 120)
                return notify_fail("��ķ粨ʮ������Ϊ��������ʹ����һ�л������ѣ�\n");
        message_vision(HIY"$N�������������צ�������ڿն���ʹ������Х���졹���У���$n��������������\n"NOR,me,target);
//        me->set("ciguangpudu", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 8);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
//        me->set("ciguangpudu", 9);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
         COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        me->delete("longxiaojiutian");
        me->start_busy(3+random(2));
        message_vision(HIW"$N���쳤��,����Х���졹������ϣ��������ջص���.\n"NOR,me,target);
        message_vision(msg,me,target);
        me->add("kee", -100);
        me->add("force", -250);
        me->add("sen",-100);
        return 1;
}
