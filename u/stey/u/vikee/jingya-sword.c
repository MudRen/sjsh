//jingya-sword. �����Ž�����
//created by vikee
//2000-12-5 17:40

/*
���Ž���    dodge  -10    parry  -10    damage  15
�˽���Ϊ��̫����ʫ����ʱ���������ʽ����ϰ����Ѫ��Ϊ�����洦��
*/

inherit SKILL;

mapping *action = ({
	([	"name":			"��",
		"action":
"$Nһ�����е�$w�����г�ŵ������ѣ����������졣˲��̳�������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -20,
		"damage":		5,
		"damage_type":		"����"
	]),
	
	([	"name":                 "��",
		"action":
"$Nһ������$n��$n��æ���Ա�һ����\n"
"����$Nһ�˾������������������������ǧ�꣬�����غ�ͨ���̡����е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N����$w�������������⻷��һ����������$n��ǰ̤��һ���������������������ȥ��������������$N���ֽ�ָ�Ѵ���$n��$l",
		"dodge":		-20,
                "parry":                -20,
		"damage":		15,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$Nһת������$n����ͷ��������ͷ�����£���ͷ˼���硣����$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		10,
		"damage_type":		"����"
	]),
	([	"name":                 "��",
		"action":
"$N�������е�$w����Х���裺����ֱ����ǧ�ߣ�������������졣���϶��£�����$n��$l",
		"dodge":		0,
                "parry":                -10,
		"damage":		25,
		"damage_type":		"����"
	]),
        ([      "name":                 "��",
		"action":
"$N����һ�࣬���е�$wƽ�Żӳ�������������������ñ���谮�����ˡ�����$n��$l",
                "dodge":                -5,
                "parry":                -5,
                "damage":      		15, 
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
		"action":
"$N��ǰ̤���벽������$w�й�ֱ�����������������������ᣬ���������ơ�����$n��ǰ��",
                "dodge":                -10,
                "parry":                0,
                "damage":     		20,
                "damage_type":  	"����"
        ]),
	([      "name":                 "��",
                "action":
"$N˫��һ�٣���������������ߣ�����֮���á������ߣ��ٴ�֮���͡�������գ�ͷ�½��ϣ�����$w����$n��ͷ��",
                "dodge":                -5,
                "parry":                -5,
                "damage":               20,
                "damage_type":  	"����"
        ]),
});

int valid_learn(object me)
{
	
	object ob;
	
	if( (int)me->query("max_force") < 100 )
		return notify_fail("�������������û�а취�����Ž�����\n");

	if( !(ob = me->query_temp("weapon"))
	||	(string)ob->query("skill_type") != "sword" )
		return notify_fail("���������һ�ѽ�������������\n");

	return 1;
}

int valid_enable(string usage)
{
	return usage=="sword" || usage=="parry" || usage=="literate";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}

int practice_skill(object me)
{
	
	int sword_level=(int)me->query_skill("sword");
	int pot=random(2)*random(2);
	
	

	if( (int)me->query("sen") < 20
	||	(int)me->query("force") < 3 )
		return notify_fail("��ľ��������������û�а취��ϰ���Ž�����\n");
	
	if (me->query("max_kee")*1000 > me->query("combat_exp"))
		return notify_fail("�����ѧ��Ϊû������ϰ���Ž���Ҳ��ͽ�͡�\n");
	
			
	me->receive_damage("sen", 10);
	me->add("force", -2);
	
	write("�㰴���Լ���ѧʶ����ϰ��һ�龲�Ž�����\n");	
		
		if (me->query("max_kee") < (me->query_skill("jingya")+sword_level/2)*10)
		{
		 me->add("max_kee",pot);
		 me->add("eff_kee",pot);		
		}	
	
	return 1;
}
