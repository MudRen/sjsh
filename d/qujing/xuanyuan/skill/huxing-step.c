// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit SKILL;

string *dodge_msg = ({
        "$nһʽ������ɺ������μ�ת��Ծ��������\n",
   "$nһ��������������һ�㣬�������ɿ��⡣\n",
   "ֻ��$n����һ�Σ�һ����������֡�������Ķ㿪��\n",
   "$nһ��������$N��ʱ�����޴룬$n�û�����һ�ԡ�\n",
"$n��Ȼ��$Nһ����Ц��$N��ʱ�������Լ���ս��֮�С�\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("��������������������������в�����\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

