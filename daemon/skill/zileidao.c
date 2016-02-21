// zileidao.c �����׵�����

#include <ansi.h>

inherit SKILL;
string* skill_head =({
        "$N�������ˣ�ʹ��һ��",
        "$N���쳤Ц����Ҳ������һ��",
        "$N����һԾ��ʹ�˸�",
        "$N��̬���У�һ��",
        "$N����ת����ͣ��ͻȻһ��",
        "$N����̤�˸���������һ��",
});

string* skill_tail =({
        "������$w����������$n����һն",
        "������$w��׼$n��$l���һն",
        "�����ֽ�$w��׼$n$lһ����ȥ",
        "������$w����ػ���$n��$l",
        "�����ֶ�׼$n$lһ����ȥ",
        "����$nת��֮�ʣ��ӳ�һ��",
});


mapping *action = ({
        ([      "action":		"$N�ḧ���е�$w��ͻȻ��ֻ������һ������������һ����\nʹ��һ��"YEL"�����ױ�����"NOR"�������̹ǵĺ�����ȻϮ����$n��$l",
     		"dodge":     -15,
     		"parry":     5,
     		"damage":    25,
     		"damage_type":     "����"
        ]),
        ([      "action":		"ֻ��$N����$w�����μ��壬������$n����֮�ʣ�һ��"HIR"�����׵�����"NOR"ͻȻ����һ����$n����б������",
     		"dodge":     -15,
     		"parry":     5,
                "damage":    30,
                "damage_type":     "����"
        ]),
        ([      "action":		"$Nб����𣬴���һƬƥ��Ҳ�Ƶĵ������$n��$l����һ��"HIG"��������ת��"NOR"��",
                "dodge":     -15,
     		"parry":     5,
                "damage":    35,
                "damage_type":     "����"
        ]),
        ([      "action":		"$NͻȻһ���߳���ʹ��"HIY"������������"NOR"�����е�$w����һ�������Բ����\n�����ĵ����ס��$n��ͷ�����ж���$n�ĺ���",
                "dodge":     -15,
     		"parry":     5,
                "damage":    30,
                "damage_type":     "����"
        ]),
        ([      "action":		"ֻ��$N��ɫһ����һ��"HIB"�������������"NOR"ʹ������ü�ݵ��Ÿ���\n$n�����ѪҺ���Ʊ����޾��ĵ��ƶ�ס��������Ҳ�·�Ҫ�����ȥ",
                "dodge":     -15,
     		"parry":     5,
                "damage":    40,
                "damage_type":     "����"
        ]),   
        ([      "action":		""HIM"�����ױ�������"NOR"ʹ����$N���ƽ�������$w�ϴ����ĺ���ȴԽ��ԽŨ��\n������ʱ��$n����ͷһ����һ������⻹Ҫ�����ĺ����Ѵ�����$n$l",
                "dodge":     -15,
     		"parry":     5,
                "damage":    50,
                "damage_type":     "����"
        ]),   
        ([      "action":		"$NҲ�������߶�ʮһ���߾�$w�����ؾ���һ����$nӭ��ն�£�\n��Ȼֻ��һ�������µĵ���ȴ����Ų����ĺ���������$n��һ����·��\n����"HIC"��ŭ��˺���ѵء�"NOR"�ú���",
                "dodge":     -15,
     		"parry":     5,
                "damage":    60,
                "damage_type":     "����"
        ]),   
});


int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 100 )
                return notify_fail("�������������û�а취�����׵���������Щ���������ɡ�\n");
        if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "blade" || (string)ob->query("material") != "gold" )
                return notify_fail("���������һ�ѵ����׵����������׵�����\n");
        return 1;
}

int valid_enable(string usage)
{
  return usage =="blade" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30 || (int)me->query("force") < 5 )
                return notify_fail("�����������������û�а취��ϰ���׵�����\n");
        me->receive_damage("kee", 30);
        me->receive_damage("sen", 30);
        write("�㰴����ѧ����һ�����׵�����\n");
        return 1;
}

int valid_effect(object me, object weapon, string name, int skill)
{
}

string perform_action_file(string action)
{
 return CLASS_D("sanjie")+"/zileidao/"+action;
}

int stage(int level)
{
	if( level <10 ) return 1;
	else if ( level < 20 ) return 2;
	else if ( level < 40 ) return 3;
	else if ( level < 70 ) return 4;
	else if ( level < 110 ) return 5;
	else if ( level < 160 ) return 6;
	else if ( level < 220 ) return 7;
	else return 8;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return YEL "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 2 )
		return HIR "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 3 )
		return HIG "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 4 )
		return HIY "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 5 )
		return HIB "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 6 )
		return HIM "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 7 )
		return HIC "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else 
		return HIW "��"+chinese_number( stage(level) )+"�㡡" NOR;
}
void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"������׵�������������ˣ�������׵���������һ���µľ��磡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�����׵����������һ���µ��÷���\n"NOR);
     tell_object(me,"��Ϊ����ȡһ�����֣�");
     input_to( (: call_other, __FILE__, "name_skill", me:));
   }
   return;
}

void name_skill(object me, string arg)
{
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=me->query("skill_sanqing-jian");
 if(!pointerp(m_actions))m_actions=({});

   content=me->query("str")+2*me->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-me->query("spi");
   m_act+=(["dodge" :content]);
   content=-me->query("cps");
   m_act+=(["parry" :content]);
   content=me->query("con")+me->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   if(!arg||arg==" ")arg="���׵�������"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIB"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
}
