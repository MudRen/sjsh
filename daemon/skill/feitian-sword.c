#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ��"+BLINK""+HIC"�����졤���硹"NOR"������$w��һ�����߰����$n��$l",
                "dodge":                -50,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������������е�"+BLINK""+HIM"�����졤������"NOR"���������ն��$n��$l",
                "dodge":                -80,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��"+BLINK""+HIW"�����졤��ն��"NOR"�����ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                -80,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ"+BLINK""+HIG"�����졤���ס�"NOR"��׼$n��$l�̳�һ��",
                "dodge":                -60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ��"+BLINK""+HIC"�����졤ˮ����"NOR"��׼$n��$lбб�̳�һ��",
                "dodge":                -50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ��"+BLINK""+HIG"�����졤������"NOR"����$n��$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ��"+BLINK""+RED"�����졤������"NOR"���ֶ�׼$n$lһ����ȥ",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ��"+BLINK""+MAG"�����졤������"NOR"����һ���⻡����$n��$l",
                "dodge":                -10,
                "damage":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 500 )
                return notify_fail("�������������û�а취��������������\n");
          if(me->query("family/master_id") != "master bigu" &&  me->query("family/master_id") != "master jianxin")
                return notify_fail("�㰴����ѧ��ϰ��һ����������������ƺ������ղ���������Ҫ�졣\n");



        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
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
        ||      (int)me->query("force") < 3 )
                return 
notify_fail("�����������������û�а취��ϰ������������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ�������������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordman") + "/feitian-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С��������졹�����еĽ�����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
        "$nʹ��һ�С�������ѩ�������еĽ���������ѩӰ��������$N��$w��\n",
        "$n���еĽ�һ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����еĽ�����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С����ھ��졹����ֱ��$N��˫�֡�\n",
        "$n�����еĽ����������������ȵ�$N�������ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

int learn_bonus()
{
        return 20;
}
int practice_bonus()
{
        return 10;
}
int black_white_ness()
{
        return 15;
}

