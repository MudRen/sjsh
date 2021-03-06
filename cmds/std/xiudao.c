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
	     return notify_fail("安全区内禁止练功。\n");
	
	if (where->query("no_flee"))
		return notify_fail("此处不宜静坐修练！\n");

	if ( (xiudao_lvl = me->query_skill("spells")) < 20 ) 
		return notify_fail("你法术修为太低，不能行功修炼！\n");
        if( (int)me->query("daoxing") > 1050000 )
                return notify_fail("你已经道高德隆了，不能行功修炼！\n");


	if (me->is_busy() || me->query_temp("pending/exercising")
		|| me->query_temp("doing_xiudao"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中修道，找死啊？！\n");

	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 50 )
		return notify_fail("你现在神智不清，再炼恐怕要走火入魔！\n");

	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 50 )
		return notify_fail("你现在体力不够，再练就要累死了！\n");

	pot_gain = xiudao_lvl/10 + random(3);
	busy_time = random(6000)/pot_gain/60+2;
	pot_gain = 1 + random(pot_gain*3);
	busy_time *= pot_gain;
	pot_gain += (int)me->query("obstacle/number")*pot_gain/2/obstacle_size;
        pot_gain = random(pot_gain*60);
        if (me->query("food") + me->query("water") < 20) busy_time *= 2;
	message_vision(HIY "$N闭上眼睛，盘膝坐下，嘴里默默念念不知在说些什么。\n" NOR, me);
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

	message_vision(HIY "$N缓缓睁开眼睛，长舒一口气站了起来。\n" NOR, me);

               if( (int)me->query("potential") < 10400 ){
        tell_object(me, HIC "你的道行增加了" + chinese_number(pot_gain*6) + "时辰！\n" NOR);
        tell_object(me, HIC "你的潜能增加了" + chinese_number(pot_gain/5) + "点！\n" NOR);
                me->add("daoxing", pot_gain);
                me->add("potential", pot_gain/5);
   return;
}
        tell_object(me, HIC "你的道行增加了" + chinese_number(pot_gain*6) + "时辰！\n" NOR);
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
指令格式 : xiudao

静坐修炼以提高道行。
HELP
        );
        return 1;
}
