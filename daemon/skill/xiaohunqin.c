#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "action":               
"$N΢΢���������е�$w��һ��"+BLINK""+HIW"������Σ¥��ϸϸ��"NOR"��������������������һ��һ�����$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
      		  "force" :		180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ȻһЦ��$w��"+BLINK""+HIW"����ɫ�̹�����"NOR"����ĳ�����ʥ����������հ�����$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ��"+BLINK""+HIW"������˭��ƾ���⡹"NOR"������$wĬĬ�ĵ����ţ������е�ɱ������$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                30,
                "force":               150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����Ṧ���˼���������$w����һ��"+BLINK""+HIW"��������ͼһ��"NOR"��������������׼$nһ���̳���ʽ��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��$w������յ���������,һ��"+BLINK""+HIW"���´������ղ��ڡ�"NOR"ͻȻ����������ȫȻ����$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               80,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��ϥ����,�Դﵽ���ٺ�һ�ľ���,$w���е���һ��"+BLINK""+HIW"��Ϊ���������㲡�"NOR"$n$lһ���ʹ��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               300,
                "damage_type":  "����"
        ]),
              ([      "action":               
"$N����һ��"+BLINK""+HIW"��һҶ��Ƽ��󺣡�"NOR"������$wһ�ڣ����μ�����ɣ����ٺ�һ������$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
               "dodge":                20,
		  "force":		       100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N$w�����������⣬һ��"+BLINK""+HIW"�������δ�����꡹"NOR"��������������������$n����
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������ˮ��"+BLINK""+HIW"��˥��б�������֡�"NOR"��¶��������꣬����бб����$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                30,
                "force":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w������һ��"+BLINK""+HIW"������Ӱ�հ����̡�"NOR"������ն��$n����
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���裬�������Ŵشأ�һ��"+BLINK""+HIW"�����ܻ���֪��ɫ��"NOR"��ƮƮ������$n��ȥ��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����ɭȻ��һ��"+BLINK""+HIW"����Ƽ��Զ��������"NOR"����ɱ��ֱ��$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",
                "dodge":                20,
                "force":               200,
                "damage_type":  "����"
        ]),
([      "action":               
"$N�ٴν�������������һ��"+BLINK""+HIW"���ͷ������仨�졹"NOR"������$w�ڶ�������һ���������$n��
$n"+HIR"�������е�����һ�𣬶�ʱ��Ѫ��ӿ���е�������ת����Ȼ���˺��ص�����"NOR"",

                "dodge":                20,
                "force":               300,
                "damage_type":  "����"
        ]),

});

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("�������������û�а취��ϰ�����١�\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "qin" )
                return notify_fail("���������һ���ٲ��������ա�\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="qin" || usage=="parry";
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
notify_fail("�����������������û�а취��ϰ�����١�\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        write("�㰴����ѧ����һ�������١�\n");
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("youxia") + "/xiaohunqin/" + action;
}
 
int effective_level() { return 23;}

string *parry_msg = ({
        "$nʹ��һ��"+HIW"���������"NOR"�����е�$v������$N��$w��\n",
        "$nʹ��"+HIW"����������ʡ�"NOR"����$N��$w�������⡣\n",
        "$nʹ��һ��"+HIW"��ǿ�ֻ���ζ��"NOR"�����е�$v����������գ�������$N��$w��\n",
        "$n���е�$vһ����һ��"+HIW"���ԾƵ��衹"NOR"����$N��$w��������ȥ��\n",
});

string *unarmed_parry_msg = ({
        "$n�����е�$v����ܲ�͸�磬һ��"+HIW"�����ǿ��Ϊ��"NOR"��ס��$N�Ĺ��ơ�\n",
        "$n����һ��"+HIW"�����������ޡ�"NOR"����������ʧ��һ�Ž���֮�С�\n",
        "$nʹ��һ��"+HIW"���м���ɫ�ԡ�"NOR"��$vֱ��$N��˫�֡�\n",
        "$n�����е�$vһ����һ��"+HIW"���Ѿ��ִ�����"NOR"���ȵ�$N�������ˡ�\n",
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
	return -100;
}
int practice_bonus()
{
	return -50;
}
int black_white_ness()
{
	return 20;
}

