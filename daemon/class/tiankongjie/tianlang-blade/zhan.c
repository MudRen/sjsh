// lost dream

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage =0, dragon;
        int myhammer;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("����նֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԡ�\n");
        if(me->query("family/family_name") != "��ս�")
                return notify_fail("���������ӵ�Ҳ��������ն��\n");
             
        if( (int)me->query_skill("tianlang-blade", 1) < 150 )
                return notify_fail("�������ҹĦ��������죬���ܷ���������ն����\n");
                                
        if( (int)me->query_skill("shouya-force", 1) < 150 )
                return notify_fail("�������ħ�������ߣ����ܹ������ǹɾ�����\n");
                        
        if( (int)me->query("force", 1) < 600 )
                return notify_fail("����������̫�������ܷ�����������������\n");
                        
        msg = HIG "$N�����Х������һ����,������ת����ħ������Բ����ɢ���������ɷ�Χ
��󽫻�Բ������ע�ڵ��ϣ�
һ�����������������磬���ϣ��У�����·����˺���Ҳ��������ɨ��$n��
�����Ǻ�Ļ���ľ�ѧ"HIR"������ն��\n"NOR;

        if( !target->is_killing(me) ) target->kill_ob(me);

        if (random(me->query_skill("shouya-force", 1)) > target->query_skill("force", 1)/4)
        {
                target->start_busy(1);
                
                damage += (int)me->query_skill("tianlang-blade", 1);
                damage = damage +  (int)me->query_skill("shouya-force", 1);
                damage = damage +  (int)me->query_skill("shanbishu", 1);
                
                  if (damage < 600) {
                        dragon = 1;
                   } else if (damage < 900) {
                        damage = damage/3*4;
                        dragon = 2;
                   } else {
                        damage = damage/5*8;
                        dragon = 3;
                   }                    
                
                if (damage >= target->query("max_kee")) damage = target->query("max_kee")-1;
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage/3);
                me->add("force", -300);
                msg += HIC"$n��$N������ħ���ľ���ǣ�ƶ������ã�����"+chinese_number(dragon)+"����\n$nֻ�����ж�������ɵ���ʹ�ƺ��Ѿ�����ʲô��ǿ��İ�����ֻ���$n�������������ڲ�����\n"NOR;
                me->start_busy(1+random(2));
        } else 
        {
                msg += MAG"$pʶ�����е���������󼸸�����������$P��Բ����ɢ���ķ�Χ��\n"NOR;
                me->add("force", -350);
                me->start_busy(1+random(2));
        }

        message_vision(msg, me, target);
        if (damage > 0) COMBAT_D->report_status(target);
        return 1;
}

