//by koker@SJSH and thanks pote

#include <ansi.h>
void done(object me);
//inherit F_YAO;
int main(object me, string arg)
{
        object ob;
        object ob1, ob2,ob3,ob4,ob5,ob6;
        int lv;
        lv=me->query_skill("medical",1);

        seteuid(getuid());

        if( me->is_busy() )
        return notify_fail("����æ���ء�\n");

        if( !arg )
        return notify_fail("��Ҫ��ʲôҩ��\n");
        
        if( me->is_fighting() )
        return notify_fail("������ս������ʲôҩ����\n");

        if(me->query("sen")<=50)
	return notify_fail("������̫���ˣ���Ϣ��Ϣ�ɣ�\n");

        if(me->query("force")<50) 
	return notify_fail("�������������������ʲô�ˡ�\n");
        
        if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("����æ���أ�ûʱ����ҩ��\n");
//������ҩƷ
     switch (arg)
      {
case "jinchuang":
        ob1 = present("hong hua", me) ;
        ob2 = present("tian qi", me) ;
        if (!ob1 || !ob2)
              return notify_fail("���ҩ�Ĳ���ȫ��\n");
        if( lv < 20 )
        return notify_fail("���ҽ�������Ƴ���ҩ��\n");
        ob1->set("done", 1);
        ob2->set("done", 1);
done(me);
        ob=new("/obj/jineng/obj2/jinchuang.c");
        ob->move(me);
        me->add("sen",-20);
        me->add("force",-50);
        me->start_busy(1);

        break;

case "hunyuandan":
        ob1 = present("hu gu", me) ;
        ob2 = present("du huo", me) ;
        if (!ob1 || !ob2)
              return notify_fail("���ҩ�Ĳ���ȫ��\n");
        if( lv < 25 )
        return notify_fail("���ҽ�������Ƴ���Ԫ����\n");
        ob1->set("done", 1);
        ob2->set("done", 1);
done(me);
        ob=new("/obj/jineng/obj2/hunyuandan.c");
        ob->move(me);
        me->add("sen",-20);
        me->add("force",-50);
        me->start_busy(1);

        break;

       default:   notify_fail("��û������������ҩ��\n");       
        }
        return 1;
}

void done(object me)
{
        int i;
        object *inv; 
               inv = deep_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("done"))
                        destruct(inv[i]);
                }
message_vision( HIC "ֻ��$N��������ҩ��֮�ϣ������ҩ�ı���ʧ�ˡ�\n" NOR,me);
                me->start_busy(1);
return;
}
