// feitian-jian.c  ���콣
// Modified by Cody March.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
            return notify_fail("��Ҫ��˭ʩչ��һ�С��������ǡ�?\n");
	if(me->query("family/family_name")!="��ѩɽ")
         return notify_fail("����һ��������ô���ñ��˵Ĺ����أ�����\n");

        if( !me->is_fighting() )
        return notify_fail("���������ǡ�ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
             || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("bingpo-blade", 1) < 150)
                 return notify_fail("��ı��ǵ����ȼ�����150����ô��ʹ�����������ǡ���\n");

      if( (int)me->query("combat_exp",1) < 250000 )
          return notify_fail("��ľ��鲻�㣬����ʹ�����������ǡ���\n");

        if (me->query("force") < 300)
               return notify_fail("���������̣�����ʹ�����������ǡ���\n");



     msg = HIG "$Nʹ�����Ǻ����ľ������������ǡ�������ַ�����ǿ��Ĺ�����\n\n" NOR;
        message_vision(msg, me);

        me->clean_up_enemy();
        ob = me->select_opponent();

        message_vision(HIW"ֻ��һ������ֱ����$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
       message_vision(HIW"һ���������$n���϶���һ��������˿ڡ�"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

         message_vision(HIW"ֻ������һ����һ�ѷ����ı���ָ��$n���ʺ�"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

         message_vision(HIW"$n��Ȼ����˵��棬ȴ�����ϵĺ������ˣ�����һƬ�Ϻ졣"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N��һ����������������������ı�������ͷ�����Ŀ���$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N˵��������һ��$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

 message_vision(HIW"$N˵�������������л�Ҫ���Ҷ�������������"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        
me->add("force", -100);
        me->start_busy(3);
target->start_busy(4);

target->reisve_damage(50);
target->reisve_wounder(10);


        return 1;  

}
