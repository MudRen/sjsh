
// jinding-zhang.c ������
// Oct. 9 1997 by That
inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "skill_name" : "������̩" ,
	"action" : "$N����΢�Σ�һ��"+BLINK""+HIY"��������̩��"NOR"�����������$nֻ����һ��ů��Ϯ��$l",
	"force" : 100,
	"dodge" : 10,
	"damage_type" : "����",
	"lvl"   : 0,
]),
([	  "skill_name" : "��������" ,
	"action" : "$N˫�ֱ�ã���ָ�ᵯ��һ��"+BLINK""+HIG"���������项"NOR"��������·������ʮ����ץ��$n��$l",
	"force" : 120,
	"dodge" : 10,
	"damage_type" : "����",
	"lvl"   : 11,
]),
([	  "skill_name" : "�����" ,
	"action" : "$N����ǰ��������ٿ��������ͷ�һ��"+BLINK""+HIM"������ơ�"NOR"����ץ��$n��$l",
	"force" : 150,
	"dodge" : 15,
	"damage_type" : "����",
	"lvl"   : 22,
]),
([	  "skill_name" : "������ɳ" ,
	"action" : "$N����Ȧת�����$n�����֣������Ƴ������������Ļ���һ��"+BLINK""+HIW"��������ɳ��"NOR"���͵ػ���$n���°�",
	"force" : 200,
	"dodge" : 25,
	"damage_type" : "����",
	"lvl"   : 33,
]),
([	  "skill_name" : "�׶�����" ,
	"action" : "$N�������ף�һ�����ȣ���$nһ㶼䣬����һ��"+BLINK""+HIR"���׶�������"NOR"��ֱ��$n��$l",
	"force" : 100,
	"dodge" : 10,
	"damage_type" : "����",
	"lvl"   : 44,
]),
([	  "skill_name" : "�𶥷��" ,
	"action" : "$N˫��ƽ����ȭ����¶΢Ц��$n��㱼俴��$N����Ϊ�������$N���������һ��"+BLINK""+HIY"���𶥷�⡹"NOR"��֪��������ʵ���Ʒ��Ѿ�Ϯ��",
	"force" : 200,
	"dodge" : 15,
	"damage_type" : "����",
	"lvl"   : 55,
]),
([	  "skill_name" : "���Ľ�ħ" ,
	"action" : "$Nһ������ׯ�ϣ�ʹ��"+BLINK""+HIM"�����Ľ�ħ��"NOR"��������磬����$nƯ�Ʋ���",
	"force" : 230,
	"parry" : 20,
	"dodge" : 20,
	"damage_type" : "����",
	"lvl"   : 66,
]),
([	  "skill_name" : "����˻�" ,
	"action" : "$Nȫ�����ߣ�˫�ۼ��裬��Ϊ�����Ӱ��һ��"+BLINK""+HIC"������˻ġ�"NOR"����ǵ�Ϯ��$nȫ�������Ѩ",
	"force" : 300,
	"parry" : 5,
	"dodge" : 30,
	"damage_type" : "����",
	"lvl"   : 77,
]),

});

int valid_learn(object me)
{
	
	if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
		return notify_fail("�������Ʊ�����֡�\n");
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
	if( (int)me->query("sen") < 30)
		return notify_fail("��ľ����޷������ˣ���Ϣһ�������ɡ�\n");
	if( (int)me->query("kee") < 30 )
		return notify_fail("����������������Ϣһ�������ɡ�\n");
	if( (int)me->query("force") < 10 )
		return notify_fail("������������ˡ�\n");

	me->receive_damage("kee", 20);
        me->add("force", -5);

	return 1;
}

string perform_action_file(string action)
{
return CLASS_D("emei") +"/jinding-zhang/" + action;
}


