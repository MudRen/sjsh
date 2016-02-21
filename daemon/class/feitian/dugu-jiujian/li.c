#include <ansi.h> 
#include <skill.h> 
#include <weapon.h> 
#include <combat.h> 

inherit SSERVER; 

string *pfa_msg = ({  HIW+ "����ͻ�������ı仯��������Ȼ���˷��ر�$N�׳��ĳ������ش̹���"+HIR+"��Ѫ"+HIW+"����һ�أ�\n"NOR, 
                      HIB+ "�����������Լ���������æ�Ӷ����б����뽫������������û�뵽����ͻȻת��������⴩����\n"NOR, 
                      MAG+ "��æת���������ܣ���Ҫ�㿪$N�׳������Ĺ�����ȴû�뵽������Ȼ�Ӻ�׷�ϣ��ӱ��Ĵ��˸��Դ���\n"NOR, 
}); 

int perform(object me, object target) 
{     
    int damage , zhao , i; 
    string msg; 
    object weapon , *ob; 

    if (!target ) target = offensive_target(me); 
    
    if (!objectp(weapon = me->query_temp("weapon")) 
        || (string)weapon->query("skill_type") != "sword") 
        return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ���뽣ʽ����\n"NOR); 

    if (!target || !target->is_character() || !me->is_fighting(target)) 
        return notify_fail("���뽣ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

    if ((int)me->query_skill("dugu-jiujian", 1) < 150 ) 
        return notify_fail(WHT"����¾Ž�������죬ʹ�������뽣ʽ����\n"NOR); 

    if ((int)me->query("max_force")<2000) 
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR); 

    if ((int)me->query("force")<600) 
    { 
        return notify_fail(HIC"����������������û�ܽ����뽣ʽ��ʹ����\n"NOR); 
    } 

    msg = HIW "$NͻȻ�����Ծ�����ֽ������׳�����һ���������£�\n"NOR; 
    msg += HIW "������ȴ����һ��"+HIG+"���"+HIW+"�����۾�һ��ֱ����$N���ֵ�����Ϯȥ��\n"NOR;             

    ob = all_inventory(environment(me)); 
    for(i=0; i<sizeof(ob); i++) 
    { 
        if( !living(ob[i]) || ob[i]==me ) 
            continue; 
                 
        if( !ob[i] || !ob[i]->is_character() || !me->is_fighting(ob[i])) 
            continue; 

        if (random(me->query_skill("force")) > ob[i]->query_skill("force")/2||  
            random(me->query("combat_exp")) > (int)ob[i]->query("combat_exp")/3|| 
            random(me->query_skill("dugu-jiujian")) > ob[i]->query_skill("sword")/2|| 
            random(me->query_skill("dodge")) > ob[i]->query_skill("dodge")/2) 
        {                    
            me->add("force", -150); 
            me->start_busy(2); 
            ob[i]->start_busy(random(3)); 
            damage = (int)me->query_skill("dugu-jiujian", 1) + (int)me->query_skill("sword", 1); 
            damage = damage + random(damage) + i * 500; 
            ob[i]->receive_damage("kee", damage/i); 
            ob[i]->receive_wound("kee", damage/(i+1)); 
            msg += HIY+ob[i]->query("name")+pfa_msg[random(sizeof(pfa_msg))]; 
       }else 
       { 
            me->start_busy(2); 
            msg += HIY+ob[i]->query("name")+HIG+"��׼��������Ϯ��λ�������б�������һ�鵲������������һ����\n"NOR; 
       } 
    } 
    msg += HIR"$N"+HIW+"�׳�֮���������Ҳ���Ŀ�꣬�ڿ���ת��һȦ��ɻص�"+HIR+"$N"+HIW+"�����У�\n"NOR; 
   message_vision(msg, me ,target);
    if(!target->is_fighting(me)) target->fight_ob(me); 
    return 1; 
} 
