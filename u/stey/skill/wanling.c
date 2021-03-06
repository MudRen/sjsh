#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int kee_wound;
	        
	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「万铃魔音」？\n");

        if(!me->is_fighting())
                return notify_fail("「万铃魔音」只能在战斗中使用！\n");

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");
	if(me->query("family/family_name")!="盘丝洞")
                return notify_fail("“天上人间”只有盘丝洞门人才可以用！\n");
        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("yinsuo-jinling", 1) < 150)
                return notify_fail("你的银索金铃级别还不够，使用这一招会有困难！\n");
        if (me->query_skill_mapped("whip") != "yinsuo-jinling")
        return notify_fail("你现在无法使用「万铃魔音」来攻击。\n");
	if(random((int)me->qurey("PKS")) >5 )
	 return notify_fail("你充满邪恶之气，驱动不了至灵的银索。\n");
	 if(random(60) > (int)me->query("kar"))
	 return notify_fail("你银索金铃不听你的使唤了。\n");	 
	me->delete("env/brief_message");

	message_vision(HIC"\n$N云足精神，内力行走了大小周天，突然媚笑一声“"HIR"万铃魔音"NOR+HIC"”！顿时间天昏地暗，电闪雷鸣，地动天摇！\n"NOR, me);


//	me->set_temp("yinsuojinling_per", 8);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

//	me->delete_temp("yinsuojinling_per");
        
        kee_wound = me->query("eff_kee")/(2+random(5));
	me->receive_damage("kee", 50);
	target->add("kee", -kee_wound);	
	target->add("eff_kee", -(kee_wound));
	me->add("force", -100);
	message_vision(HIW"$n被万铃齐鸣的魔音搅心神不定，七窍五俯震坏了，翻倒在地。\n"NOR,me, target);
	target->start_busy(3);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

	me->start_busy(3);
	return 1;
}
