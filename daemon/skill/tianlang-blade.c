//tianlang-blade.c ������ҹħ����lost 2002

#include <ansi.h>

inherit SKILL;

mapping *action = ({
        ([      "name":                 "��",
                "action":
"$N�ḧ���е�$w��$w��£����һ�㵭����������
һ�������Ĺǵĺ�����ȻϮ����$n��$l",
                "dodge":                0,
                "parry":                10,
                 "damage":              35,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"ֻ��$N��������$w������ʳָ����ָ��ס������һ������ֱ����ʡ�
��$n���ֻʱ��$w�Ѿ�������$n��$l",
                "dodge":                0,
                "parry":                0,
                "damage":                       50,
                "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$NͻȻ����һ�������˺�һֱ����$n��$l",
                        "dodge":                        10,
                        "parry":                -15,
                        "damage":                       50,
                        "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"$N��ǰ����������һ���������������»��¡�
������ɫ�ĵ����ס��$n��ͷ�����ж���$n�ĺ���",
                        "dodge":                        5,
                        "parry":                10,
                        "damage":                       40,
                        "damage_type":          "����"
        ]),
        ([      "name":                 "��",
                "action":
"ֻ��$Nһ����Ц��������䣬��ʽһ��
$n�ƺ�����Ҳ�����ˣ�����$w�����Լ���$l��ȴҲ�������á�",
                        "dodge":                        -15,
                        "parry":                0,
                        "damage":                       50,
                        "damage_type":          "����"
        ]),   
        ([      "name":                 "��",
                "action":
"$N����ͻȻ��죬�Ϲ��ʤֱ����$n��$l
$n����ͷһ�����ⲻ������������",
                "dodge":                        0,
                "parry":                10,
                "damage":                       40,
                        "damage_type":          "����"
        ]),   
        ([      "name":                 "��",
                "action":
"$N����ħ��һ������ǰ���������һ������$n��
��Ȼ�Ǽ򵥵�һ�������µĵ���ȴ������Ũ�ص�ħ����$n�ƺ��Ѿ�û����·",
                        "dodge":                        0,
                        "parry":                0,
                        "damage":                       80,
                        "damage_type":          "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 50 )
                return notify_fail("���������Ϊ�����ѧ��Ҳû�á�\n");
        if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") != "blade" )
                return notify_fail("���������һ�ѵ�������ϰ������\n");
        return 1;
}

int practice_skill(object me)
{
        int dod=(int)me->query_skill("dodge");
        int swo=(int)me->query_skill("tianlang-blade");

        if (dod<swo/2)
                return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
        if ((int)me->query("kee") < 30)
                return notify_fail("������Ƿ�ѣ�ǿ��ҹħ���к����档\n");
        if ((int)me->query("force") < 5)
                return notify_fail("���������㣬ǿ��ҹħ�����߻���ħ��Σ�ա�\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        message_vision("$NĬĬ������һ�����Ȼ������һ��ҹħ����\n", me);
        return 1;
}

int valid_enable(string usage)
{
        return usage=="blade"||usage=="parry";
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

        ap = me->query_skill("blade");
        ap += (me->query_str())*2;
        dp =  victim->query_skill("parry");
        
        weapon = victim->query_temp("weapon");

        if(objectp(weapon) && me->query_skill("blade")>100){ 
        if( random(ap+dp) > dp && random(2)>0){
        if(me->query("force") > random(victim->query("force"))){
                         if(weapon->query("rigidity") >=4 ){  
                               victim->start_busy(2);
                               weapon->move(environment(victim));       
                               victim->receive_damage("kee", ap);  
                               victim->receive_wound("kee", ap/2);      
         msg = MAG"ֻ����������һ����$n���е�$w�ѱ������ɡ�$nҲ�����ħ�����ˡ�\n"NOR ;
                                msg = replace_string(msg, "$w", weapon->name());    
                               }
                        else{
                               victim->start_busy(1);
  msg = MAG"$N����ԣ�����������������ֻ����ž����һ���죬$n����$w�ѱ���������Ρ�\n"NOR ;
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
         msg = HIM"ֻ�����ˡ���һ�����죬$n���е�$w�����ΰ����ĳ���²�ס��������Щ���֣�\n"NOR ;
                            msg = replace_string(msg, "$w", weapon->name()); 
                                                           }
                }

                return msg; 
    }
}

string perform_action_file(string action)
{
    return CLASS_D("tiankongjie") + "/tianlang-blade/" + action;
}
