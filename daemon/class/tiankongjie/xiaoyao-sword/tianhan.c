z//lost
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;

   int ap, myexp, yourexp;
        if(me->query("family/family_name") != "��ս�")
                return notify_fail("���������ӵ�Ҳ�����캮��\n");
if(me->is_busy()) return notify_fail("����æ����!\n");
if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("�캮ֻ����ս����ʹ��.\n");


    if( (int)me->query_skill("xiaoyao-sword",1) <80)
    return notify_fail("�����ң���ȼ�������!!\n");
   if( (int)me->query("max_force") <600)
   return notify_fail("�������̫��,������ʩչ�캮!\n");
  if( (int)me->query("force") <250)
  return notify_fail("�������������!!!\n");
   ap = (int)me->query_skill("xiaoyao-sword",1)/40+1;
  myexp = (int)me->query("combat_exp");
  yourexp = (int)target->query("combat_exp");
    msg = HIW
"\n$N�������,ƮȻ����,��̬��������,��������,�����ɢ��, ����̾Ϊ��ֹ!!\n"
"$n���Ŀ�����֮��,������֮�������ӿ��н���,ɲ�Ǽ���ס$nȫ��.\n\n" NOR;

    if( random(myexp*ap) > yourexp)
{
    msg += HIR
"\n�캮����$n����,�汬��$n��������.\n" NOR;
        target->receive_damage("kee",((int)target->query("max_kee")/47),me);
        target->receive_wound("kee",((int)target->query("max_kee")/72),me);
       me->start_busy(1+random(1));
        } else {
        msg += HIY
"\n$n�����б�����÷��겻͸,û���캮����һ˿һ��!!\n" NOR;
me->start_busy(2+random(1));
        }
me->add("force",-100);
        message_vision(msg, me, target);
        return 1;
}

