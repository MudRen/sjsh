// Ӧdxh���� �Ķ� �����ʺ�damage

#include <ansi.h>
inherit SSERVER;
#include "/daemon/skill/eff_msg.h";

int def;
int perform(object me, object target)
{       
        string msg,str;
        int damage, p,time;
        if( !target ) target = offensive_target(me);
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("�����؄š�ֻ����ս����ʹ�á�\n");
                if(me->query("family/family_name")!="��������")
                return notify_fail("��ǽ������˵��ӣ������ô��У�\n");
        if( (int)me->query_skill("kongshoudao", 1) < 100 ||
           (int)me->query_skill("unarmed", 1) < 100 )
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á����؄š���\n");
        if(me->query_skill("force", 1) <100)                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ���������؄š���\n");        
        if (me->query_skill_mapped("unarmed") != "kongshoudao")
                return notify_fail("�������޷�ʹ�á����؄š����й�����\n");                                                                                 
        if( (int)me->query("max_force") < 1200 )
                return notify_fail("���������Ϊ̫��������ʹ�á����؄š���\n");
        if( (int)me->query("force") < 600 )
                return notify_fail("�������������\n");
        msg = HIG "\n ͻȻ$N���һ��:��һ�؄š�,������ǰ,��ȭǰ��,�������³������µ�ɱ��~!\n" NOR;
        message_vision(msg, me, target); 
       msg = HIB "\n  ���ˡ���һ����һȭ����$n���ؿڣ�\n" NOR;
  if (random(me->query("combat_exp")) > random((target->query("combat_exp")/4))
         )
        {
                me->start_busy(0);
                target->start_busy(2);
                damage = (int)me->query_skill("kongshoudao", 1);
                damage = damage + random(damage/2);
 def=(int)target->query_temp("apply/armor_vs_force");
damage -=damage*def/400000000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                               me->add("force", -(damage/4));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
 if (target->query("eff_kee")<0 || !living(target))  
                 {str=HIW+target->name()+HIM"��"HIG+me->name()+HIM"ʩ�ԵĿ��ֵ�"+HIY+"�����؄š�"+HIM+"�����ˣ���˵"+target->name()+"��������,���жദ����,�������"; 
      message("channel:rumor",HIM"��"+HIC+"��������"+HIM+"��ĳ�ˣ�"+str+"\n"NOR,users()); 
      } 

               target->set_temp("last_damage_from", me);
                if(me->query_skill("kongshoudao", 1) > 149)
                   call_out("perform2", 1, me, target);                        
                      } else 
        {       me->start_busy(random(1));
                me->add("force", -200);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
  int damage, p,skill;
          string msg,weapon,str;
    weapon = me->query_temp("weapon");          if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 300 )
                return notify_fail("���Ҫ�ٳ��ڶ�����ȴ�����Լ������������ˣ�\n");     
        msg = HIW "\nֻ��$NͻȻ���һ�������؄š���\n" NOR;
        message_vision(msg, me, target); 
       msg = HIR "\n  $N����ȭЮ����֮����$n���ؿڻ�����\n" NOR;
if (me->query("combat_exp") > target->query("combat_exp")/4)
       {
                     me->start_busy(0);
                target->start_busy(2);
                damage = (int)me->query_skill("kongshoudao", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("guixi-force", 1);
                damage = (damage + random(damage))/2;
                
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/800000000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -random(damage/10));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                target->set_temp("last_damage_from", me);
 if (target->query("eff_kee")<0 || !living(target))  
                 {str=HIW+target->name()+HIM"��"HIG+me->name()+HIM"ʩ�ԵĿ��ֵ�"+HIY+"�����؄š�"+HIM+"�����ˣ���˵"+target->name()+"��������,���жദ����,�������"; 
      message("channel:rumor",HIM"��"+HIC+"��������"+HIM+"��ĳ�ˣ�"+str+"\n"NOR,users()); 
      } 


                          if(me->query_skill("kongshoudao", 1) > 179)
                   call_out("perform3", 1, me, target);                        
                      } else 
        {       me->start_busy(random(1));
                me->add("force", -200);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform3(object me, object target)
{
  int damage, p,skill;
          string msg,weapon,str;
    weapon = me->query_temp("weapon");  
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
        if( (int)me->query("force", 1) < 400 )
                return notify_fail("���Ҫ�ٳ���������ȴ�����Լ������������ˣ�\n");     
        msg = HIG "\nֻ��$N������ǰ,����$n����ǰ,n" NOR;
        message_vision(msg, me, target); 
       msg = HIC "\n ��ȭΪ���ó�������֮���İ����ѧ˫�ؼ��ޡ����؄š���\n" NOR;
if (me->query("combat_exp") > target->query("combat_exp")/4)
       {
                me->start_busy(1);
                target->start_busy(2);
                damage = (int)me->query_skill("kongshoudao", 1);
                damage = damage+(int)me->query_skill("unarmed", 1);
                damage = damage+(int)me->query_skill("guixi-force", 1);
                damage = (damage + random(damage))/2;
                
 def=(int)target->query_temp("apply/armor_vs_force");
              damage -=damage*def/1200000000;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                me->add("force", -random(damage/10));
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
               target->set_temp("last_damage_from", me);
 if (target->query("eff_kee")<0 || !living(target))  
                 {str=HIW+target->name()+HIM"��"HIG+me->name()+HIM"ʩ�ԵĿ��ֵ�"+HIY+"�����؄š�"+HIM+"�����ˣ���˵"+target->name()+"��������,���жദ����,�������"; 
      message("channel:rumor",HIM"��"+HIC+"��������"+HIM+"��ĳ�ˣ�"+str+"\n"NOR,users()); 
      } 


                      } else 
        {       me->start_busy(random(1));
                me->add("force", -200);                
                msg += HIY"����$p����һ�����㿪�˶��ֵĹ�����\n"NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
