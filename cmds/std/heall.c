// full.c
#include "/doc/help.h"
#include "ansi.h"
inherit F_CLEAN_UP;
int main(object ob,string arg)
{
        object me,obj;
        int force, mana;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("��Ҫ��˭���ˣ�\n");
        if (!me)->query_skill("medical",1)<1000)
		return notify_fail("�㻹����ҽ��,�������ˡ�\n");
}
        }
       force = (int)me->query("max_force");
       mana  = (int)me->query("max_mana");
       me->set("eff_kee",me->query("max_kee"));
       me->set("kee",me->query("max_kee"));
       me->set("eff_sen",me->query("max_sen"));
       me->set("sen",me->query("max_sen"));
       me->set("force",force*2);
       me->set("mana",mana*2);
       ob->clear_condition();
//       ob->reincarnate();
message_vision("$N���ȶ�����ȫ������һ��"HIW"����"NOR"����ɫ����"HIR"����"NOR"������\n", me);
     return 1;
}
