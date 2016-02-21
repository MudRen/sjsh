// fy-sword.c
inherit SKILL;
#include <ansi.h>
mapping *action = ({
        ([      "action":
"$Nʹ��һ��"+BLINK""+HIC"����β����"NOR",���е�$w����һ��Բ������$n��$l����",
                "dodge":                -50,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���������ĳ�һ�ƣ������е�$wʹ��һ��"+BLINK""+HIW"����������"NOR",ն��$n��$l",
                "dodge":                -10,
                "damage":               70,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һ��"+BLINK""+HIB"�����ɱ��"NOR",����������ˮ������$w���������ն��$n��$l",
                "dodge":                -50,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$Nʹ��һʽ��"+BLINK""+MAG"������ɱ��"NOR",��׼$n��$l�̳�һ��",
                "dodge":                -20,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N������$w���μ������У�һ��"+BLINK""+RED"��ɢ������"NOR"��$n��ȥ",
                "dodge":                -60,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N˫���ս���ʹ��һ��"+BLINK""+HIR"�����ն��"NOR"����$n��$l",
                "dodge":                -100,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":
"$N���н�����һ�Σ�$w��Ϊһ����⣬ʹ��"+BLINK""+BLU"�����׽���"NOR"����$n��$l",
                "dodge":                -10,
                "damage":               100,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취����Ȼ��������\n");
          if(me->query("family/master_id") != "master zhaitengyi" &&  me->query("family/master_id") != "master zongsi")
                return notify_fail("�㰴����ѧ��ϰ��һ����Ȼ�����������ƺ������ղ���������Ҫ�졣\n");


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
        ||      (int)me->query("force") < 5 )
                return  notify_fail("�����������������û�а취��ϰ��Ȼ��������\n"
);
        me->receive_damage("kee", 30);
        me->add("force", -5);
        write("�㰴����ѧ����һ����Ȼ��������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordman") + "/lixin-sword/" + action;
}

int effective_level() { return 9;}

string *parry_msg = ({
        "$n�Թ����أ���ֱ��$N��ȥ��$N�ŵ����������������˹��ơ�\n",
        "$nʹ��һ�С����¡�����ȫ������˽�Ļ�С�\n",
});

string *unarmed_parry_msg = ({
        "$n�����еĽ������̳�����ס$N��ȫ�����ơ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

