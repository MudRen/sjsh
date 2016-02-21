
//huifeng-jian.c �ط������

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "����ɺ�",
	"action" : "$N���⽣â������һ��"+BLINK""+HIW"������ɺ硹"NOR"������$w�����´󿪴��أ�
һ����������$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "��ӵ�к",
	"action" : "$N����Ȧת��һ��"+BLINK""+HIY"����ӵ�к��"NOR"������$wƽչ�´̣�һ�����Ữ
��$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "���ھ���",
	"action" : "$N��������������������������$wʹ��һʽ"+BLINK""+HIY"�����ھ��졹"NOR"����$n��
$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "��������",
	"action" : "$N������ָ��������ת��һ��"+BLINK""+HIB"���������졹"NOR"ֱȡ$n��$l",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "��������ѡ�",
	"action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+BLINK""+HIC"��������ѡ�"NOR"���������
����$n��$l",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "����ժ��",
	"action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"+BLINK""+HIW"������ժ�ǡ�"NOR"ԾԾ����Ʈ��$n��$l",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "���ո���",
	"action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+BLINK""+HIC"�����ո��ơ�"NOR"������
����֮�ƣ�����$n��$l",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "����"
]),
([	  "name":   "���Ƽ���",
	"action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+BLINK""+HIG"�����Ƽ��ա�"NOR"����
���ϴ���$n��$l",
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
		return notify_fail("�������������û�а취�����ὣ��\n");

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
		return notify_fail("�����������������û�а취��ϰ���ὣ��\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�����ὣ��\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("emei") + "/tianji-sword/" + func;
}

