// added to adm
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int myskill,times, damage;
        string number;
        myskill = (int)me->query_skill("wugou-jian", 1);  
        weapon = me->query_temp("weapon");
      
        if( !target ) target = offensive_target(me);
        
       
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С�������ɡ���\n");

        if(!me->is_fighting())
                return notify_fail("��������ɡ�ֻ����ս����ʹ�ã�\n");
                
        if(me->query("family/family_name") != "����ɽ���鶴" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á�������ɡ�?\n");
	
                
        if(!objectp(weapon = me->query_temp("weapon"))
           ||(string)weapon->query("skill_type")!="sword")
                return notify_fail("��������ɡ�Ҫ�ý����ܷ���������\n");

        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");

	if((int)me->query("force") < 300 )
		return notify_fail("����������㣡\n");

        if((int)me->query("sen") < (int)(me->query("max_sen")/2) )
                return notify_fail("��ľ��񲻹����޷�ʹ��������ɣ�\n");

        if(myskill < 40)
                return notify_fail("����⹳�������𻹲�����\n");
        else 
            if(myskill <70){
                times = 3;        
                number = "��";}
            else
                if (myskill <90){
                    times = 4;
                    number = "��";}
                else
                    if(myskill <110 ){
                           times = 5;
                           number = "��";}
                     else{ 
                           times = 6;
                           number = "��";}

        me->delete("env/brief_message");
	target->delete("env/brief_message");
	damage = me->query_str() + random(me->query_skill("sword"));

message_vision(HIC"\n$Nһ����Х��"+ weapon->query("name")+ HIC"��һת�������������$n������"+number+"��������Ҫ����\n"NOR,me,target);

        for(int i=1;i<=times;i++)
        COMBAT_D->do_attack(me, target, weapon);
        
        me->receive_damage("sen", 20);
        me->add("force", -(times*50+50));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
	if(me->is_fighting() && target->is_fighting() &&
	environment(me) == environment(target) && times>5)
	{

                target->receive_damage("sen",damage,me);
	}
        me->start_busy(2+random(3));
        return 1;
}

