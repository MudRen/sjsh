// ������.c

inherit SKILL;

string *dodge_msg = ({
        "$n����һ�����˹�ȥ��\n",
        "$n����һ�����˹�ȥ��\n",
        "$nһ����粽��һ���ҿ粽����Ȼվ����$N�����\n",
        "$n��󼸸������������ɿ��⡣\n",
        "$nһ������������$Nվ�˸����Ա���\n",
        "$n����һ���շ�����֧�أ����������\n",
        "$nһ����˫���Ƶ�������󵹷ɣ����˹�ȥ��\n"
});

int valid_enable(string usage)
{
        return (usage=="dodge") || (usage=="move");
}

int valid_learn(object me)
{
        if( (int)me->query("max_force") < 0 )
        return notify_fail("�������������û�а취������������\n");

        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return notify_fail("��������������������ܲ�͸�������ˡ�\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}
