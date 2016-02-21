// xiudao.c

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

#include <obstacle.h>

void finish(object me, int pot_gain);

int main(object me, string arg)
{
	int obstacle_size = sizeof(obstacles);
	int busy_time, pot_gain;
	int xiudao_lvl;
	mapping fam;
	object where;

	seteuid(getuid());
	where = environment(me);
	
	if(where->query("no_fight") || where->query("no_magic") )
	     return notify_fail("��ȫ���ڽ�ֹ������\n");
	
	if (where->query("no_flee"))
		return notify_fail("�˴����˾���������\n");

	if ( (xiudao_lvl = me->query_skill("spells")) < 20 ) 
		return notify_fail("�㷨����Ϊ̫�ͣ������й�������\n");
        if( (int)me->query("daoxing") > 1050000 )
                return notify_fail("���Ѿ����ߵ�¡�ˣ������й�������\n");


	if (me->is_busy() || me->query_temp("pending/exercising")
		|| me->query_temp("doing_xiudao"))
		return notify_fail("��������æ���ء�\n");

	if( me->is_fighting() )
		return notify_fail("ս�����޵�������������\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
		return notify_fail("���������ǲ��壬��������Ҫ�߻���ħ��\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
		return notify_fail("����������������������Ҫ�����ˣ�\n");

	pot_gain = xiudao_lvl/10 + random(3);
	busy_time = random(6000)/pot_gain/60+2;
	pot_gain = 1 + random(pot_gain*3);
	busy_time *= pot_gain;
	pot_gain += (int)me->query("obstacle/number")*pot_gain/2/obstacle_size;
        pot_gain = random(pot_gain*60);
        if (me->query("food") + me->query("water") < 20) busy_time *= 2;
	message_vision(HIY "$N�����۾�����ϥ���£�����ĬĬ���֪��˵Щʲô��\n" NOR, me);
	me->start_busy(busy_time+2);
	me->set_temp("doing_xiudao",1);
	call_out("finish",busy_time, me, pot_gain);
	return 1;
}

void finish(object me, int pot_gain)
{
    if(!me) return;

    // mon /10/19/98
//    if(wizardp(me)) {
//	MISC_D->random_capture(me,1,0);
//	return;
//   }
    me->delete_temp("doing_xiudao");
    if(MISC_D->random_capture(me,3000,0)) return;

	message_vision(HIY "$N���������۾�������һ����վ��������\n" NOR, me);

               if( (int)me->query("potential") < 10400 ){
        tell_object(me, HIC "��ĵ���������" + chinese_number(pot_gain*6) + "ʱ����\n" NOR);
        tell_object(me, HIC "���Ǳ��������" + chinese_number(pot_gain/5) + "�㣡\n" NOR);
                me->add("daoxing", pot_gain);
                me->add("potential", pot_gain/5);
   return;
}
        tell_object(me, HIC "��ĵ���������" + chinese_number(pot_gain*6) + "ʱ����\n" NOR);
                me->add("daoxing", pot_gain);
                me->add("potential", 0);

       me->add("food",- 10);

       me->add("water",- 10);

	me->receive_damage("sen", me->query("int"));
	me->receive_damage("kee", me->query("int"));
	me->improve_skill("spells", random(pot_gain));

	me->start_busy(1);
}

int help(object me)
{
        write(@HELP
ָ���ʽ : xiudao

������������ߵ��С�
HELP
        );
        return 1;
}
