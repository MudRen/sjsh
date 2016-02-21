

inherit SKILL;
#include <ansi.h>

mapping *action = ({
([	  "name":   "��������������",
	"action" : "$N�����ǰ���ŵ���������������ͻ��ǰ�̣���ת�����
ʹ��һʽ"+BLINK""+HIW"���������������ס�"NOR"��������ƥ����й��$n",
	"force" : 120,
	"dodge" : 20,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "�˵³���������",
	"action" : "$N����̧�ۣ�����ǰ����Ϸ������ͦ����ƽ��������ǰ������������ʹ��
һʽ"+BLINK""+HIM"���˵³��������桹"NOR"����$n",
	"force" : 120,
	"dodge" : 20,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������䷨�ſ�",
	"action" : "$N���β�������ǰ�������������ϱ���һ��"+BLINK""+HIR"��������䷨�ſ���"NOR"��
������������ǰ�·��̣�һ��ָ��$n",
	"force" : 140,
	"dodge" : 15,
	"damage" : 350,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "ֻ������Ӣ��",
	"action" : "$N�����˲������ֽ�ָ��ת������������һ��"+BLINK""+HIW"��ֻ������Ӣ����"NOR"����������ָ��$n",
	"force" : 150,
	"dodge" : 15,
	"damage" : 280,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "����ǰ�̽�ʥ̥",
	"action" : "$N�鲽�������ὣ�ؽ��������ϱ���һ��"+BLINK""+HIG"������ǰ�̽�ʥ̥��"NOR"ֱȡ$n",
	"force" : 130,
	"dodge" : 25,
	"damage" : 300,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������������̦",
	"action" : "$N���ϲ����������أ�����������һʽ"+BLINK""+HIY"��������������̦��"NOR"������Բ�󣬴���$n",
	"force" : 120,
	"dodge" : 25,
	"damage" : 320,
	"lvl" : 0,
	"damage_type" : "����"
]),
([	  "name":   "������������",
	"action" : "$Nƽ��бϴ����Բ��ֱ��˫�Ž��满������������������ʹ��һʽ"+BLINK""+HIB"����������������"NOR"��
����������ת�������಻������$n",
	"force" : 110,
	"dodge" : 15,
	"lvl" : 0,
	"damage" : 400,
	"damage_type" : "����"
]),
([	  "name":   "�������ӹ�",
	"action" : "$Nʹһʽ"+BLINK""+HIC"���������ӹ桹"NOR"���������������͡���һ��б������գ�
�漴���¡��ৡ����£�����һ�����֣���$n��$l��ȥ",
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
		return notify_fail("�������������û�а취���⹳������\n");

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
		return notify_fail("�����������������û�а취��ϰ�⹳������\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ���⹳������\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}
string perform_action_file(string func)
{
return CLASS_D("kunlun") + "/wugou-jian/" + func;
}

