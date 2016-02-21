#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
        string msg;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("���ֹ⻯Ӱ��ֻ����ս����ʹ�á�\n");
        if( (int)me->query_skill("mindsword", 1) < 60 ||
           (int)me->query_skill("zixia-shengong", 1) < 100 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á��ֹ⻯Ӱ����\n");
                if(me->query("family/family_name") != "��ɽ����" )
                return notify_fail("�����Ķ�͵ѧ�����书��\n");
        if( (int)me->query("max_force") < 600 )
                return notify_fail("���������Ϊ̫��������ʹ�á��ֹ⻯Ӱ����\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
        message_vision(HIW"\n$N�����񣬿��������\n",me,target);
        message_vision(HIW"\n�����񣬽���ף�����⣬ͬ�䳾��\n",me,target);
       msg = HIW "\n     $Nһ��бб������\n\n" NOR;
            me->start_busy(1);
            target->start_busy(1);
if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))
        {
                if(me->query_skill("mindsword", 1) > 299)
                   call_out("perform5", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 239)
                   call_out("perform4", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 179)
                   call_out("perform3", 1, me, target);    
                  else  if(me->query_skill("mindsword", 1) > 119)
                   call_out("perform2", 1, me, target);    
                else
                   call_out("perform1", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -100);                
                msg += HIY"����$pʶ����թ���������һ�С�\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
int perform1(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!me->is_fighting(target)) 
          return notify_fail("ս���Ѿ������ˡ�\n");
        msg = HIY "\n$p�ۼ�$N¶����������æ��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "˭֪$N����ȴ�����У�$p����ʱΪʱ������һ�����У�����һ��������˿ڡ�\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p�ۼ�$N¶����������æ��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "˭֪$N����ȴ�����У�$p����ʱΪʱ������һ�����У�����һ��������˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һ���������н�������$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "ֻ��$p�������õ�����˳�������\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("zixia-shengong", 1);
                damage = random(damage)+damage/2;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform3(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p�ۼ�$N¶����������æ��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "˭֪$N����ȴ�����У�$p����ʱΪʱ������һ�����У�����һ��������˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һ���������н�������$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "ֻ��$p�������õ�����˳�������\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һת���н���һ����$p��ն��������$p���ϸ��һ����ɼ��ǵ��˿ڡ�\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p�ۼ�$N¶����������æ��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "˭֪$N����ȴ�����У�$p����ʱΪʱ������һ�����У�����һ��������˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һ���������н�������$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "ֻ��$p�������õ�����˳�������\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һת���н���һ����$p��ն��������$p���ϸ��һ����ɼ��ǵ��˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "�ô�������$N��ǰԾ��������$p�ͻ�һ�ƣ����$p������\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("unarmed");
                damage = random(damage)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -400);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
int perform5(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        msg = HIY "\n$p�ۼ�$N¶����������æ��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "˭֪$N����ȴ�����У�$p����ʱΪʱ������һ�����У�����һ��������˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һ���������н�������$p\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "ֻ��$p�������õ�����˳�������\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N˳��һת���н���һ����$p��ն��������$p���ϸ��һ����ɼ��ǵ��˿ڡ�\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "�ô�������$N��ǰԾ��������$p�ͻ�һ�ƣ����$p������\n" NOR;
        message_vision(msg, me, target); 
        msg = HIC "$N����һƬ��������Ȼ�ͽ�һ����$p��ȥ��$p��һ�����Ķ����������ǻ���ˡ�\n\n" NOR;
                me->start_busy(3);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("unarmed");
                damage = damage+(int)me->query_skill("spells");
                damage = random(damage*2)+damage;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -600);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
