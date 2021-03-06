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
                return notify_fail("「天翔龙闪」只能对战斗中的对手使用。\n");
    if(me->query("family/family_name")!="剑客联盟")
    return notify_fail("“天翔龙闪”只有剑客联盟弟子才可以使用！\n");
    if( (int)me->query_skill("feitian-sword",1) < 300)
    return notify_fail("你的飞天御剑流还不够纯熟!\n");
    if(me->query("swordman/tianxiang_perform")!=1)
    return notify_fail("你还没学会「天翔龙闪」！\n");
    if( (int)me->query("force") < 2000)
    return notify_fail("你的内力不够了!\n");

message_vision(HIC
  "\n$N抚剑对$n淡淡说道：能死在这招“天翔龙闪”之下，你也可无憾。"NOR,me,target);
message_vision(WHT
"\n\n言毕，$N手中的"+weapon->name()+"不着边际地缓缓向$n刺去，如同曼妙的舞者手中
舞动的长剑一般，不带半丝杀气。\n" NOR,me,target);
fskill=me->query_skill("sword",1);
myexp= me->query("combat_exp") /1000;
yourexp=target->query("combat_exp")/1000;
myskill=me->query_skill("sword");
yourskill=target->query_skill("parry");
ap=myexp*myskill;
dp=yourexp*yourskill;
       if (random(3*ap)>random(2*dp))
       {
     message_vision(RED"\n$n左躲右闪，但$N手中的"+weapon->name()+"却如同跗骨之锥一般，始终不离$n的眉心半寸。\n"NOR,me,target);
     message_vision(BLU"\n$n只觉得眼前蓝光一闪，那已是$n在这个世界看到的最后色彩。\n"NOR,me,target);
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
        message_vision(RED "\n$n向后远远跃开，终于避开了$P的这一击！！\n" NOR,me,target);
        me->start_busy(3+random(2));
        me->set_skill("sword",fskill-5);
        me->add("force",-500);
        return 1;
       }
}
