
//huifeng-jian.c �ط������

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "�һ�����",
	"action" : "$N���⽣â������һ��"+BLINK""+HIR"���һ����ơ�"NOR"������$w�����´󿪴��أ�
һ����������$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "�����ķ�",
	"action" : "$N����Ȧת��һ��"+BLINK""+HIB"�������ķ���"NOR"������$wƽչ�´̣�һ�����Ữ
��$n��$l",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������",
	"action" : "$N��������������������������$wʹ��һʽ"+BLINK""+HIB"�������ơ�"NOR"����$n��
$l",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "����ޱ�",
	"action" : "$N������ָ��������ת��һ��"+BLINK""+HIR"������ޱߡ�"NOR"ֱȡ$n��$l",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������",
	"action" : "$N��â���£��������ߣ�����$wʹ��һʽ"+BLINK""+HIM"�������á�"NOR"���������
����$n��$l",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "ף�ڻ���",
	"action" : "$N�����ƽ���������ʵ��׷ɣ��ó�����ǹ⣬����$wʹ��һʽ
"+BLINK""+HIR"��ף�ڻ��桹"NOR"ԾԾ����Ʈ��$n��$l",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "���羪��",
	"action" : "$N�ӽ��ֻ�����������ǰԾ��������$wһʽ"+BLINK""+HIY"�����羪�硹"NOR"������
����֮�ƣ�����$n��$l",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "����"
]),
([	  "name":   "��������",
	"action" : "$N�˲������ֽ�ָ��ת������һŤ������$wһ��"+BLINK""+HIG"������������"NOR"����
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
		return notify_fail("�������������û�а취�����׽���\n");

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
string perform_action_file(string func)
{
return CLASS_D("emei") + "/leiyan-sword/" + func;
}
int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30
	||	(int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ���׽���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�����׽���\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
