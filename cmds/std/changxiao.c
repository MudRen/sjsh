// shout.c
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
                if(me->query("family/family_name") == "��ͨ����" )
		return notify_fail("������ͨ���գ�����������Х��\n");

        if((int)me->query_skill("force", 1) < 200)
                return notify_fail("��ĵ�������Ϊ����������޷���Х��\n");

        if((int)me->query("sen") < 500 )
                return notify_fail("��ľ����㣬�޷���Х��\n");

        if (!arg) return notify_fail("����Ҫ���ʲô��\n");
          shout(HIW + me->name() +  "������Х��"HIR"" + arg + "\n" NOR);
          write(HIW "��������Х��"HIR""+ arg + "\n" NOR);
        me->receive_damage("sen", 100);
        return 1;
}
int help(object me)
{
  write(@HELP
ָ���ʽ : shout <ѶϢ>
 
���ָ�����㽫 <ѶϢ> ���ͳ�ȥ, ����������Ϸ�е��˶�
��������Ļ�.
 
see also : tune
HELP
    );
    return 1;
}
 


