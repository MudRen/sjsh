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
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int)me->query("force") < 2000 )
                return notify_fail("�������������\n");
        if((int)me->query("mana") < 2000 )
                return notify_fail("��ķ���������\n");
        if((int) me->query_skill("wuyue-spear",1) <= 220)
                return notify_fail("���������ǹ����������������ʩչ��������\n");
        if((int) me->query_skill("huomoforce",1) <= 220)
                return notify_fail("��Ļ�ħ�ķ�����������������ʩչ��������\n");
        if((int) me->query_skill("moshenbu",1) <= 220)
                return notify_fail("���ħ�񲽷�����������������ʩչ��������\n");
        if((int) me->query_skill("pingtian-dafa",1) <= 220)
                return notify_fail("���ƽ��󷨻���������������ʩչ��������\n");

        message_vision(HIR"$N����Ի����ӵ������������������������߰���$n��\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), random(2)+2);
        me->start_busy(3+random(1));
                me->add("force", -1000);
                me->add("mana", -1000);
        return 1;
}
void kill_him(object me, object target)
{
        string msg;
        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIR "������$n����£����ʱ$n��������һƬ���С�
�������籩��ѩ���$N���Ϸ����������$n��
$N�ڱ���ѩ��Ļ����У����������һ��"HIY"��ɫ�Ļ�����" ;
msg +=  "\n��ɫ�Ļ���"HIR"ֱ����$n���Ŀڣ�ȫ��û�롣$nҲ�����˵��ϡ�����\n" NOR;

        message_vision(msg, me, target);
                target->die();
        }
        me->start_busy(5);
        return ;
}

