//����ҽ�� by koker@sjsh 2001
/*������V2.0�汾*/
 
inherit SKILL;
#include <ansi.h>

string exert_function_file(string func)
{
        return "/daemon/class/jineng/medical/" + func;
//ҽ���ǿ����ƶ��������˵ġ�
}

int valid_learn(object me)
{
   object ob;
//ÿ����һ���ȼ�����ѧ4��ҽ�����ܡ�
   if ((int)me->query_skill("medical", 1) > ( (int)me->query("level")*4))
    return notify_fail(""HIW"��ĵȼ�����,���ܼ���ѧϰҽ�����������ˡ�"NOR"\n");

   return 1;
}



