// ҽ�������ƹ���
//by koker@sjsh 2001/11

#include <ansi.h>
inherit F_CLEAN_UP;

//int do_heal(object me, object obj, object who);

//void create() { seteuid(getuid()); }

int main(object me, object target)
{
        
        object obj, who;
        int lv;
        lv=me->query_skill("medical",1);
        if(this_player()->is_busy())
           return notify_fail("����æ���أ�����\n");
                                 
        //if( !target)
        //   return notify_fail("��Ҫ��˭���ˣ�\n");

        //if( !objectp(obj = present(target, environment(me))))
         //       return notify_fail("����û������ˡ�\n");
        if((int)me->query_skill("medical",1)<1)
		return notify_fail("�㻹����ҽ��,�������ˡ�\n");
        if((int)me->query("force")<50) 
		return notify_fail("��������������������ˡ�\n");
	if((int)me->query("sen")<=50)
		return notify_fail("������̫���ˣ���Ϣ��Ϣ�ɣ�\n");
	if((int)me->is_fighting() )
                return notify_fail("ս�������ˣ�������\n");
       // if(wizardp(who)&&!wizardp(me)) 
        //       return notify_fail("��Ҫ��\n");
//if( who == me )  {
        
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
                return notify_fail("���Ѿ����˹��أ�ֻ�������ҽ���ǲ����κõģ�\n");
               message_vision("$N���ȶ�����ȫ������һ��"HIW"����"NOR"����ɫ����"HIR"����"NOR"������\n", me);
        me->receive_curing("kee", 20 + lv );
       me->add("force", -50);
        me->set("force_factor", 0);
               // return 1;
 //       }
//else{if( (int)me->query("eff_kee") < (int)me->query("max_kee") / 2 )
//                return notify_fail("���Ѿ����˹��أ�������������ơ�\n");
  //      if( (int)me->query("eff_kee") < (int)target->query("eff_kee"))
    //            return notify_fail("$n����Ҫ������ƣ�\n");
      //  message_vision(HIW"$Nһ������$n���ģ�˳�������������������͹�ȥ��$n�������ö��ˡ�//\n"NOR, who,target);
//        target->receive_curing("kee", (50 + lv)/2 );}
       
     return 1;    
}


int help(object me)
{	
	write(@HELP
ָ���ʽ : heal [<ĳ��>]

����:���Ը��Լ������˿�Ҳ���Ը��������ơ�
     ����ʱֻ���Ÿ��Լ����ƵĹ��ܡ���

HELP
    );
    return 1;
}
