// emeiforce.c �����ķ�
inherit FORCE;
#include <ansi.h>

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }

int practice_skill(object me)
{
        return
notify_fail("�����ķ�ֻ����ѧ�ģ����Ǵ�����(exert)�����������ȡ�\n");
}

void skill_improved(object me)
{
	switch (me->query_skill("linji-zhuang",1))
	{
		  case 30:
		   tell_object(me, HIG "�������������! \n" NOR );
		   break;
		  case 60:
		   tell_object(me, HIG "��֮����������! \n" NOR );
		   break;
		  case 90:
		   tell_object(me, HIG "��������������! \n" NOR );
		   break;
		  case 120:
		   tell_object(me, HIG "�������������! \n" NOR );
		   break;
		  case 150:
		   tell_object(me, HIG "���С��������! \n" NOR );
		   break;
		  case 180:
		   tell_object(me, HIG "����ڤ��������! \n" NOR );
		   break;

	}
	return;
}

string exert_function_file(string func)
{
        return CLASS_D("emei") + "/emeiforce/" + func;
}

