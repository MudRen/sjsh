
// zhutian-bu.c ���컯��
// modified by Venus Oct.1997
// written by That

inherit SKILL;
#include <ansi.h>

string *dodge_msg = ({
	"ֻ��$nһ��"+BLINK""+HIB"����ع���"NOR"�������ڿգ�˫�����ϣ���ֱ���������࣬�����$N��һ�С�\n",
	"$n������ת��һʽ"+BLINK""+HIC"�����ͷ��"NOR"ͷ��ǰͦ�������ո���ٿ����һ��Ų�������ߣ��ܹ�����һ�С�\n",
	"$n˫��ץ�أ�����΢�Σ�һ��"+BLINK""+HIM"��ӥצ�ɡ�"NOR"�о����յرܿ���$N��һ�С�\n"
	"����$n����Ʈ����һʽ"+BLINK""+HIW"���������"NOR"������һ�ݣ����ѱܿ���\n",
	"$nһ��"+BLINK""+HIR"����������"NOR"������ݳ�����֮Զ���ܿ���$N���������ƣ��������۽�$N���ԡ�\n",
	"$nʹ��"+BLINK""+HIG"�����¿ۡ�"NOR"��˫���繳��һ��ƮȻ�ݳ��������ŵء�\n"
});

int valid_enable(string usage)
{
	return (usage=="dodge");
}

int valid_learn(object me)
{
	if( (int)me->query("max_force") < 0 )
		return notify_fail("�������������û�а취ѧ���컯����\n");

	return 1;
}

string query_dodge_msg(string limb)
{
	return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30)
		return notify_fail("������̫�����������컯������ˤ����\n");
	if((int)me->query("force") < 3 )
		return notify_fail("�������������������ܳ˷����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	return 1;
}

