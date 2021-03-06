// thunder.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 120;
	damage_adj = 120;


	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
                return notify_fail("你要对谁施展南冥离火？\n");

	if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 100 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 50);

	if( random(me->query("max_mana")) < 50 ) {
                write("你的南冥离火太弱，没有给对手造成任何伤害！\n");
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
		"shen", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
HIB "\n$N大喝一声「浩然天地！」，右手出现一团南冥离火，烧向$n！\n" NOR,
			//initial message
HIR "\n只见「噗」地一声$n突出一口鲜血，$n被烧的体无完肤！\n" NOR, 
			//success message
HIB "$n早听说过南冥离火的威力，吓了一跳，躲开了。\n" NOR, 
			//fail message
HIB "结果南冥离火被$n以法力反逼，把$N烧着了！\n" NOR, 
			//backfire initial message
HIR "\n只见「噗」地一声$n突出一口鲜血，$n被烧的体无完肤！\n" NOR, 
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(5);
}

