// /daemon/class/fighter/wusi-mace/andu
// �²ְ���
// ��Ҫ�Լ�ѧʲô����ȫ�öԷ����书�����Է�
// Ľ�ݾ�ѧ���Ǻǡ�����
// writted by jie 2001-2-12

#include <ansi.h>

inherit SSERVER;
int perform(object me,object target)
{
        int damage;
        string msg;
        string limb,*limbs,attack_skill,attack;
        object weapon;
        mapping action;
        if( !target ) target = offensive_target(me);

        if(!target||!target->is_character() || !me->is_fighting(target) )
        return notify_fail("�²ְ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("literate",1)<80)
        return notify_fail("��Ķ���ʶ�ֲ��ô�����о���ԣ��ò��ˡ��²ְ��ɡ���\n");
                
        if( (int)me->query_skill("wusi-mace",1)<50)
        return notify_fail("�����˽ﵷ�������죬����ʹ�á��²ְ��ɡ���\n");
        if( (int)me->query_skill("lengquan-force",1)<50)
        return notify_fail("�����Ȫ�񹦲�����񣬲���ʹ�á��²ְ��ɡ���\n");
                                
                        
        if( (int)me->query("force",1)<200)
        return notify_fail("����������̫��������ʹ�á��²ְ��ɡ���\n");
                        
        msg=HIY"$N��һ���񣬼������������²ְ��ɡ�����ƶ�Ȼʩչ����\n"NOR;

        me->start_busy(3);
        target->start_busy(random(3));
                
        damage = (int)me->query_skill("wusi-mace",1);
                
        damage = damage/2 + random(damage);
                
        target->receive_damage("kee",damage);
        target->receive_wound("kee",damage/3);
        me->add("force",-damage/10);
                
        weapon=target->query_temp("weapon");
        if(objectp(weapon))
                attack_skill=weapon->query("skill_type");
        else
                attack_skill="unarmed";
        attack=target->query_skill_mapped(attack_skill);
        if(!attack)     attack=attack_skill;
        msg +=HIY"$NʩʩȻ�ݳ�$n��ѧ��\n          ����"HIM+to_chinese(attack)+HIY"����\n�����о����̣�������ԣ���Ȼ���Ȳ��ң�\n"NOR;

        limbs=target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        action=target->query("actions");
        if( !mapp(action) ) {
                target->reset_action();
                action=target->query("action");
                
        }
        msg += action["action"]+"��\n";
        msg+=HIR"$nû�ϵ��Է��ݹ����Ķ����Լ������ѧ����ʱ����ʧ�룡\n�����$l���"+action["damage_type"]+"����\n\n"NOR;
        msg=replace_string(msg,"$l",limb);
        if(objectp(weapon)) msg=replace_string(msg,"$w",weapon->name());
        message_vision(msg, me, target);
        COMBAT_D->report_status(target, 0);
        return 1;
}

