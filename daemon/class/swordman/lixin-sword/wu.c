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
                return notify_fail("����ͻ����ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if(me->query("family/family_name")!="��������")
    return notify_fail("����ͻ����ʽ��ֻ�н������˵��Ӳſ���ʹ�ã�\n");
    if( (int)me->query_skill("lixin-sword",1) < 180)
    return notify_fail("�����Ȼ����������������!\n");
    if(me->query("swordman/wu_perform")!=1)
    return notify_fail("�㻹ûѧ�ᡸ��ͻ����ʽ����\n");
    if( (int)me->query("force") < 800)
    return notify_fail("�������������!\n");

msg = HIR
"\n$N����ͻȻ�˺�������ǰ΢̤һ��������ǰƽָ������΢���£�������ָ
ƽ���ڽ���֮�ϣ��˽���һ����ͬ�������$nϮȥ��\n" NOR;
myexp= me->query("combat_exp") /1000;
yourexp=target->query("combat_exp")/1000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp*myskill;
dp=yourexp*yourskill;
if (random(3*ap)>random(2*dp))
{
msg += HIR
"\n\n$nһ�������������ؿڱ����˸�Ѫ��ģ���Ĵ�!!\n" NOR;
damage=(int) target->query("max_kee")/3;
target->receive_wound("kee",damage,me);
target->start_busy(3);
me->add("force",-500);
 } 
else
{
msg += HIY "\n\n$n������������ڱܿ���$P����һ������\n" NOR;
me->start_busy(3);
me->add("force",-300);
}
message_vision(msg, me, target);
return 1;
}

