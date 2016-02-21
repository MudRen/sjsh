// lost.c
#include <ansi.h>
//#define SPELL_D "/adm/daemons/spelld"
inherit SSERVER;
int cast(object me, object target)
{
 int success_adj, damage_adj;
 success_adj = 130;
 damage_adj = 150;
 if( !target ) target = offensive_target(me);
 if( !target
 ||      !target->is_character()
 ||      target->is_corpse()
 ||      target==me)
  return notify_fail("��Ҫ��˭���������ģ�\n");
 if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
  return notify_fail("��ķ���������\n");
 if((int)me->query("sen") < 20 )
  return notify_fail("���޷����о������������ġ�\n");
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
  HIC "$N�ӵ�������˫�����죬�ڹ�Ʈ�죡
"HIB"$N����������Х����"NOR""WHT"�����ģ�"HIW"����ɽ"NOR""WHT"������"HIB"��
"NOR"��"WHT"һ���޴��"WHT"��"HIW"����ɽ"NOR"��"WHT"��һ�ź�����������$n\n" NOR,
   //initial message
  RED "���$n��ѹ���ˣ�\n" NOR,
   //success message
  HIR "$nһ�����������ǰһԾ�����˿�ȥ��\n" NOR,
   //fail message
  HIW "$n����С��վ��$N�����¡�����ɽ������$N��ͷ����\n" NOR,
   //backfire initial message
  RED "���$N��ѹ���ˣ�\n" NOR
   //backfire hit message. note here $N and $n!!!
 );
 me->start_busy(1+random(2));
 return 3+random(5);
}
