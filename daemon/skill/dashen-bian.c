inherit SKILL;
#include <ansi.h>
mapping *action = ({
	([	"name":			"��������������",
		"action":
"$N������ħﵺ���һɨ��һ��"+BLINK""+HIG"������������������"NOR"һƬ��Ӱɨ��$n",
		"dodge":		-5,
		"parry":		5,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"������ɧ��Ұ��",
		"action":
"ֻ��$N������ת��ʹ��"+BLINK""+HIW"��������ɧ��Ұ�ˡ�"NOR"��һ������г����������$n��$l",
		"dodge":		-5,
		"parry":		-15,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"Ϫδ�������",
		"action":
"$N��������ħ�һ����ֻ�������Ӱ��������ա�\n"
"��һ��"+BLINK""+HIM"��Ϫδ������Ρ�"NOR" ֻ����$n�ۻ����ң����ﻹ���м�",
		"dodge":		-15,
		"parry":		-5,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"name":			"μˮ��֪������",
		"action":
"$nֻ������ǰһ����$N����Ȼ������$n���������ħ�ֱָ$n�ĺ��ģ� \n"
"����һʽ"+BLINK""+HIC"��μˮ��֪�����롹"NOR"",
		"dodge":		10,
		"parry":		-10,
		"damage":		20,
		"damage_type":		"����"
	]),
	([	"name":			"��ʷ��ƿ���ҵ",
		"action":
"$N�������ܣ�һʽ"+BLINK""+HIY"����ʷ��ƿ���ҵ��"NOR"���������У� ���ƴ�����\n"
"������ħ�ֱָ$n��������",
		"dodge":		-10,
		"parry":		0,
		"damage":		25,
		"damage_type":		"����"
	]),
	([	"name":			"�����������׾",
		"action":
"$N����������һʽ"+BLINK""+HIR"�������������׾��"NOR"���������Ӱ, \n"
"$nֻ���������ڹ�Ϯ������֪���������",
		"dodge":		-5,
		"parry":		-5,
		"damage":		15,
		"damage_type":		"����"
	]),
});
int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 100 )
		return notify_fail("���������Ϊ���������ѧ����޷���\n");
	if (!(ob = me->query_temp("weapon"))
	   || (string)ob->query("skill_type") != "mace" )
		return notify_fail("����û�б�����ô����\n");
	return 1;
}
	
int practice_skill(object me)
{
	if ((int)me->query("kee") < 30)
		return notify_fail("������Ƿ�ѣ�ǿ������޷��к����档\n");
	if ((int)me->query("force") < 5)
		return notify_fail("���������㣬ǿ������޷����߻���ħ��Σ�ա�\n");
	me->receive_damage("kee", 30);
	me->add("force", -5);
	message_vision("ֻ��һ�ź�Ӱ���߳�$N��ԭ�����������޷���\n", me);
	return 1;
}

int valid_enable(string usage)
{
	return usage=="mace"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}
string perform_action_file(string action)
{
        return CLASS_D("kunlun") + "/dashen-bian/" + action;
}
