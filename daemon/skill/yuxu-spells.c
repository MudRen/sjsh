inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( 2*(int)me->query_skill("spells") <= (int)me->query_skill("yuxu-spells") )
        return notify_fail("��ķ�����Ϊ����������޷�ѧϰ�������ɷ�����\n");
        return 1;
}

string cast_spell_file(string spell)
{
        return CLASS_D("kunlun") + "/yuxu-spells/"+spell;
}

string type() { return "magic"; } 
