#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

        success_adj = 180;
        damage_adj = 170;

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��˭ʩչħ���䣿\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 50 )
		return notify_fail("���޷����о�����׼��\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
		me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("����������������ˣ�\n");
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
		HIC "$N�������˼������ģ�����һ����ħ���䣡��������ֳ�һ���޴��ħ����\nֻ��ħ������֮�£����䡱��һ������$n��ͷ���£�\n" NOR,
			//initial message
		HIC "����Ҹ����ţ����û��$n�Ǳ⣡\n" NOR, 
			//success message
		HIC "����$n��ǧ��һ��֮�����˿�����\n" NOR, 
			//fail message
        HIC "���Ǻ�����$n�Է���һ���������ǵ���$N�Ķ��ţ�\n" NOR,
			//backfire initial message
		HIC "����Ҹ����ţ����û��$nѹ�⣡\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

