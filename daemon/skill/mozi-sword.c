// ī�ӽ�����mozi-sword.c   created 17-06-2001 ����Ʈ(piao)
//  ���ݻ���С˵��Ѱ�ؼǡ��е���������ī�ӽ����ı�

inherit SKILL;
#include <ansi.h>


mapping *action = ({
   ([
     "action":
"$N���ҵ���������"+BLINK""+CYN"��ī�س¹桹"NOR"$w�������һ�½�ǽ��$n�Ĺ�����������$N�ֺ�",
     "dodge":     -15,
     "parry":     10,
     "damage":     200,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ��,һ��"+BLINK""+MAG"���Թ�Ϊ�ء�"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n���ҵ���,����"+BLINK""+HIY"��ī�سɹ桹"NOR"���������������һ�½�ǽ,$N�Ĺ�����������$n�ֺ���\n",
		"parry_power":		50,
     ] ),
   ([
     "action":
"$Nһ��"+BLINK""+GRN"����ī������"NOR"��ת��������$w��ס���Ƶ�ͬʱ��˲���ֳ�һ������$n��$l",
     "dodge":     -5,
     "parry":     -10,
     "damage":     300,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ��,һ��"+BLINK""+WHT"�����ؼ汸��"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		50,
		"parry_msg":
"$n���ҵ���,����"+BLINK""+HIY"��ī�سɹ桹"NOR"���������������һ�½�ǽ,$N�Ĺ�����������$n�ֺ���\n",
		"parry_power":		50,
   ] ),
   ([
     "action":
"ֻ��$N���һ����һ��"+BLINK""+RED"��Ѫī���ڡ�"NOR"�������������$w�ó�������Ӱ����������칥��$n",
     "dodge":     -5,
     "parry":     -5,
     "damage":     500,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ��,һ��"+BLINK""+MAG"���Թ�Ϊ�ء�"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		10,
		"parry_msg":
"$n���ҵ���,����"+BLINK""+HIY"��ī�سɹ桹"NOR"���������������һ�½�ǽ,$N�Ĺ�����������$n�ֺ���\n",
		"parry_power":		50,

   ] ),
   ([
     "action":
"���ھù�����֮�ʣ�$N���ƾ۱䣬����Ť�����壬$w���дӲ����ܵĽǶȿ񿳶���",
     "dodge":     -15,
     "parry":     5,
     "damage":     200,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ��,һ��"+BLINK""+BLU"�����ش�����"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		80,
		"parry_msg":
"$n���ҵ���,����"+BLINK""+HIY"��ī�سɹ桹"NOR"���������������һ�½�ǽ,$N�Ĺ�����������$n�ֺ���\n",
		"parry_power":		50,

   ] ),
   ([
     "action":
"��ս�У���֪$N����������߶���ֻ��$w���Ҳ壬����һ�̼侹��$n��������",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ��,һ��"+BLINK""+BLU"�����ش�����"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		80,
		"parry_msg":
"$n���ҵ���,����"+BLINK""+HIY"��ī�سɹ桹"NOR"���������������һ�½�ǽ,$N�Ĺ�����������$n�ֺ���\n",
		"parry_power":		50,

   ] ),
     ([
     "action":
"���$N���ٱ�����$w�ó���Ƭ��Ӱʱ��ͻȻ�ֳ�����,�������$n��$l����,�����ޱ�",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����ĳ�ְ��أ���$N���Ѱ��ձƽ����ٶȺ�ʱ�䡣\n",
		"dodge_power":		80,
		"parry_msg":
"$n˿�����壬�԰�$W�ĽǶȣ���ס��$N�Ľ�����\n",
		"parry_power":		50,

   ] ),
   ([
     "action":
"$N˫Ŀ�ӹ���â����Ȼ�Ƕ���ɱ�����������ף����һ��������$w��$n$l��һ������",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "����",
        "dodge_msg":
"$n����ȥ������һ����â����Ȧ���պ�ӭ��$N����һ�С�\n",
		"dodge_power":		80,
		"parry_msg":
"$n����ȥ������һ����â����Ȧ���պ�ӭ��$N����һ�С�\n",
		"parry_power":		50,

   ] ),
   ([
     "action":
"$N������ԥ����Ӱ���ε���$n��ȥ��ͬʱ�ɵ��ָ�Ϊ˫����$w���߾ٹ�ͷ,
�����Ƶ���֮��Ĳ�������ͷ����$n��ȥ",
     "dodge":     -5,
     "parry":     0,
     "damage":     15,
     "damage_type":     "����",
        "dodge_msg":
"$n�Ĳ����̽ݿ����һ��"+BLINK""+BLU"�����ش�����"NOR"���侹˳�ƶ��$N�Ĺ��ơ�\n",
		"dodge_power":		80,
		"parry_msg":
"$n$w���·��ɣ���â���䣬������ס��$N�Ĺ��ơ�\n",
		"parry_power":		50,

   ] ),


});

int valid_learn(object me)
{
   object ob;

   if( (int)me->query("max_force") < 150 )
     return notify_fail("���������Ϊ������޷�ѧī�ӽ�����\n");

   if (!(ob = me->query_temp("weapon"))
           || (string)ob->query("skill_type") == "axe" 
           || (string)ob->query("skill_type") == "spear" 
           || (string)ob->query("skill_type") == "fork" 
           || (string)ob->query("skill_type") == "qin" 
           || (string)ob->query("skill_type") == "mace" 
           || (string)ob->query("skill_type") == "dagger" 
           || (string)ob->query("skill_type") == "hammer" 
           || (string)ob->query("skill_type") == "staff" 
           || (string)ob->query("skill_type") == "stick" 
           || (string)ob->query("skill_type") == "whip" 
           || (string)ob->query("skill_type") == "rake" 
           || (string)ob->query("skill_type") == "throwing" 
           || (string)ob->query("skill_type") == "archery" )
      return notify_fail("���������һ������������ϰī�ӽ�����\n");

   return 1;
}


int valid_enable(string usage)
{
   return usage=="sword"||usage=="parry"||usage=="blade"||usage=="dodge";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string query_parry_msg(object weapon)
{
	return action[random(sizeof(action))]["parry_msg"];
}
string query_dodge_msg(string limb)
{
	return action[random(sizeof(action))]["dodge_msg"];
}

int practice_skill(object me)
{
   int dod=(int)me->query_skill("dodge");
   int swo=(int)me->query_skill("mozi-sword");

   if (dod<swo/2)
     return notify_fail("����������Ͻ���������ȥ�ܿ��ܻ��˵��Լ���\n");
   if ((int)me->query("kee") < 30)
     return notify_fail("������Ƿ�ѣ�ǿ��ī�ӽ����к����档\n");
   if ((int)me->query("force") < 30)
     return notify_fail("���������㣬ǿ��ī�ӽ������߻���ħ��Σ�ա�\n");
   me->receive_damage("kee", 30);
   me->add("force", -5);
   message_vision("$NĬĬ������һ�����Ȼ������һ��ī�ӽ�����\n", me);
   return 1;
}

string perform_action_file(string func)
{
return CLASS_D("youxia") + "/mozi-sword/" + func;
}

