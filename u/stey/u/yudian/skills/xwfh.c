#include <ansi.h>
inherit SSERVER;
void free(object target);
int perform(object me, object target)
{
       object weapon;
 int ap, ap1, ap2, dp, dp1, dp2, kaee, kkee, ook,ap3,dp3;
       string fer;
       if( !target ) target = offensive_target(me);
       fer = me->query("id");
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("�����˭ʩչ��һ�С�ѩ��ɺ�����\n");
        if(!me->is_fighting())
                return notify_fail("��ѩ��ɺ���ֻ����ս����ʹ�ã�\n");
  //          if((int)me->query("combat_exp") > 500000 );
  //                 return notify_fail("�����ѧ���ߣ��Ѿ��޷��١�ѩ��ɺ����ˡ�\n");
  //          if( (int)me->query_skill("snowsword", 1) > 100);
  //                  return notify_fail("��ķ��ѩ�轣�����ߣ���ѩ��ɺ����Ѿ��޷�ʹ�á�\n");
  //          if( (int)me->query_skill("sword", 1) > 100);
  //                  return notify_fail("��Ļ����������ߣ���ѩ��ɺ����Ѿ��޷�ʹ�á�\n");
       if((int)me->query("max_force") < 600 )
               return notify_fail("���������Ϊ�������޷��߶���ѩ��ɺ�����\n");
       if((int)me->query("force") < 300 )
               return notify_fail("�������������\n");
        if( (int)me->query_skill("snowsword", 1) < 50)
                return notify_fail("��ķ��ѩ�轣����򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("sword", 1) < 50)
                return notify_fail("��Ļ���������򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("force", 1) < 50)
                return notify_fail("��Ļ����ڹ���򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("moonforce", 1) < 50)
                return notify_fail("���Բ���ķ���򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("parry", 1) < 50)
                return notify_fail("��Ĳ���ж����򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("dodge", 1) < 50)
                return notify_fail("��Ļ����Ṧ��򲻵����޷�������ô�������书��\n");
        if( (int)me->query_skill("moondance", 1) < 50)
                return notify_fail("������������跨��򲻵����޷�������ô�������书��\n");
 message_vision( MAG "$N��$n���ĵ�һЦ,$n��ʱ���Ĵ���Ŀ��,��ʱ$N�Ӷ������е�$wֱ��$n��$1��\n\n" NOR,me,target,);
        ook = 1;
       ap = (int)me->query("combat_exp");
       ap1 = (int)me->query_skill("sword");  
       ap2 = (int)me->query_skill("snowsword");
        ap3= (int)me->query("per");
          dp = (int)target->query("combat_exp");
       dp1 = (int)target->query_skill("dodge");
       dp2 = (int)target->query_skill("parry");
        dp3= (int)target->query("per");
  (int)ap = (ap3 + ap1 * ap2) * ap;
  (int)dp = (dp3 + dp1 * dp2) * dp;
       if (random(ap) < random(dp))
       ook = 0;
       if (ook == 1)
{
                me->delete("env/brief_message");
        target->delete("env/brief_message");
  message_vision( HIC "$n���������Դ������ﲻ֪����ʱ��$N�Ѿ���׼ʱ���ݺݵĴ���һ���� \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                message_vision( HIY "$n��Ȼ�����Ĳ�����$N��׼ʱ�����ǺݺݵĴ���һ���� \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                message_vision( HIG "$n�ѻָ�������,��������ȴ��Ȼ��ľ�޷��ƶ���$N�û�����$n�ɿ�Ĵ���һ���� \n" NOR,me,target,);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                me->add("force",-150+random(50));
              me->start_busy(2+random(1));
}
         else {
                message_vision(HIR "$n������$N����,����Ϊ������������ӯ���������һ���㿪����һ����\n" NOR,me,target,);   
                me->add("force",-50+random(50));
              me->delete("env/brief_message");
        target->delete("env/brief_message");
            me->start_busy(2+random(2));
        }
        return 1;
}
