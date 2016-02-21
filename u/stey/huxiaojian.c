// huxiaojian.c ����Х�ʽ���

#include <ansi.h>

inherit SKILL;

mapping *action = ({
	([	"action":		"$Nһ�����е�$w��ʹ��һ��"HIR"��һХ�쳾����"NOR"��˲��̳���ʮ������$n��ʱ��æ���ң��ֲ�����ʵ",
		"dodge":		-10,
                "parry":                -20,
		"damage":		35,
		"damage_type":		"����"
	]),
	([	"action":		"$Nһ������$n��ʹ��һ��"HIC"����Х��������"NOR"��$n��æ���Ա�һ����\n����$Nһ�˾��������е�$wͻȻ���˹�����ת������$n��$l",
		"dodge":		-20,
                "parry":                -10,
		"damage":		50,
		"damage_type":		"����"
	]),
	([	"action":		"$N����$w�������������⻷��һ����������$n��ǰ̤��һ����$N���ֽ�ָ�Ѵ���$n��$l������һ��"HIB"����Х����١�"NOR,
		"dodge":		-20,
                "parry":                -20,
		"damage":		55,
		"damage_type":		"����"
	]),
	([	"action":		"������"HIW"����Х����"HIW"��$Nһת������$n������$w��Ҹ�·��ִ���$n��$l",
		"dodge":		-10,
                "parry":                -10,
		"damage":		60,
		"damage_type":		"����"
	]),
});

int valid_learn(object me)
{
	object ob;

	if( (int)me->query("max_force") < 50 )
		return notify_fail("�������������û�а취����Х�ʽ���\n");
	if( !(ob = me->query_temp("weapon")) ||	(string)ob->query("skill_type") != "sword" )
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

int valid_effect(object me, object weapon, string name, int skill)
{
}
string perform_action_file(string action)
{
	return CLASS_D("sanjie")+"/huxiaojian/"+action;
}

int practice_skill(object me)
{
	int flvl=(int)me->query_skill("force");
	int slvl=(int)me->query_skill("sword");

	if( (int)me->query("kee") < 30 || (int)me->query("force") < 3 )
		return notify_fail("�����������������û�а취��ϰ��Х�ʽ���\n");
	me->receive_damage("kee", 30);
	me->add("force", -3);
	write("�㰴����ѧ����һ�黢Х�ʽ���\n");
	if(random(slvl)>flvl)
		me->improve_skill("force", 1);
	return 1;
}

int stage(int level)
{
	if( level <60 ) return 1;
	else if ( level < 120 ) return 2;
	else if ( level < 180 ) return 3;
	else return 4;
}

string level_description(int level)
{
	if ( stage(level) < 1 )
		return HIR "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 2 )
		return HIC "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else if ( stage(level) < 3 )
		return HIB "��"+chinese_number( stage(level) )+"�㡡" NOR;
	else 
		return HIW "��"+chinese_number( stage(level) )+"�㡡" NOR;
}

void skill_improved(object me)
{
   int m_skill=me->query_skill("sanqing-jian",1);

   if(m_skill>200&&m_skill%10==0){
     tell_object(me,HIW"��Ի�Х�ʽ�����������ˣ���Ļ�Х�ʽ�������һ���µľ��磡\n"NOR);

     if(random(me->query("kar"))<20){
        tell_object(me,HIW"Ȼ��������о�Ȼ������һ��ʧ��У�\n"NOR);
        return;
     }
     if(random(me->query("int"))<20){
       tell_object(me,HIW"Ȼ�������������һ�����ĸо����·���һ˿��Ҫ�Ķ���û��ץס��\n"NOR);
       return;
     }
     tell_object(me,HIW"��ͻȻ�������飬�Ի�Х�ʽ��������һ���µ��÷���\n"NOR);
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

   if(!arg||arg==" ")arg="��Х�ʽ�����"+chinese_number(sizeof(m_actions)+1);
   m_act+=(["name":arg]);
   msg= skill_head[random(sizeof(skill_head))]+BLINK+HIB"��"+arg+"��"NOR
                  +skill_tail[random(sizeof(skill_tail))];
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   me->set("skill_sanqing-jian",m_actions);
}