inherit SSERVER;
#include <ansi.h>


int cast(object me)
{
        int howlong;
        int spell,tt;
        spell=me->query_skill("spells")/2 + me->query_skill("mahayana");
        if(spell < 100)
                return notify_fail("�㻹û�����ն��ҵ�����������\n");

        if (me->query_temp("no_heal_up/yinshen"))
                return notify_fail("���Ѿ�������������!\n");
         if(me->query("family/family_name") != "������" )
                return notify_fail("�㲻�Ƕ����ɵ��ӣ��޷�����������������\n");
        if ( ((tt=(int)me->query_temp("lastyinshen")) <= time()) && 
             (tt+20 > time()))
                return notify_fail("��ո�ʹ�ù�������������������Ϣһ�°�!\n");

        if( (int)me->query("mana") < 2*(int)me->query_skill("spells"))
                return notify_fail("��ķ��������ˣ�\n");

        if( (int)me->query("sen") < 50 )
                return notify_fail("��ľ����޷����У�\n");

        message_vision("$NĬĬ���������Ԫ��һ�����������Լ�������\n", me);

        if( random(me->query("max_mana")) < 200 ) {
                me->add("mana",-(int)me->query_skill("spells"));
                me->receive_damage("sen",10);
                message("vision", "������������û�з����κα仯��\n", environment(me));
                return 5+random(5);
        }

        me->add("mana", -2*(int)me->query_skill("spells"));
        me->receive_damage("sen", 20);

        howlong = 15 + random((me->query_skill("spells") -100));
                call_out("free", howlong, me, howlong);

        me->set("env/invisibility", 1);
        me->set_temp("no_heal_up/yinshen",1);
        
        message_vision(HIB"\nһ������Ȼ��أ��������棡��֮��$N�����˶��ȿռ䣬������ǰ��ʧ�ˡ�\n\n"NOR, me);
        
        return 5+random(5);
}

void free(object user, int howlong)
{
        if(!user) return;
        user->delete_temp("no_heal_up/yinshen");
        if (!user->query("env/invisibility")) return;
        user->delete("env/invisibility");      
        user->save();
        message_vision(HIB"\nһ������������$N�������������ǰ��\n\n"NOR, user);
        user->set_temp("lastyinshen",time());
        return;
}

