// force.c
// modi by xintai 3/10/2001

inherit SKILL;

mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	int damage;

	me->add("force", - factor );
	// enforce 1��enforce 0֮��Ĳ��̫���ˣ����Լ�������жϡ�
	damage = factor - random(victim->query("force_factor"));
	if (damage > 0) {
	damage += (int)me->query("force")/20 - (int)victim->query("force")/25;
	    }
	else 
	    {	
	    	damage +=  (int)me->query("force")/20 - (int)victim->query("force")/25;
	    	if (damage > 0) damage = 0;
	    	if( !me->query_temp("weapon")
		&&	random(victim->query_skill("force")) > me->query_skill("force")/2 ) {
			damage = - damage-1;
			me->receive_damage( "kee", damage * 2 );
			me->receive_wound( "kee", damage );
			if( damage < 10 ) return "$N�ܵ�$n�����������ƺ�һ����\n";
			else if( damage < 20 ) return "$N��$n���������𣬡��١���һ������������\n";
			else if( damage < 40 ) return "$N��$n������һ���ؿ������ܵ�һ���ػ�����������������\n";
			else return "$N��$n������һ����ǰһ�ڣ��������ɳ���������\n";
		}
		if( damage_bonus + damage < 0 ) return - damage_bonus;
		return damage;
	}

	damage -= victim->query_temp("apply/armor_vs_force");
	if( damage_bonus + damage < 0 ) return - damage_bonus;
	if( random(me->query_skill("force")) < damage )
		return damage;
}