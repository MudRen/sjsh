#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���羫��");
        CHANNEL_D->do_channel( this_object(), "sys", "\n�Զ��ڴ����ϵͳ�Ѿ�������\n");
        call_out("auto_clear", 10);
}

void auto_clear()
{
        int i,mem;
        object *ob, link_ob;
        string id;
        CHANNEL_D->do_channel( this_object(), "sys",
                sprintf("ϵͳ�Զ���� " + reclaim_objects() + " ��������\n"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("��վip��ַ:210.34.120.6 6666(7777��8888)"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("��վ��վ��ַ:http://zmud.7i24.com"));
        CHANNEL_D->do_channel( this_object(), "chat",
                sprintf("��վ��ַ:http://xlqysjsh.51.net"));
        remove_call_out("auto_clear");
        call_out("auto_clear", 1200+random(120));
remove_call_out("init_dynamic_quest");
  TASK_D->init_dynamic_quest(1);
    write("����ϵͳ TASK ���!\n");
    rm("/log/dlog/money");
    if (random(5)==1) rm("/log/debug.log"); //��ֹdebug very big
    rm("/log/monitord");
     "/adm/daemons/money"->move_money();
     "/adm/daemons/money"->move_money();
//     "/adm/daemons/money"->move_money();
//     "/adm/daemons/money"->move_money();
     "/adm/daemons/money"->move_money();
}
