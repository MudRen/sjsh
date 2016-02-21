// �׵�ŭ��
// xintai 3/11/01

#include <ansi.h>

inherit SSERVER;
inherit F_DBASE;

int cast(object me, object target)
{
	object *member, victim = offensive_target(me);
        string msg;
        int a_fali, d_fali, damage, ap, dp, i, j;
        member = me->query_team();
 
	if( !victim
	||      !victim->is_character()
	||      victim->is_corpse()
	||      victim==me )
		return notify_fail("�����˭ʹ�á��׵�ŭ�Ρ���\n");
	
	if( sizeof(member) != 2 )
                return notify_fail("���׵�ŭ�Ρ�����������ʹ�ã�\n");
	j=sizeof (member);
	if( j > 2 ) j = 2;
	for (i=0;i<j;i++)
        {
        target=member[i];
	if( !target||!living(target)||!target->is_character())
		return notify_fail("������˭���С��׵�ŭ�Ρ���\n");
	if( victim->query("id") == target->query("id") )
		return notify_fail("��������Ķ��ֽ��С��׵�ŭ�Ρ���\n");
	if( !victim->is_character() || !target->is_fighting(victim) )
		return notify_fail("ֻ�ܶ���������ս���еĶ���ʹ�á��׵�ŭ�Ρ���\n");
        if( target->is_busy() || target->query_temp("pending/meditating") 
            || target->query_temp("qingwang")|| (int)target->query_temp("no_cast")==1 )
                return notify_fail("�������ڲ�����ħ����\n");   
	if( !target->is_fighting(victim) )
		return notify_fail("���ͬ�鲻�������ս���С�\n");
	if(target->query_skill("dao", 1) < 120 || target->query_skill_mapped("spells") !="dao"  )
		return notify_fail("���ǵĵ����ɷ��ȼ�������\n");
	if((int)target->query("mana") < 800+(int)target->query("mana_factor") )
		return notify_fail("���ǵ�ħ��������\n");
	if((int)target->query("sen") < 200 )
		return notify_fail("���ǵľ����㣬û����ʩ�÷�����\n");
	}
	me->add("mana", -150-(int)me->query("mana_factor"));
	me->receive_damage("sen", 150);
	target->add("mana", -50-(int)target->query("mana_factor"));
	target->receive_damage("sen", 100);

	
 msg = HIC
"$N��$n����ͬʱ���˼������ģ�������ֳ������ۣ�ֻ����ʮָ���ţ�һ�����״��������������"+victim->query("name")+"��ͷ���£�\n" NOR;

        ap = me->query_skill("spells");
        ap = ap / 10 * ap * ap ;
        ap = ap/500000*(1+me->query("daoxing"));
        ap += target->query("daoxing")/2;
        dp = victim->query("daoxing");
        if( random(ap + dp) > dp ) {
                a_fali = (int)me->query("max_mana") / 20 + random((int)me->query("eff_sen") / 10);
                d_fali = (int)victim->query("max_mana") / 20 + random((int)victim->query("eff_sen") / 10);  
                a_fali+= (me->query("mana_factor")+ target->query("mana_factor")/2)/100*120;    
     		d_fali+= random((int)victim->query("mana_factor"));
     		
     		damage = a_fali - d_fali;
                if( damage > 0 ) {
     msg += HIC "����������ţ�"+victim->query("name")+"���׵��Ļ����ڣ����ǲ��壡\n" NOR;
     		damage += damage*(int)me->query_skill("spells")/150;
                        victim->receive_damage("sen", damage, me);
                        victim->receive_wound("sen", damage/2, me);
                        victim->receive_damage("kee", damage, me);
                        victim->receive_wound("kee", damage/2, me);
                        me->improve_skill("dao", 1, 1);
                        target->improve_skill("dao", 1, 1);
                }
       else {
     msg += HIC "����׵类"+victim->query("name")+"�Է�������������������$N��$n��\n" NOR;
     damage -= (int)victim->query("mana_factor");
     damage -= -damage*(int)target->query_skill("spells")/200;
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/2, target);
                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/2, target);
                        target->receive_damage("sen", -damage, target);
                        target->receive_wound("sen", -damage/2, target);
                        target->receive_damage("kee", -damage, target);
                        target->receive_wound("kee", -damage/2, target);
                        me->improve_skill("dao", 1, 1);
                        target->improve_skill("dao", 1, 1);
       }
             } 
   else
                msg += "���Ǳ�"+victim->query("name")+"�㿪�ˡ�\n";

        message_vision(msg, me, target, victim);
        if( damage > 0 ){
         COMBAT_D->report_status(victim);
        		COMBAT_D->report_sen_status(victim);
        } 		
        else if( damage < 0 ) {
        	COMBAT_D->report_status(me);
        		      COMBAT_D->report_sen_status(me);
               	COMBAT_D->report_status(target);
         		      COMBAT_D->report_sen_status(target);
        } 		      
    
        me->start_busy(2+random(2));
        target->start_busy(2+random(2));
        return 3+random(5);
}

