// yaohuo.c ����
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, dp2, dp3, damage;
	
	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("pingtian-dafa",1) < 60)
		return notify_fail("�㻹ûѧ�����𡣡���\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("�����˭���\n");  

	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ���æ�ˡ�\n");

	if(target->query_temp("no_move"))
		return notify_fail(target->query("name")+"�Ѿ����������ˣ�\n");
	if((int)me->query("mana") < 200 )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("���޷����о�����\n");

	me->add("mana", -100);
	me->receive_damage("sen", 20);

	msg = HIG
"$N͹��������ҧ����⣬�ſ�һ�磬һ�ű����׵�����ֱ��$n��ȥ��\n\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");

//�Ǻǣ������²��£��ȵ�ʶ
	ap2 = (int)me->query_cor();
	dp2 = (int)target->query_cor();


	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
// �����������ˣ�û��ô�򵥣���pingtian-dafa�ߵͣ���ҵĳ̶Ȳ�һ��
	if(success == 1 && (int)me->query_skill("pingtian-dafa",1) < 100){
		msg +=  HIR "$n����$N�Ǳ�ª����������������һ�ű̻�Ϯ������ʱ��æ���ҡ�\n" NOR;
		target->start_busy(2+random(2));
		if( living(target) ) target->kill_ob(me);
		
		
	}
	
	else if(success == 1 && (int)me->query_skill("pingtian-dafa",1) > 100){
// �ѵ�����ô�����ˣ�û�أ����и�����Ҫ�������ģ�
// �����ÿ������������Ǹ�Ե��		
		if(random(me->query("kar"))>18){
		msg +=  HIR "$n������Ϯ�У�һ�ɻ�ֱ�������衢���衢Ѫ�衢���衣������\n" NOR;
		target->apply_condition("yaohuo_poison",((int)me->query_skill("pingtian-dafa",1)/5));
		target->start_busy(3+random(2));
		damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("pingtian-dafa",1);
                
                target->receive_damage("sen", damage);
                target->receive_wound("sen", damage/3);
		
		          
		}	    
		msg +=  HIR "$nһ��������������������ȫ��ֻ����$n�ڱ��װ�������вҽ�����!\n" NOR;
		target->start_busy(1+random(2));
		damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("pingtian-dafa",1);
                
                target->receive_damage("sen", damage);
                target->receive_wound("sen", damage/3);
		if((int)me->query("mana") > 100 )
                me->add("mana", -100);
                if( living(target) ) target->kill_ob(me);
                me->start_busy(2+random(2));
                
	}
	
	else {
		msg +=  HIR "$n��Ȼ���$N���е��������������������������\n" NOR;	
		me->start_busy(2+random(2));
		if((int)me->query("mana") > 100 )
		me->add("mana", -100);        
        	if( living(target) ) target->kill_ob(me);
        	
        	
	} 
	
	message_vision(msg, me, target);

	return 1;
}



