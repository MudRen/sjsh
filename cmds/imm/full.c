// full.c
#include "/doc/help.h"
#include "ansi.h"
inherit F_CLEAN_UP;
int main(object ob,string arg)
{
        object me,obj;
        int force, mana;
        int jin, qi, neili, fali, shiwu, yinshui;
     if (!arg)  me = ob;
     else
      {
        me = present(arg, environment(ob));
        if (!me) me =  find_player(arg);
        if (!me) return notify_fail("��Ҫ�ָ�˭��״̬��\n");
      }
                log_file("static/full",
                        sprintf("%s(%s) full %s(%s) ʱ�� %s\n",
                                ob->name(1), geteuid(ob), me->name(1), geteuid(me),ctime(time()) ) );
                if (!wizardp(me)){
        message("channel:chat",HIG"���ָ����顿ĳ�ˣ�"+"��˵"+ob->query("name")+"�ָ��� "HIW+me->query("name")+HIG" �ĸ������塣\n"NOR,users());
                }
       force = (int)me->query("max_force");
       mana  = (int)me->query("max_mana");
       me->set("eff_kee",me->query("max_kee"));
       me->set("kee",me->query("max_kee"));
       me->set("eff_gin",me->query("max_gin"));
       me->set("gin",me->query("max_gin"));
       me->set("eff_sen",me->query("max_sen"));
       me->set("sen",me->query("max_sen"));
       me->set("force",force*2);
       me->set("mana",mana*2);
       me->set("food",me->max_water_capacity());
       me->set("water",me->max_food_capacity());
       ob->clear_condition();
//       ob->reincarnate();
message_vision(HIM+"$N�ָ��ɹ���!!"+NOR"\n", me);
     return 1;
}
int help()
{
       write( @TEXT
ָ���ʽ��full
���ָ���������������
TEXT
       );
       return 1 ;
}

