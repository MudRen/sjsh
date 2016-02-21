#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        int sen_cost;   
        int my_skill;
        int pot,i;
        int amount,qlearned,qskill;
        int bimprove=1;
   
        if( me->is_fighting() )
                return notify_fail("��ս���и��о���\n");
   
        if(!arg) return notify_fail("ָ���ʽ: research <����>\n");
   
        if( !(int)my_skill=me->query_skill(arg,1) )
                return notify_fail("��Դ����һ����֪����θ��о���\n");
   
        if(my_skill<100)
                return notify_fail("�������书��ô�����ʲô�о���\n");                                                                                
   

        if( !SKILL_D(arg)->valid_learn(me) ) return 0;

        pot = (int)me->query("potential") - (int) me->query("learned_points");
   
        if(pot>1) pot=1;
        if(pot<=0)return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
   
        sen_cost = 150*pot/(int)me->query_int();
        if((int)me->query("sen") < sen_cost)
        {
        me->set("sen",0);
        return notify_fail("������̫���ˣ����ʲ��Ҳû���о�������\n");
        }

        if( (string)SKILL_D(arg)->type()=="martial"
        &&my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp"))
                return notify_fail("Ҳ������ѧ���������ʲ��Ҳû���о�������\n");

        amount=0;
        for(i=0;i<pot;i++)
        amount += random(me->query_int())+1;
        amount +=amount*my_skill/1000;
        qlearned=me->query_learned()[arg]+amount;
        qskill=(my_skill+1)*(my_skill+1);
        me->add("learned_points",1*pot);
        me->receive_damage("sen", sen_cost );
       if(qlearned>1*qskill && random(me->query_int())>32) bimprove=0;
       if(qlearned>1*qskill && me->query_int()<34 && !random(40))
        bimprove=0;
        me->improve_skill(arg, amount);
        //me->improve_skill(arg, amount,bimprove);
        write("���"+to_chinese(arg)+"����һ�����׵��о���\n");
        return 1;
}
int help(object me)
{
   write( @HELP
ָ���ʽ: research <����>

��һָ������������50��Ǳ�ܶ�ĳ�����������о���
ע: skills Ҫ�� 100 Ǳ����Ҫ2��Ǳ�ܣ�
HELP
   );
   return 1;
}
