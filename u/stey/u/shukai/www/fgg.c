#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
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
        msg = HIC "\n $N�����񣬿��������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n        ������\n" NOR;
if (random(me->query("combat_exp")) > random((target->query("combat_exp")/3)))
        {
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);               
                me->add("force", -100);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 119)
                   call_out("perform2", 1, me, target);    
        } else 
        {       me->start_busy(3);
                me->add("force", -100);                
                msg += HIY"����$p�͵�һԾ���㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
int perform2(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!me->is_fighting(target)) 
          return notify_fail("ս���Ѿ������ˡ�\n");
        if( (int)me->query("force") < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        msg = HIY "\n�����ţ�$N���������\n" NOR;
        message_vision(msg, me, target); 
       msg = CYN "\n       ����ס�\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("zixia-shengong", 1);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -200);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 179)
                   call_out("perform3", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform3(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!me->is_fighting(target)) 
          return notify_fail("ս���Ѿ������ˡ�\n");
        if( (int)me->query("force") < 400 )
                return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     
        msg = HIY "\n�����ţ�$N���������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n       ����⡣\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force", 1);
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -300);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 239)
                   call_out("perform4", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform4(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!me->is_fighting(target)) 
          return notify_fail("ս���Ѿ������ˡ�\n");
        if( (int)me->query("force") < 500 )
                return notify_fail("���Ҫ�ٳ����Ļ���ȴ�����Լ������������ˣ�\n");     
        msg = HIY "\n�����ţ�$N���������\n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "\n       ͬ�䳾��\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -400);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
                if(me->query_skill("mindsword", 1) > 299)
                   call_out("perform5", 1, me, target);    
        message_vision(msg, me, target);
        return 1;
}
int perform5(object me, object target)
{
  int damage, p,skill;
        string msg,weapon;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if(!me->is_fighting(target)) 
          return notify_fail("ս���Ѿ������ˡ�\n");
        if( (int)me->query("force") < 1000 )
                return notify_fail("���Ҫ�ٳ���ɱһ����ȴ�����Լ������������ˣ�\n");     
        msg = HIY "\n$Nʩչ��ֹ⻯Ӱ����������δ����\n" NOR;
        message_vision(msg, me, target); 
       msg = HIW "\n   $N��Ȼ�����ʲô�������ĺϣ����뽣�ϣ���������$n��ȥ��\n" NOR;
                me->start_busy(1);
                target->start_busy(1);
                damage = (int)me->query_skill("sword");
                damage = damage+(int)me->query_skill("force");
                damage = damage+(int)me->query_skill("spells");
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/3000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/4);
                me->add("force", -500);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
        message_vision(msg, me, target);
        return 1;
}
