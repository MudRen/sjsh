#include <ansi.h>
inherit SSERVER;

  int perform(object me, object target)
  {
          string str;//����rumor�ı���
           object weapon=me->query_temp("weapon");  

          if( !target ) target = offensive_target(me);

          if( !target
          ||      !target->is_character()
          ||      target->is_corpse()
          ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ��"HIY"��"HIR" �P"HIM" ��"HIG" ��"HIC" �� "HIY"��"NOR"��\n");

          if(!me->is_fighting())
                return notify_fail(""HIY"��"HIR"�P"HIM"��"HIG"��"HIC"��"HIY"��"NOR"ֻ����ս����ʹ�ã�\n");

          if((int)me->query("max_force") < 300 )
                  return notify_fail("�������������\n");

          if((int)me->query("force") < 400 )
                  return notify_fail("����������㣡\n");

          if((int)me->query("kee") < 200 )
                  return notify_fail("�����Ѫ���㣬û����ʩ���⹦��\n");

          if((int)me->query_skill("bainiao-jian", 1) < 180)
                  return notify_fail("��İ��񽣷����𻹲�����ʹ����һ�л������ѣ�\n");

          if((int)me->query_skill("ningxie-force", 1) < 150)
                  return notify_fail("��ı�����Ѫ����������ʹ����һ�л������ѣ�\n");

          if(me->query_temp("busy_fengwu")+5>time())
                  return notify_fail("���ۻ�������Ϣһ�°ɡ�\n");

          me->delete("env/brief_message");
          target->delete("env/brief_message");

           message_vision(HIC"$Nһ�����ѵ�ˮ���е�"HIR+weapon->name()+HIC"�緢���Ĺ���$n,\n"NOR+HIW"ֻ��$nû�����ļ��м�����һ������裬����Ŀ�ɿڴ���֪���룡\n\n"NOR,me,target);
          message_vision(HBRED+HIW"$Nʹ����ѩɽ���B�����ľ����P�����,\n"NOR,me,target);

          message_vision(HIW"
                               "HBRED+HIG"������������"NOR"
                               "HBRED+HIG"��   "NOR+BLINK+HIR"�P"NOR+HBRED+HIG"   ��"NOR"
                               "HBRED+HIG"������������\n"NOR,me,target);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

          message_vision(HIW"
                               "HBRED+HIG"������������"NOR"
                               "HBRED+HIG"��   "NOR+BLINK+HIM"��"NOR+HBRED+HIG"   ��"NOR"
                               "HBRED+HIG"������������\n"NOR,me,target);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

          message_vision(HIW"
                               "HBRED+HIG"������������"NOR"
                               "HBRED+HIG"��   "NOR+BLINK+HIG"��"NOR+HBRED+HIG"   ��"NOR"
                               "HBRED+HIG"������������\n"NOR,me,target);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

          message_vision(HIW"
                               "HBRED+HIG"������������"NOR"
                               "HBRED+HIG"��   "NOR+BLINK+HIC"��"NOR+HBRED+HIG"   ��"NOR"
                               "HBRED+HIG"������������\n"NOR,me,target);
          COMBAT_D->do_attack(me, target, me->query_temp("weapon"));


          me->receive_damage("kee", 100);
          me->add("force", -200);
                       if (target->query("eff_kee")<0 || !living(target))  
                          {str=NOR+YEL+target->name()+HIM"��"NOR+HIY+me->name()+HIM"��"HIW"��ѩɽ"HIB"��ѧ"HIY"��"HIR" �P"HIM" ��"HIG" ��"HIC" �� "HIY"��"HIM"��ɱ����!��˵"+target->name()+"Ƥ������������Ŀ!";
                          message("channel:rumor",HIM"������������ĳ�ˣ�"+str+"\n"NOR,users());
                         }
          if( !target->is_fighting(me) ) {
                  if( living(target) ) {
                          if( userp(target) ) target->fight_ob(me);
                          else target->kill_ob(me);
                  }
          }
           target->start_busy(1+random(3));//�O���϶Է���busy
          me->set_temp("busy_fengwu",time());
          return 1;
  }

