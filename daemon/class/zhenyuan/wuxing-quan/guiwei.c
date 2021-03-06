//guiwei...2001.3

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int success_adj, damage_adj;

	success_adj = 100;
	damage_adj = 100;

	if( !target ) target = offensive_target(me);

	if( !target
	||   !target->is_character()
	||   target->is_corpse()
	||   target==me)
		return notify_fail("你要攻击谁？\n");

	if((int)me->query_skill("wuxing-quan", 1) < 100 )
		return notify_fail("你的五行拳法还不够精熟还不能真源归位！\n");
        if (me->query_skill_mapped("unarmed")!="wuxing-quan")
            return notify_fail("归位必须配合五行拳才能使用。\n");
	if (!me->is_fighting())
             return notify_fail("五行归位只能在战斗中使用！\n");
        
        if((int)me->query("mana") < 20+2*(int)me->query("mana_factor") )
		return notify_fail("你的法力不够，还不能使你的五行真源归位！\n");

	if((int)me->query("force") < 100 )
		return notify_fail("你的内力不够，无法将真源归位。\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你现在神智不清，何来真源！\n");

	me->add("mana", -20-2*(int)me->query("mana_factor"));
	me->add("force", -100);
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) 
	{
		write("你还是去多多冥思吧。\n");
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
		HIW "$N突然双手双举对天大喊道：金、木、水、火、土五行真源速速归位!只见空气中突然暴开五色光球急速向$n飞去！\n" NOR,
			//initial message
		HIC "结果$n被你的真源逼的连连倒退！\n" NOR, 
			//success message
		HIC "但是$n轻轻一跳就躲了开来。\n" NOR, 
			//fail message
		HIC "但是你的真源被$n的真源硬给逼了回来！\n" NOR, 
			//backfire initial message
		HIC "结果你的真源被对方打破，$n的五行四散而去！\n" NOR
			//backfire hit message. note here $N and $n!!!
	);

	me->start_busy(1+random(2));
	return 3+random(2);
}

