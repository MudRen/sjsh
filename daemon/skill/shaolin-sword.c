
// shaolin-sword.c�����ַ�ħ����
//for ��ʿ NPCs, if going to be used by players, need refine. 

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$Nһ��",
        "ֻ��$N��������Ծ��,һ��",
        "$Nʹ��",
        "$NƮȻ������һʽ",
        "$N��������Ծ��,�������ּ�ת��һ��",
        "$N����������һ��",
});

mapping *action = ({
	([	"action":
"$N�ս�����$wһ��"+BLINK""+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"����ȥ���硹"NOR"����$n��$l,
$nȴ�޷��ҵ�$N����Ӱ,���д�",
		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"����"
	]),
	([	"action":
"$Nһ��"+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"�������޹⡹"NOR"������$w���´̳���ֱ��$n��ȥ,
�·𽣹���ס��̫��,$n��ǰһ��",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":
"$N����һЦ����ǰ����һ��������$wʹ��"+BLINK""+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"���������"NOR"ֱ��$n�ĺ�,
$n���ŵ����˼���,��ʱ���޻���֮��",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N���һ����ʹ��"+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"���ľ���ˮ��"NOR"����$wֱ��$n��Ҫ��,
$N����侲��$n����������թ",
		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"ֻ��$N�������е�$w��ʹ��"+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"��������ա�"NOR"�����ֱ��$n,
�����ס��$n���۾�,�ɼ���������֮��",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"����"
	]),
        ([      "action":
"$N�������е�$w��ʹ��"+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"������Ҷ�䡹"NOR"��������ֱ��$n,
���ܶ�ʱ�����˿��,��Χ����Ҷ�뽣������һ������м��е�$n",
                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "����"
        ]),
	([      "action":
"$Nʹ��"+BLK"����Ӱ������"NOR"�е�"+BLINK""+HIW"������������"NOR"������$w�������һ����˸������
����û��Σ��,ͻȻ������Ϊһ������$n",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "����"
        ]),
           ([      "action":
"$N����ʹ��"+BLK"����Ӱ������"NOR"֮����"+BLINK""+HIW"����Ӱ���١�"NOR"������$w�����һ������ǵصĴ���$n,
$nʹ����������ѵ�����,Ψ�г������",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		20,
                "damage_type":  "����"
        ]),
            ([      "action":
"$Nʹ��"+BLK"����Ӱ������"NOR"֮���վ���"+BLINK""+HIW"��������ˮ��"NOR",����$w��������һ�����$n ,
$n�·𿴵�һ��������ˮ����,��ʱ��֪����",
                "dodge":                -25,
                "parry":                -10,
                "damage":     		30,
                "damage_type":  "����"
        ]),	
       ([	   "action":
"$Nʹһʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"��������Ե����"NOR"������$w����΢�񣬻ó�һ���������$n��$l",

		"dodge":		-5,
                "parry":                -10,
		"damage":		10,
		"damage_type":	"����"
	]),
	([	"action":
"$N����ǰ��ʹ��"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"����ȥ�����С�"NOR"�������������ޣ�$w��������$n��$l��ȥ",
		"dodge":		-25,
                "parry":                -5,
		"damage":		20,
		"damage_type":	"����"
	]),
	([	"action":
"$N����һЦ��һʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"��������ɣԶ��"NOR"������Ʈ�������˷�����������$wңҡָ��$n��$l",
		"dodge":		-10,
                "parry":                -15,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N��������Ծ��һʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"���ֻط����᡹"NOR"���������ּ�ת������ն��$n��$l",

		"dodge":		-20,
                "parry":                -5,
		"damage":		15,
		"damage_type":	"����"
	]),
	([	"action":
"$N����$w�й�ֱ����һʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"��ˮ��ͨ���š�"NOR"��������Ϣ�ض�׼$n��$l�̳�һ��",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":	"����"
	]),
        ([      "action":
"$N����$wбָ���죬��â���£�һʽ"+BLK"����Ħ������"NOR"�е�"+BLINK""+HIC"��������������"NOR"����׼$n��$lбб����",

                "dodge":                -25,
                "parry":                -5,
                "damage":      		20, 
                "damage_type":  "����"
        ]),
	([      "action":
"$N��ָ�����㣬����$w�Ƴ�����ѩ����â��һʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"��ǧ��һέȥ��"NOR"����$n��$l", 
               "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "����"
        ]),
           ([      "action":
"$N���Ƶ�����һʽ"+BLK"����Ħ������"NOR"��"+BLINK""+HIC"�����Ķ�������"NOR"��$w�Ի���Ծ�����缲�������$n���ؿ�",
                "dodge":                -5,
                "parry":                -10,
                "damage":     		10,
                "damage_type":  "����"
        ]),
          ([      "action":
"$N�ս�����,��"+BLK"����Ӱ������"NOR"��"+BLK"����Ħ������"NOR"��Ȼһ��,ʹ��˫����һ"+BLINK""+HIY"���Ⱥ��նɡ�"NOR"ʽ��
$w�������������Ծ����ֱ��$n���ؿڴ��롣",
                "dodge":                -35,
                "parry":                -10,
                "damage":     		40,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취�����ַ�ħ����\n");

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
		return notify_fail("�����������������û�а취��ϰ���ַ�ħ����\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�����ַ�ħ����\n");
	return 1;
}
string perform_action_file(string action)
{
  return CLASS_D("shaolin") + "/shaolin-sword/" + action;
}
