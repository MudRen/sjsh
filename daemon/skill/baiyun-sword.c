// baiyun-sword.c ���ƽ���
//created 17-06-2001 ����Ʈ(piao)

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nʹһ��"+BLINK""+HIB"�����·ת��"NOR""NOR"������$w��һ�����߰����$n��$l",
		"dodge":		0,
		"damage":		100,
		"damage_type":	"����"
	]),
	([	"action":		"$Nʹ�����ƽ����е�"+BLINK""+HIM"����ɽ���"NOR"���������ն��$n��$l",
		"dodge":		0,
		"damage":		90,
		"damage_type":	"����"
	]),
	([	"action":		"$Nһ��"+BLINK""+HIW"��������С�"NOR"�����ζ�Ȼ�������ߣ�����$wն��$n��$l",
		"dodge":		0,
		"damage":		140,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w�й�ֱ����һʽ"+BLINK""+HIR"�����ն�����"NOR"��׼$n��$l�̳�һ��",
              "damage":		60,
		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N����һԾ������$wһ��"+BLINK""+HIY"�����к�ء�"NOR"��׼$n��$lбб�̳�һ��",
              "damage":		60,
   		"dodge":		0,
		"damage_type":	"����"
	]),
	([	"action":		"$N��$wƾ��һָ��һ��"+BLINK""+HIC"��ͯ����·��"NOR"����$n��$l",
		"dodge":		0,
		"damage":		80,
		"damage_type":	"����"
	]),
	([	"action":		"$N����$w����һ�֣�ʹһ��"+BLINK""+HIG"������������"NOR"���ֶ�׼$n$lһ����ȥ",
		"dodge":		0,
		"damage":		60,
		"damage_type":	"����"
	]),
	([	"action":		"$N�ὣ��ǰ������һת����$wʹһ��"+BLINK""+HIW"���չ���硹"NOR"����һ���⻡ն��$n��$l",
		"dodge":		0,
		"damage":		100,
		"damage_type":	"����"
	]),
            ([      "action":           "$N�ὣ��ǰ������һת����$wʹһ��"+BLINK""+HIW"�������ܲ���"NOR"����һ���⻡����$n��$l",
                "dodge":           -10,
                "damage":          150,
                "damage_type":  "����"
        ]),



});


int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ƽ�����\n");

		if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ���ƽ�����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ����ƽ�����\n");
	return 1;
}

string perform_action_file(string action)
{
	return CLASS_D("youxia") + "/baiyun-sword/" + action;
}

int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С�������졹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�������ѩ�������е�$v��������ѩӰ��������$N��$w��\n",
        "$n���е�$vһ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
});
