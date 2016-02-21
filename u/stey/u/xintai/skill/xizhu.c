// yudian
// modi by xintai 3/11/01
#include <ansi.h>

inherit F_DBASE;
inherit SSERVER;

void check_fight(object me, object target, object victim, int amount);
int remove_effect(object me, object target, int amount);

int perform(object me, object target)
{
	int skill, skill1, skill2, i, j;
	object *member, weapon, victim = offensive_target(me);
	member = me->query_team();

	if( !victim
        ||      !victim->is_character()
        ||      victim->is_corpse()
        ||      victim==me)
                return notify_fail("��Ҫ��˭ʹ�á�˫��Ϸ�项��\n");
                
	if( sizeof(member) != 2 )
                return notify_fail("��˫��Ϸ�项����������ʹ�ã�\n");
	j=sizeof (member);
	if( j > 2 ) j = 2;
	for (i=0;i<j;i++)
        {
        target=member[i];
        if (!target||!living(target)||!target->is_character())
                return notify_fail("�����˭һ��ʹ��˫��Ϸ�飿\n");
        if (target->is_ghost() )
                return notify_fail("ֻ��������˲�������˫�����塣\n");
	if( (string)target->query_skill_mapped("force")!= "dragonforce" )
                return notify_fail("��˫��Ϸ�项����ʹ�������ķ���\n");
        if( (int)target->query_skill("fengbo-cha",1)<80)
                return notify_fail("���ǵķ粨�滹����������\n");               
       	if( !victim->is_character() || !target->is_fighting(victim) )
		return notify_fail("ֻ�ܶ���������ս���еĶ���ʹ�á�˫��Ϸ�项��\n");
	if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/skill_type") != "fork" &&
		weapon->query("skill_type") != "fork" ) || 
		target->query_skill_mapped("fork") !="fengbo-cha" )
		return notify_fail("��Ķ���û��ʹ�÷粨ʮ���棡�\\n");
	if( (int)target->query_temp("xizhu") )
		return notify_fail("��Ķ����Ѿ���ʹ��˫�������ˣ� \n");
	
	target->add("force", -200-(int)target->query("force_factor"));
	target->receive_damage("kee", 100);
	skill1 = me->query_skill("fengbo-cha", 1);
	skill2 = target->query_skill("fengbo-cha", 1);
	skill = (skill1 + skill2)/4;
		target->add_temp("apply/attack", skill);
		target->add_temp("apply/damage", skill);
		target->add_temp("apply/defense",  skill);
		target->add_temp("apply/armor",  skill);
		target->add_temp("xizhu", 1);
	remove_call_out("check_fight");	
	call_out("check_fight", 1, me, target, victim, skill);
	}
	message_vision( HIG "ֻ��ƽ����һ�����ף�$N��$n��Ϊ�����������ƶ��ϣ�˫�������ˣ�\n"NOR, me, target);
	return 1;
}

void check_fight(object me, object target, object victim, int amount)
{
	object weapon;

	if( !living(victim) || !present(victim->query("id"), environment(me)) ) 
		remove_effect(me, target, amount);

	else if(   !present(victim->query("id"), environment(me)) 
		|| !target->is_fighting(victim)
		|| !present(target->query("id"), environment(me)) 
		|| !me->is_fighting(victim) ) 
		remove_effect(me, target, amount);

	else if( !objectp(weapon=target->query_temp("weapon")) ||
		(weapon->query("apply/amount_type") != "fork" &&
		weapon->query("amount_type") != "fork" ) || 
		target->query_amount_mapped("fork") != "fengbo-cha" )
		remove_effect(me, target, amount);

	else if( !objectp(weapon=me->query_temp("weapon")) ||
		(weapon->query("apply/amount_type") != "fork" &&
		weapon->query("amount_type") != "fork" ) || 
		me->query_amount_mapped("fork") != "fengbo-cha" )
		remove_effect(me, target, amount);

	else call_out("check_fight", 1, me, target, victim, amount);
}

int remove_effect(object me, object target, int amount)
{
	if( me->query_temp("xizhu")){
	  me->add_temp("apply/attack", -amount);
	  me->add_temp("apply/damage", -amount);
	  me->add_temp("apply/armor", -amount);
	  me->add_temp("apply/defense", -amount);
	  me->delete_temp("xizhu");
	}
        if( target->query_temp("xizhu")) {
	  target->add_temp("apply/attack", -amount);
	  target->add_temp("apply/damage", -amount);
	  target->add_temp("apply/armor", -amount);
	  target->add_temp("apply/defense", -amount);
	  target->delete_temp("xizhu");
	}
	message_vision(HIW"˫����λ��\n"NOR, target);
	return 0;
}

