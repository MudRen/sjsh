
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
int myexp, yourexp, myskill, yourskill;
int ap, dp, damage, def;
       string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ܽ������项ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		if(me->query("family/family_name")!="��������")
 return notify_fail("���ܽ������顱ֻ�н������˵��Ӳſ���ʹ�ã�\n");
    if( (int)me->query_skill("doom-sword",1) < 200)
    return notify_fail("���ɱ�˽�������������!\n");
    if( (int)me->query("force") < 800)
    return notify_fail("�������������!\n");

      msg = RED
"\n$N�����ӻ�������˺�ѿ������ٶ�����������$n���ؿڼ��̶�ȥ��
��Ħ�������ĸ��¸��ǽ�����Χ�Ŀ���ȼ��������\n" NOR;msg += RED""+BLINK"
������������������
��  �ܽ�������  ��
������������������" NOR;
myexp= me->query("combat_exp") /10000;
yourexp=target->query("combat_exp")/10000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp+myskill;
dp=yourexp+yourskill;
if (random(ap+dp)>dp)
{
msg += RED

"\n\n$nһ�������������ؿڱ������̸����ţ����ϵĳ�����ϢѸ����
$n����ɢ����������$n��ͬ��������!!\n" NOR;
damage=(int) target->query("max_kee")/2;
             target->receive_wound("kee",damage,me);
             target->apply_condition("fire",6);
             me->add("force",-500);
             me->start_busy(3);
} 
    else {
        msg += HIY "\n\n$n������������ڱܿ���$P����һ������\n" NOR;
          me->start_busy(2+random(1));
        me->add("force",-300);
        }
//        if( wizardp(me) && (string)me->query("env/combat")=="verbose" )                       
//            tell_object(me, sprintf( GRN "AP��%d��DP��%d���˺�����%d\n" NOR,ap/100, dp/100, damage));

message_vision(msg, me, target);
return 1;
}

