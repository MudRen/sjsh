

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "��ǹ���ѩ",
	"action" : "$Nʹһʽ"+BLINK""+HIW"����ǹ���ѩ��"NOR"������$w��ʱ�ó�,\n"
"���⽣Ӱ������$n��$l��",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "�����Ʊ���",
	"action" : "$Nʹһʽ"+BLINK""+CYN"�������Ʊ��ǡ�"NOR"�������Ծ������$w�ڰ�������£�\n"
"����һ����ɫ��������$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "�󶷴�����",
	"action" : "$Nʹһʽ"+BLINK""+HIG"���󶷴����"NOR"��΢΢һ��ת��\n"
"����$wȴ�������´���������$n��$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "�����̿�",
	"action" : "$Nʹһʽ"+BLINK""+HIR"�������̿ա�"NOR"��һƬ����֮����\n"
"����$w���ּ�����������ৡ���һ����$n��$l��ȥ��",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "ʱ�������",
	"action" : "$Nʹһʽ"+BLINK""+HIW"��ʱ���������"NOR"������������£�\n"
"����$w��ƥ��������$n��$l",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������ɣ",
	"action" : "$Nʹһʽ"+BLINK""+HIY"��������ɣ��"NOR"��һ������\n"
"����$w����б������ֱָ$n��$l",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "����������",
	"action" : "$Nʹһʽ"+BLINK""+HIC"�����������꡻"NOR"������ͻ�䣬\n"
"��������$w�籩�������ĵ���$n���ؿڴ�ȥ��",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "����"
]),
([	  "name":   "ɱ�����ڷ�",
	"action" : "$Nʹһʽ"+BLINK""+HIR"��ɱ�����ڷ���"NOR"����¶ɱ����\n"
"����$w�Ӵ�����˷�����$n��$l",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "����"
]),

([	  "name":   "���������",
	"action" : "$Nʹһʽ"+BLINK""+HIB"����������硻"NOR"����ؼ���һ�����ֳ�ǰ������\n"
"����$w��Ϊ�⻡��$n��$l��ȥ��",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "����ƶ�˪",
	"action" : "$Nʹһʽ"+BLINK""+HIW"������ƶ�˪��"NOR"������һ�Σ����Ӷ��ϣ�\n"
"����$w����һ������׼$n��$l����������",
	"force" : 150,
	"dodge" : 35,
	"damage" : 400,
	"lvl" : 0,
	"damage_type" : "����"
]),


});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취������һ����\n");

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

int valid_effect(object me, object weapon, string name, int skill)
{
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ����һ����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�����һ����\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("kunlun") + "/huntian-jian/" + func;
}

