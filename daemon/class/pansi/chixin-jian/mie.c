#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
             return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ���𽣡���\n"NOR);
        if (!target || !target->is_character() || !me->is_fighting(target) )
             return notify_fail("���𽣡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if( (int)me->query_skill("jiuyin-xinjing", 1) < 100 )
                return notify_fail("��ľ����ľ�������죬����ʹ�á�\n");
        if ((int)me->query_skill("chixin-jian",1) < 100 )
             return notify_fail(WHT"��ĳ����鳤��������죬��ʹ�������𽣡���\n"NOR);
        if ((int)me->query("max_force")<1000)
             return notify_fail(RED"���������Ϊ���㣬�޷����㡸�𽣡���������\n"NOR);
        if ((int)me->query("force")<500)
        {
               return notify_fail(HIC"����������������û�ܽ����𽣡�ʹ�꣡\n"NOR);
        }
        msg = HIC "$N���г�����âԾ�������Ⱪ�����ó�������ɫ�ʣ����⽥\n"NOR;
        msg += HIC"���ƽ�$n��$n�������콣�⣬������Ծ��ֻ��һɲ�����콣\n"NOR;
        msg += HIC"Ӱ��Ϊһ��ֱ��$nǰ�أ�������ף�ֻ��һ����\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/2|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                me->start_busy(2);
                target->start_busy(random(3));
                damage = (int)me->query_skill("chixin-jian", 1);
                damage = damage + random(damage);
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage);
                target->receive_damage("sen", damage);
                target->receive_wound("sen", damage/3);
        msg += HIR"$n����û����ܣ�һʽ�������鳤�����ľ��С��𽣡��˶���\n"NOR;
        msg += HIR"��������$n�ؿڣ�$nһ��ͷ�����������ؿڰγ���\n"NOR;
                me->add("force", -200);
        } else
        {
                me->start_busy(2);
        msg += HIY"����$p����һЦ��������ת�������ָ��������$P�Ľ��ϣ���\n"NOR;
        msg += HIY"����$p���໮�����������ˡ�\n"NOR;
                me->add("force", -200);
        }
        message_vision(msg, me, target);
        if(!target->is_fighting(me)) target->fight_ob(me);
//      if(userp(target)) target->fight_ob(me);
//      else if( !target->is_killing(me) ) target->kill_ob(me);
        return 1;
}