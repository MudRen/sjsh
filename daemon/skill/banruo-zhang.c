//banruo-zhang.c �������ơ�weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
        ([      "action":
"$Nǰ���߳������Ƚż��أ�һʽ"+BLINK""+HIW"����ճ�����"NOR+"������ֱ��������$n����������·",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "����",
        "skill_name" : "��ճ���"
]),
        ([      "action":
"$N���ƻ�һ��Բ��һʽ"+BLINK""+HIW"��������ա�"NOR+"������б������������$n����ǰ��Ѩ",
                "dodge":                -25,
                "parry":                -25,
	    "force":		70,
                "damage_type":  "����",
        "skill_name" : "�������"
]),
        ([      "action":
"$Nʹһʽ"+BLINK""+HIW"���ƶ����롹"NOR+"�����������������ɺ����һ��˦����ն��$n��$l",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "����",
        "skill_name" : "�ƶ�����"
]),
        ([      "action":
"$N���ƻ��أ���ȭ�����󷢣�һʽ"+BLINK""+HIW"������������"NOR+"����������$n��$l",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "����",
        "skill_name" : "��������"
]),
        ([      "action":
"$Nʹһʽ"+BLINK""+HIW"������ء�"NOR+"��ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
                "dodge":                -5,
                "parry":                -5,
	    "force":		90,
                "damage_type":  "����",
        "skill_name" : "�����"
]),
        ([      "action":
"$N���Ʊ�������һ������һʽ"+BLINK""+HIW"�����б��¡�"NOR+"��˫�Ƽ�����$n�ļ�ͷ",
                "dodge":                5,
                "parry":                5,
	    "force":		60,
                "damage_type":  "����",
        "skill_name" : "���б���"
]),
        ([      "action":
"$N���ϸ߸�Ծ��һʽ"+BLINK""+HIW"����ɽ��ˮ��"NOR+"���Ӹ����£���������$n��ȫ��",
                "dodge":                5,
                "parry":                5,
	    "force":		80,
                "damage_type":  "����",
        "skill_name" : "��ɽ��ˮ"
]),
        ([      "action":
"$Nʹһʽ"+BLINK""+HIW"��ժ�ǻ�����"NOR+"������������˫�����֣�һ������$n��$l�ȥ",
                "dodge":                -5,
                "parry":                -5,
	    "force":		80,
                "damage_type":  "����",
        "skill_name" : "ժ�ǻ���"
]),
              ([      "action":
"$N�������»��أ�һʽ"+BLINK""+HIW"������������"NOR+"����Ȼ��Ϊ�������꣬����$n",
                "dodge":                -5,
                "parry":                -5,
	    "force":		60,
                "damage_type":  "����",
        "skill_name" : "��������"
]),
              ([      "action":
"$Nһʽ"+BLINK""+HIW"����շ�ħ��"NOR+"��˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ�����˰���ӿ����",
                "dodge":                -5,
                "parry":                -5,
	    "force":		100,
                "damage_type":  "����",
       "skill_name" : "��շ�ħ" 
]),

});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("�������Ʊ�����֡�\n");
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	if( (int)me->query("sen") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 30);
	me->add("force", -10);

	return 1;
}

string perform_action_file(string func)
{
return CLASS_D("shaolin") + "/banruo-zhang/" + func;
}
