// lidichenfo.c ������Ӱ��      ���سɷ�
//wirted by piao 2001-10-04

#include <ansi.h>

inherit SSERVER;

#include "/daemon/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill;
        object weapon;
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("��"HIY"���سɷ�"NOR"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_skill_mapped("dodge") != "shaolin-shenfa")
                return notify_fail("������û�����ֵ������޷�ʩչ��"HIY"���سɷ�"NOR"����\n");
        if( (int)me->query_skill("shaolin-sword", 1) < 100 )
                return notify_fail("���������Ӱ����������죬�޷�ʩչ��"HIY"���سɷ�"NOR"����\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"��ʹ�õ��������ԣ��޷�ʩչ��"HIY"���سɷ�"NOR"��!\n"NOR);

        if (me->query_skill_mapped("force") != "yijinjing")
        return notify_fail("��"HIY"���سɷ�"NOR"��������������׽����ʹ��!\n"NOR);

        if( (int)me->query("max_force") < 2000 )
                return notify_fail("�������������㣬�޷�ʩչ��"HIY"���سɷ�"NOR"����\n");     

         if( (int)me->query("force") < 500 )
                return notify_fail("�����������������޷�ʩչ��"HIY"���سɷ�"NOR"����\n");     

        if( (int)me->query_skill("yijinjing", 1) < 120 )
                return notify_fail("����׽�񹦲�����죬�޷�ʩչ��"HIY"���سɷ�"NOR"����\n");

        if (me->query_str() < 20 )
                return notify_fail("�������̫С���޷�ʩչ��"HIY"���سɷ�"NOR"����\n");

        if( me->query_temp("sl_wuying") )
                return notify_fail("���ʹ�꡸"HIY"���سɷ�"NOR"�����У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        
        msg = RED "\n$N�ӵ����ϵ���������˵�����������������سɷ�һ��ǿ��֮���Ʒ�ֱ��$n��ȥ��\n"NOR;        
        weapon->move(environment(me));

        me->set_temp("sl_wuying", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /4 ){                     
                me->start_busy(1);
                target->start_busy(2); 
                me->add("force", -200);
                me->add("sen", -20);
                damage = (int)me->query_skill("shaolin-sword", 1);                
                damage = damage*2 + random(damage);
                if(me->query("force") > target->query("force")*2 ) damage += random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
                target->start_busy(1);
                me->add("force", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("shaolin-shenfa");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("force", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ����ȴ�����Լ������������ˣ�\n");     

        msg = HIC "\n$N���ƾ���δ��������Ҳ�����Ƴ�����������������سɷ��Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("shaolin-sword", 1) > 150 ){                
                me->start_busy(1);
                target->start_busy(2);
                me->add("force", -300);
                me->add("sen", -30);                
                damage = (int)me->query_skill("shaolin-sword", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("force") > target->query("force")*2 ) damage += random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(2);
                me->add("force", -200);
                tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("shaolin-shenfa");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/4, me);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("force", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ����ȴ�����Լ������������ˣ�\n");     

        msg = HIG "\n$N΢΢һЦ��˫���ಢ��ǰ�Ƴ�����������ʲô��������$n��ͬ��ǰ��Բ����ȫ�ڡ����سɷ𡹾�������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 4 &&
            me->query_skill("shaolin-sword", 1) > 199 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("force", -400);
                me->add("sen", -40);                
                damage = (int)me->query_skill("shaolin-sword", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("force") > target->query("force")*2 ) damage += random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/2);
                p = (int)target->query("kee")*100/(int)target->query("max_kee");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(2);
                target->start_busy(1);
                me->add("force", -300);
                target->add("sen", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("shaolin-shenfa");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        call_out("remove_effect", me->query_con()/2, me);
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("sl_wuying");
        tell_object(me, HIC"\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á����سɷ𡹾����ˡ�\n"NOR); 
}


