inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("renshu") )
                return notify_fail("��ķ�����Ϊ����������޷�ѧϰ������\n");
        return 1;
}

string cast_spell_file(string spell)
        {
return CLASS_D("swordman") + "/renshu/" + spell;

        }

string type() { return "magic";}

