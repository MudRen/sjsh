
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int extra;
         if( !target ) target = offensive_target(me);
         if( !target
          || !me->is_fighting()
        || !me->is_fighting(target)  )
                return notify_fail("���ʵ��׷ɡ�ֻ����ս����ʹ�á�\n");

       if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "needle" )
                return notify_fail("ʹ�á��ʵ��׷ɡ������ø��룡\n"); 

        if( (int)me->query("force") < 250 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("tianyi-zhen",1) < 60 )
                return notify_fail("�����һ�뷨�ȼ�����.\n");


        msg = HIY "$Nʹ����ԯ��Ĺ�ľ������ʵ��׷ɡ�������ʱ���ʮ����ӯ��\n" NOR;

        message_vision(msg, me);

        extra=me->query_skill("tianyi-zhen",1)*3/4;

        me->add_temp("apply/attack",extra);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       
        me->add_temp("apply/attack",-extra);
        
        me->add("force", -100);
        me->start_busy(2);

        if(!ob->is_fighting(me)) ob->fight_ob(me);
        return 1;
}
