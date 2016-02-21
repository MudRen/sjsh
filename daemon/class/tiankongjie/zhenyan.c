// zhenyan.c
#include <ansi.h>
//#define SPELL_D "/adm/daemons/spelld"
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 150;
 damage_adj = 120;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("��Ҫ��˭����ԣ�\n");
 if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
  return notify_fail("��ķ���������\n");
 if((int)me->query("sen") < 20 )
  return notify_fail("���޷����о�������ԡ�\n");
 me->add("mana", -25-2*(int)me->query("mana_factor"));
 me->receive_damage("sen", 10);
 if( random(me->query("max_mana")) < 50 ) {
  write("����û��Ӧ������һ�ΰɣ�\n");
  return 1;
 }
 SPELL_D->attacking_cast(
  me,
   //attacker
  target,
   //target
  success_adj,
   //success adjustment
  damage_adj,
   //damage adjustment
  "both",
   //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
  HIC "$N����ʳָ��סĴָָ�⣬����ָ��£���������⡣
"MAG"���������"HIR"�ߣ�"HIY"Ħ��"YEL"��"HIG"�ߣ�"HIC"�ȣ�"HIB"��"HIM"��"HIW"�գ�����
"NOR"��"WHT"ֻ��һ���������پ���$n��\n" NOR,
   //initial message
  MAG "���������ס��$n,$n��Ҫ��˺���ˡ�\n" NOR,
   //success message
  HIR "$nһ�����������ݣ����˿�ȥ��\n" NOR,
   //fail message
  HIW "$nһ�������ù�����ǰ����������һ��������������������$N��\n" NOR,
   //backfire initial message
  HIR "���$N��������������գ�\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(2));
 return 3+random(5);
}

