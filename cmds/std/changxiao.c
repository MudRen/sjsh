// shout.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
                if(me->query("family/family_name") == "普通百姓" )
		return notify_fail("你是普通百姓，哪有内力长啸！\n");

        if((int)me->query_skill("force", 1) < 200)
                return notify_fail("你的的内力修为还不够高深，无法长啸！\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，无法长啸！\n");

        if (!arg) return notify_fail("你想要大叫什么？\n");
          shout(HIW + me->name() +  "纵声长啸："HIR"" + arg + "\n" NOR);
          write(HIW "你纵声长啸："HIR""+ arg + "\n" NOR);
        me->receive_damage("sen", 100);
        return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : shout <讯息>
 
这个指令让你将 <讯息> 传送出去, 所有正在游戏中的人都
会听见你的话.
 
see also : tune
HELP
    );
    return 1;
}
 


