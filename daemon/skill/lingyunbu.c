#include <ansi.h>
inherit SKILL;

string *dodge_msg = ({
"$n����΢�Σ��о����յرܿ���$N��һ�С�\n"
"$n�������һ��"+BLINK""+HIM"����ռ�Ƭ��ϼ��"NOR"�����䷭�ɣ����$N��һ�С�\n",
"����$n����Ʈ��������һ�ݣ����ѱܿ���\n",
"ֻ��$n�������һ����һ��"+BLINK""+HIR"������һ���ζ��"NOR"���󵴶�������һ�ԡ�\n",
"$n������ת��ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
"$nһ��"+BLINK""+HIC"����ˮ�ر����¡�"NOR"��$Nֻ����ǰһ����������$n����Ӱ��\n",
"����$n����һ�ã�$N��һ�����˸��ա�\n",
"$nһ��"+BLINK""+HIG"�����������һ���"NOR"������΢�Σ��о����յرܿ���$N��һ�С�\n",
"ȴ��$n�㲻��أ����Դܿ����ߣ����˿�ȥ��\n",
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취�����Ʋ���\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("��������������������������Ʋ���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

