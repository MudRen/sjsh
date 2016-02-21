//banruo-zhang.c �������ơ�weiqi
//menpai skill(non manpai NPCs can also use it)

inherit SKILL;
#include <ansi.h>;

mapping *action = ({
([      "action" : "$N˫����Σ�����͵ط���һʽ"+BLINK""+HIW"��������ӿ��"NOR+"���ż�ζ�������$n��ƨ��",
        "parry" : -10,
        "dodge" : -15,
        "damage_type" : "����",
        "skill_name" : "������ӿ"
]),
([      "action" : "$N��Ŷٵأ���ת�����������ߣ�ֻһɲ�Ǽ�һ�����ҽ�һʽ
"+BLINK""+HIB"���չ�������"NOR+"������$n��$l",
        "parry" : -20,
        "dodge" : -10,
        "damage_type" : "����",
        "skill_name" : "�չ�����"
]),
([      "action" : "$N����һ��������Ť��ס$n�����֣��ҽ�ͬʱ�߳���������׼��һ
ʽ"+BLINK""+HIY"����Ԩ���ԡ�"NOR+"�����е�$n���ؿ�",
        "parry" : -25,
        "dodge" : 5,
        "damage_type" : "����",
        "skill_name" : "��Ԩ����"
]),
([      "action" : "$NͻȻԾ��˫������Ȧת��һʽ"+BLINK""+HIG"�������Ҷ��"NOR+"������糾������$n��ȫ��",
        "parry" : 10,
        "dodge" : -25,
        "damage_type" : "����",
        "skill_name" : "�����Ҷ"
]),
([      "action" : "$N���ֻ��أ�˫�Ž�������һʽ"+BLINK""+HIC"����ɨ���ơ�"NOR+"���ŽŲ���$n����������",
        "parry" : 10,
        "dodge" : -10,
        "damage_type" : "����",
        "skill_name" : "��ɨ����"
]),
([      "action" : "$NͻȻ����ȴ�����ˣ�һ��ǰ�շ����ҽ����϶���һʽ"+BLINK""+HIR"������׹�ء�"NOR+"����$n������ֱ������",
        "parry" : -20,
        "dodge" : 5,
        "damage_type" : "����",
        "skill_name" : "����׹��"
]),
([      "action" : "$Nʹһʽ"+BLINK""+HIW"��˷�紵ѩ��"NOR+"��ȫ��ͻȻ������ת��˫���ǰ����Ѹ��
�޼�����$n���ؿ�",
        "parry" : -20,
        "dodge" : -10,
        "damage_type" : "����",
        "skill_name" : "˷�紵ѩ"
]),
([      "action" : "$N����Ծ�𣬿������������һ�����ˣ�һʽ"+BLINK""+HIR"���׶����졹"NOR+"��˫��
�����������$n��$l",
        "parry" : 20,
        "dodge" : 5,
        "damage_type" : "����",
        "skill_name" : "�׶�����"
]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon")
)
                return notify_fail("����������ȱ�����֡�\n");
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
return CLASS_D("shaolin") + "/jingang-leg/" + func;
}
