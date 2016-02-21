#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":               
"$Nʹһ��"+BLINK""+HIW"�����С�"NOR",����$w���Ż������⣬����ϸ���㽫$n��$l�����޾��Ľ�����",
                "dodge":                -50,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����Ȼ������е�"+BLINK""+HIC"��˪����"NOR"������ɻ�ƬƬ���ն��$n��$l",
                "dodge":                -40,
                "damage":               30,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��"+BLINK""+WHT"��˲ѩ��"NOR"���ζ�Ȼ��յ������ߣ����е�$wͽȻն��$n��$l",
                "dodge":                -50,
                "damage":               20,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ"+BLINK""+HIM"��������"NOR"��׼$n��$l�͵Ĵ̳�����",
                "dodge":                -40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ��"+BLINK""+MAG"����ն��"NOR"��׼$n��$lбб�̳�һ��",
                "dodge":                -70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ����Ȼ�任��ʽ��һ��"+BLINK""+HIW"��������"NOR"����$n��$l",
                "dodge":                20,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ��"+BLINK""+BLU"��ѩ�硹"NOR"���ֶ�׼$n$lһ����ȥ",
                "dodge":                -40,
                "damage":               60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ��"+BLINK""+HIC"��ˮ�¡�"NOR"����һ���⻡����$n��$l",
                "dodge":                -30,
                "damage":               50,
                "damage_type":  "����"
        ]),
});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취����Ȼ�������\n");
//        if(me->query("title") != "��ȵ�������")
          if(me->query("family/master_id") != "master xun" &&  me->query("family/master_id") != "master miyan")
                return notify_fail("�㰴����ѧ��ϰ��һ����Ȼ����������ƺ������ղ���������Ҫ�졣\n");



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
notify_fail("�����������������û�а취��ϰ��Ȼ�������\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ����Ȼ�������\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("swordman") + "/huoxin-sword/" + action;
}
 
int effective_level() { return 15;}

string *parry_msg = ({
        "$nʹ��һ�С����¡������еĽ�����һ�����磬�Ŀ���$N��$w��\n",
        "$nʹ�����ɻ���������$N��$w�������⡣\n",
        "$nʹ��һ�С���ˮ�������еĽ�����������Ӱ��������$N��$w��\n",
        "$n���еĽ�һ����һ�С���ѩ������$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����еĽ�����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
        "$n����һ�С��ɻ�������������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ�С���Ҷ������ֱ��$N��˫�֡�\n",
        "$n�����еĽ�������������������ɪɪ��磬�ȵ�$N�������ˡ�\n",
});

string query_parry_msg(object weapon)
{
        if( weapon )
                return parry_msg[random(sizeof(parry_msg))];
        else
                return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}

