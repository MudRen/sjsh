// feitian-jian.c  ���콣
// Modified by Cody March.2001
// Write by Cody

#include <ansi.h>

inherit SSERVER;


int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int myexp,yourexp,lvl;    
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�� �������� ��?\n");
         
         if ((string)me->query("family/family_name")!="��ׯ��")
     return notify_fail("�㲻����ׯ�۵���,����ʲô!!\n"); 
        if( !me->is_fighting() )
            return notify_fail("�� �������� ��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

        if( environment(me)->query("no_fight") )
                return notify_fail("�����ﲻ�ܹ������ˡ�\n");

        if( (int)me->query_skill("xiaofeng-sword", 1) < 100)
                return notify_fail("���������½��ȼ�����������ô��ʹ���� �������� ����\n");

    if( (int)me->query("combat_exp",1) < 150000 )
             return notify_fail("��ľ��鲻�㣬����ʹ���� �������� ����\n");

        if (me->query("force") < 300)
                return notify_fail("���������̣�����ʹ���� �������� ����\n");

        me->clean_up_enemy();
        ob = me->select_opponent();
        myexp = (int) me->query("combat_exp");
        yourexp = (int) target->query("combat_exp");
        lvl = (int)me->query_skill("xiaofeng-sword",1)/20;
        
           msg = HIC
"\n$N��ɫ��ת����,���н�â�ó���ʹ�â���㽫������$n����Ȧȥ��\n" NOR;
       if(random(myexp)>yourexp/10)
        {
                message_vision(msg + "\n", me, target);
        msg = HIM "$nֻ�����ɽ���Ȧס�Լ�,��ʱȫ��һ��,��������!!\n" NOR;
                
                message_vision(msg, me, target);
target->start_busy(1+random(lvl));
        message_vision(HIM" ͻȻһ����ʽ�����ס$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIW"ͻȻ�ڶ�����ʽ�����ס$n��"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        message_vision(HIC"ͻȻ��������ʽ�����ס$n"NOR, me, ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

        }
    else {
            message_vision(msg +"\n", me, target);
           msg = HIY "����$n�ƺ�������$N����ͼ,��ȥ����ʽ��������Ρ�\n" NOR;
message_vision(msg, me, target);
            me->start_busy(2); }        
        me->add("force", -150);
        me->start_busy(1);
        return 1;  

}
