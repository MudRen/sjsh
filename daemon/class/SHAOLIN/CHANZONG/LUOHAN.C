// cast...jingang.c

inherit SSERVER;

int cast(object me, object target)
{
        int invocation_time;
        object soldier;
        object soldier2;

        if( !me->is_fighting() )
                return notify_fail("ֻ��ս���в����ٻ�ʮ���޺���\n");

        invocation_time=60+(200-(int)me->query_skill("spells"));
        if(invocation_time<30) invocation_time=30;
        if((time()-me->query("last_invocation"))<invocation_time)
            return notify_fail("��սй�ʮ���޺������Ƕ�����з��ˣ�\n");

        if( (int)me->query("mana") < 500 )
                return notify_fail("��ķ��������ˣ��޷��ٻ�ʮ���޺���\n");

        if( (int)me->query("sen") < 150 )
                return notify_fail("��ľ����޷����У��޷��ٻ�ʮ���޺���\n");

        message_vision("$N�૵����˼���������\n", me);

        me->add("mana", -300);
        me->receive_damage("sen", 150);

        if( random(me->query("max_mana")) < 800 ) {
                message("vision", "����ʲôҲû�з�����\n",
environment(me));
                return 1;
        }

        seteuid(getuid());
        soldier = new("/obj/npc/luohan1");
        soldier2 = new("/obj/npc/luohan2");
        soldier->move(environment(me));
        soldier2->move(environment(me));
        soldier->invocation(me);
        soldier2->invocation(me);
        soldier->set_temp("invoker",me);
        soldier2->set_temp("invoker",me);
        me->set("last_invocation",time());
        me->start_busy(1+random(1));

        return 8+random(5);
}

