 // skill talk ,by boy

inherit SKILL;

mapping *action = ({
	([	"action":
"$N�ſ�Ѫ����죬һʽ��Ѫ�����ˡ���ߴ���������$n",
		"force":		150,
                "damage_type":          "����",
      "weapon" :              "˫��",
        "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
	([	"action":
  "$N�ſ�Ѫ����죬һʽ����Ѫ��ͷ����ߴ���������$n",
		"force":		100,
                "damage_type":          "����",
      "weapon" :              "˫��",
        "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
	([	"action":
       "$N�������Ĳ�����һʽ��˥���塹������ž�����$n",
		"force":		120,
                "damage_type":          "����",
      "weapon" :              "����",
                   "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
	([	"action":
             "$N��Ƥ�鶯��һʽ�����ޱߡ�������ž�����$n",
		"force":		100,
                "damage_type":          "����",
      "weapon" :              "����",
        "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
            ([	"action":
             "ֻ��$N����ͦ�أ�һʽ���������ء��������������$n",
		"force":		150,
                "damage_type":          "˥��",
      "weapon" :              "����",
        "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
            ([	"action":
             "ֻ��$N����Ǭ����һʽ����٩�޵С��������������$n",
		"force":		180,
                "damage_type":          "����",
      "weapon" :              "����",
        "parry_msg":    "ֻ��$N��Ŀ����,��֮����",
	]),
});

int valid_learn(object me)
{


   if(me->query("id")!="boy" )
     return notify_fail("����򲻿�������\n");
	return 1;
}

int valid_enable(string usage)
{
       return usage=="literate";
}

mapping query_action(object me, object weapon)
{
	return action[random(sizeof(action))];
}


string perform_action_file(string func)
{
	return CLASS_D("dragon") + "/dragonfight/" + func;
}
