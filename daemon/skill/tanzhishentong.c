//����Ϭһָ��lingxiyizhi.c
// created 17-06-2001 ����Ʈ(piao)
#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":
"$N���һ����ʮָ���·ַɣ�һ��"+BLINK""+HIG"�������m���䡹"NOR"��˫ֱָȡ$n��$l",
		"dodge":		-10,
		"parry":		-10,
		"force":		150,
		"damage_type":		"����",
		"weapon" :		"������ָ",
	]),
           ([	            "action":
"$Nʮָ���������ʵ��һ��"+BLINK""+HIM"��Ω��׽��ס��"NOR"��ǰ�����ң�˲Ϣ����$n����������",
		"dodge":		-20,
		"parry":		-20,
		"force":		150,
		"damage_type":		"����",
		"weapon" :		"������ָ",
	]),
	([	"action":
"$N����������ǰ��һʽ"+BLINK""+HIR"���������P�e��"NOR"������ʳָ��סĴָ���������$nһ��",
		"dodge":		10,
		"parry":		-20,
		"force":		100,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),
	([	"action":
"$N˫�ƻ�ָ��ָ�д��ƣ�˫�����ƣ�һ��"+BLINK""+HIW"���wȥ���@����"NOR"��һ����ɽ������������ֱ��$n$l",
		"dodge":		-10,
		"parry":		-20,
		"force":		120,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),
	([	"action":
"$Nһ��"+BLINK""+HIC"�������m���䡹"NOR"������һȭ���������ƻ�ָ��һ��һָ��ջ���$n��$l",
		"dodge":		10,
		"parry":		-10,
		"force":		100,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),
            ([	"action":
"$NͻȻ���м�ת��һ��"+BLINK""+HIY"��Ω��׽��ס��"NOR"��ʮָ���裬��ʱ֮�佫$n����˷�����ס��",
		"dodge":		0,
		"parry":		-20,
		"force":		150,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),
            ([	"action":
"$Nһʽ"+BLINK""+HIC"���������P�e��"NOR"����ָ���У�һ����������ٱ�ĵ�����������$n��$l��ȥ",
		"dodge":		10,
		"parry":		-30,
		"force":		180,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),
      ([	"action":
"�����������죬һ����͵�������$N��ָӿ��������һ��"+BLINK""+HIB"���wȥ���@����"NOR"����������$n$l",
		"dodge":		10,
		"parry":		-30,
		"force":		180,
		"damage_type":		"����",
		"weapon":		"������ָ",
	]),

});

int valid_learn(object me)
{
		if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("��Ϭһָ���������ϰ��\n");
	return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query_skill("unarmed",1) < (int)me->query_skill("lingxiyizhi",1)/2)
                return notify_fail("����˻��񶷻�������տ���޷�����������Ϭһָ��\n");

	if( (int)me->query("sen") < 50)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");

	if( (int)me->query("kee") < 50 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");

	if( (int)me->query("force") < 20 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -20);

	return 1;
}

string perform_action_file(string func)
{
	return CLASS_D("youxia") + "/tanzhishentong/" + func;
}
