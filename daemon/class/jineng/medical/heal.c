// heal.c

#include <ansi.h>

int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("ս�������ˣ�������\n");

        if( (int)me->query("force") < 50 )
                return notify_fail("�������������\n");
        //if( (int)me->query("mana") < 50 )
        //        return notify_fail("��ķ���������\n");
       // if ((int)me->query_skill("medical", 1) <=0)
        //        return notify_fail("�㻹����ҽ���ǡ�\n");
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )

                return notify_fail("���Ѿ����˹��أ�ֻ��һ��������������Σ�գ�\n");
	message_vision("$N���ȶ�����ȫ������һ����棬�˿�Ҳ���������ˡ�\n", me);

        me->receive_curing("kee", 10 + (int)me->query_skill("force")/5 );
        me->add("force", -10);
        //me->add("mana", -50);
        return 1;
}

