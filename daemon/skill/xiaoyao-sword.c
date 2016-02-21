// ��ң���÷�ؽ���xiaoyao-sword.c
// lost
// ��ʽ �佣ʽ �˽�ʽ �콣ʽ ����ʽ ת��ʽ
#include <ansi.h>
inherit SKILL;
mapping *action = ({
        ([      "name":                 "��ʽ",
                "action":
"��ʽ��\n"
"$N����󷭣������������$w��أ��������Ʈ��$n,$w����$n��$l",
                "dodge":                30,
                "parry":                10,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�佣ʽ",
"�佣ʽ��\n"            "action":
"$N˫�Ŷٵ�Ծ����У�������¡���������$w\n"
"����ȴʼ�ղ���һ�㣬����һ�����$n,������$n��$l",
                "dodge":                -10,
                "parry":                -10,
                "damage":               50,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�˽�ʽ",
                "action":
"�˽�ʽ��\n"
"$N���������෭���������$w������ת��\n"
"ͻ�ķ���ؾ�Ϯ��$n������$w����$n��$l",
                "dodge":                30,
                "parry":                20,
                "damage":               30,
                "damage_type":          "����"
        ]),
        ([      "name":                 "�콣ʽ",
                "action":
"�콣ʽ��\n"
"$N��$n�������ߣ���$n������У�"
"$N����$w�ÿ�$n�Ĺ��ƣ����ж��ϴ���$n��$l",
                "dodge":                -5,
                "parry":                30,
                "damage":               35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ʽ",
                "action":
"����ʽ��\n"
"$Nԭ��һ�����ת������$w����$n��$l",
                "dodge":                0,
                "parry":                0,
                "damage":               50,
                "damage_type":          "����"
        ]),
        ([      "name":                 "ת��ʽ",
                "action":
"ת��ʽ��\n"

"$Nչ�����Σ�$w֮�������಻���ز���$n��$l��"
"ת��ʽ����Ȼ�з��·ת���湦��",
                "dodge":                10,
                "parry":                10,
                "damage":               40,
                "damage_type":          "����"
        ]),
        ([      "name":                 "����ʽ",
                "action":
"��ʽ��\n"
"$N����������$nֻ��$N����ӰѸ���ƶ�������$N���е�$w���ص���$n��$l,$n�ƺ��Ѿ��޴ӱ�����",
                "dodge":                40,
                "parry":                40,
                "damage":               40,
                "damage_type":          "����"
        ]),
        
});
int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("���������Ϊ�����ѧ��Ҳû�á�\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "sword" )
                return notify_fail("���������һ����������ϰ������\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("xiaoyao-sword");

        if (dod<swo/2)
                return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("������Ƿ�ѣ�ǿ����ң�����к����档\n");
        if ((int)me->query("force") < 5)
                return notify_fail("���������㣬ǿ����ң�������߻���ħ��Σ�ա�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$NĬĬ������һ�����Ȼ������һ����ң������\n", me);
        return 1;
}

int valid_enable(string usage)
{
        return usage=="sword"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

mixed hit_ob(object me, object victim)
{
        string msg;
        int ap,dp;
        object weapon;

        ap = me->query_skill("sword");
        ap += (me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");

        if(objectp(weapon) && me->query_skill("sword")>100){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("force") > random(victim->query("force"))){
                         if(weapon->query("rigidity") >=4 ){  
                               victim->start_busy(2);
                               weapon->move(environment(victim));       
                               victim->receive_damage("kee", ap);  
                               victim->receive_wound("kee", ap/2);      
       msg = HIR"ֻ����������һ����$n���е�$w"HIR"�ѱ������ɡ�$nҲ����Ľ������ˡ�\n" NOR;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(1);
msg = HIW"$N����ԣ�����������������ֻ����ž����һ���죬$n����$w"HIW"�ѱ���������Ρ�\n" NOR;
                                msg = replace_string(msg, "$w", weapon->name());
                                weapon->unequip();
                                weapon->move(environment(victim));
                                weapon->set("name", "�ϵ���"+weapon->query("name"));
                                weapon->set("value", 0);
                                weapon->delete("long");
                                weapon->set("weapon_prop", 0);
                                }
                                }
                   else {       
       msg = HIY"ֻ�����ˡ���һ�����죬$n���е�$w"HIY"�����ν����ĳ���²�ס��������Щ���֣�\n" NOR;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
}

string perform_action_file(string action)
{
    return CLASS_D("tiankongjie") + "/xiaoyao-sword/" + action;
}
