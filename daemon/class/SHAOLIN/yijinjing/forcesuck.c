// �������μǡ�����
// 5-8-2001 piao

#include <ansi.h>

int exert(object me, object target)
{
        int sp, dp;

        if( !objectp(target) || target->query("id") == "piao" )
                return notify_fail("��Ҫ������˭��������\n");

        if ( me->query_temp("sucked") )
                return notify_fail("��ո����ɹ�������\n");


        if( !me->is_fighting() || !target->is_fighting())
                return notify_fail("�������ս���в������ɶԷ���������\n");

        if( (int)me->query_skill("yijinjing",1) <80)
                return notify_fail("����׽�񹦹����������������ɶԷ����������\n");

        if( (int)me->query("force",1) < 500 )
                return notify_fail("�����������������ʹ�ú��ɰٴ���\n");

        if( (int)target->query("max_force") <= 0 )
                return notify_fail( target->name() +
                        "û���κ�������\n");

        if( (int)target->query("force") < (int)target->query("max_force") / 10 )
                return notify_fail( target->name() +
                        "�Ѿ�������ɢ�����Ѿ��޷��������������κ������ˣ�\n");

        message_vision(
              HIW "$N�����׽�񹦣��׹�һ������һ���������ɰٴ�����\n\n" NOR,
                me, target );

        if( !target->is_killing(me) ) target->kill_ob(me);

        sp = me->query_skill("force") + me->query_skill("dodge") + me->query("kar");
        dp = target->query_skill("force") + target->query_skill("dodge") - me->query("kar");

        me->set_temp("sucked", 1);              

        if( random(sp*3) > random(dp) )
        {
            tell_object(target, HIR "��پ�����΢ʹ����ͬ��������˸�����С�ף�ȫ��������ˮ����ѭ�׷�й������\n" 
NOR);
                tell_object(me, HIG "�����" + target->name() + "������ԴԴ����������������ڡ�\n" NOR);

                target->add("force", -1*(int)me->query_skill("yijinjing", 1) );
                me->add("force", (int)me->query_skill("yijinjing", 1) );

                if( target->query("combat_exp") >= me->query("combat_exp") ) {          
                        if( (int)me->query("potential") - (int)me->query("learned_points") < 100 )
                                me->add("potential", 1);
                        me->add("combat_exp", 1);
                }

                me->start_busy(random(2));
                target->start_busy(random(2));
                 me->add("force", -10);

                call_out("del_sucked", 2, me);
        }
        else
        {       
                message_vision(HIY "����$p������$P����ͼ����������˿�ȥ��\n" NOR, me, target);
                me->start_busy(2);
                call_out("del_sucked", 4, me);
        }

        return 1;
}

void del_sucked(object me)
{
        if ( me->query_temp("sucked"))
        me->delete_temp("sucked");
}
