#include <ansi.h>
inherit SSERVER;

void delay_effect(object me, object target, object weapon,int power);

int perform(object me, object target)
{
int myexp, yourexp, myskill, yourskill,fskill;
object weapon=me->query_temp("weapon");
int ap, dp,damage;
string msg;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if(me->query("family/family_name")!="��������")
    return notify_fail("������������ֻ�н������˵��Ӳſ���ʹ�ã�\n");
    if( (int)me->query_skill("feitian-sword",1) < 300)
    return notify_fail("��ķ�������������������!\n");
    if(me->query("swordman/tianxiang_perform")!=1)
    return notify_fail("�㻹ûѧ�ᡸ������������\n");
    if( (int)me->query("force") < 2000)
    return notify_fail("�������������!\n");

message_vision(HIC
  "\n$N������$n����˵�������������С�����������֮�£���Ҳ���޺���"NOR,me,target);
message_vision(WHT
"\n\n�Աϣ�$N���е�"+weapon->name()+"���ű߼ʵػ�����$n��ȥ����ͬ�������������
�趯�ĳ���һ�㣬������˿ɱ����\n" NOR,me,target);
fskill=me->query_skill("sword",1);
myexp= me->query("combat_exp") /1000;
yourexp=target->query("combat_exp")/1000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp*myskill;
dp=yourexp*yourskill;
       if (random(3*ap)>random(2*dp))
       {
     message_vision(RED"\n$n�����������$N���е�"+weapon->name()+"ȴ��ͬ�ƹ�֮׶һ�㣬ʼ�ղ���$n��ü�İ�硣\n"NOR,me,target);
     message_vision(BLU"\n$nֻ������ǰ����һ����������$n��������翴�������ɫ�ʡ�\n"NOR,me,target);
    target->receive_damage("sen",target->query("max_sen")+1,me);
    target->receive_wound("sen", (int)target->query("max_sen")+1, me);
    target->receive_damage("kee",target->query("max_kee")+1,me);
    target->receive_wound("kee", (int)target->query("max_kee")+1, me);
        me->set("force",0);
        me->start_busy(2);
        return 1;
        }
       else
       {
        message_vision(RED "\n$n���ԶԶԾ�������ڱܿ���$P����һ������\n" NOR,me,target);
        me->start_busy(3+random(2));
        me->set_skill("sword",fskill-5);
        me->add("force",-500);
        return 1;
       }
}
