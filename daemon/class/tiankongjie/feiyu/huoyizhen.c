// huoyizhen  lost 2002

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��¥�޻�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query("force") < 3000 )
                return notify_fail("�������������\n");
        if((int)me->query("mana") < 3000 )
                return notify_fail("��ķ���������\n");
        if((int) me->query_skill("feiyu",1) <= 300)
                return notify_fail("��ķ��𻹲�������������ʩչ����¥�޻�����\n");
        if((int) me->query_skill("mtl-force",1) <= 300)
                return notify_fail("�����٢���ľ�����������������ʩչ����¥�޻�����\n");
        if((int) me->query_skill("shanbishu",1) <= 300)
                return notify_fail("�������������������������ʩչ����¥�޻�����\n");
        if((int) me->query_skill("baimofa",1) <= 300)
                return notify_fail("��İ�ħ������������������ʩչ����¥�޻�����\n");

        message_vision(HIR"$N����Ի����ӵ������������������������߰���$n��\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(1)+3);
        me->start_busy(2+random(2));
                me->add("force", -2000);
                me->add("mana", -2000);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIR "������$n����£����ʱ$n��������һƬ���С�
��ë���籩��ѩ���$N���Ϸ����������$n��
$N�ڱ���ѩ�����ë�У������ӳ���һ��"HIY"��ɫ�ķ���" ;
msg +=  "\n��ɫ�ķ���"HIR"ֱ����$n���Ŀڣ�ȫ��û�롣$nҲ�����˵��ϡ�����\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
        me->start_busy(3);
        return ;
}

