//onesword.c by angell

#include <ansi.h>
#include <skill.h>

inherit SSERVER;

int perform(object me, object target)
{
        int i,j,k,damage;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʹ�á�����һ������\n");

        if(!me->is_fighting())
                return notify_fail("����û���ڴ�ܣ�\n");

        if((int)me->query("max_force") < 500 )
                return notify_fail("�������̫�\n");

        if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("qixiu-jian", 1) < 100)
                return notify_fail("������޽��ȼ�����������ʹ����һ�У�\n");
        i=(int)me->query("combat_exp");
       j=(int)target->query("combat_exp");
             k=(int)me->query_skill("rake");
        
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIB"\n$N��Ȼ�������ߣ�$n��Ҫ׷��������$Nת�����һ����"NOR,me,target);
        if (random(i+j)>j) {
            damage=k/2+random(k);
        target->receive_damage("kee",damage);
       target->receive_wound("kee",damage/4);
             if (k>200) k=200;
target->apply_condition("zhushang",
(int)target->query_condition("zhushang")+1+k/50);
                COMBAT_D->report_status(target);
message_vision(HIR"\n$nһ���������������������˼�����ɼ��ǵ�Ѫ��������Ѫ��Ȫ�����\n"NOR,me,target);
        }
else {
 message_vision(HIY"\n$n����һ�����㿪����ͻ��������һ����\n"NOR,me,target);
}     
me->receive_damage("sen", 50);
        me->add("force", -200);
        me->receive_damage("kee", 30);
 if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
    me->start_busy(2+random(1));
        return 1;
}
