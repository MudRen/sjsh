//�����������صİ�Ȩ����,ϣ���õ��������վ����ͱ�����ϵ!
//лл���,ϣ����Ҳ�Ҫ�Ҹĳ���,лл!
//edit by leox 2001/05/29
#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "��ȫ����");
        CHANNEL_D->do_channel( this_object(), "sys", "\n�Զ���ȫ����ϵͳ�Ѿ�������\n");
        call_out("auto_clear", 10);
}

void auto_clear()
{
        int i,mem;
        object *ob, link_ob;
        string id;
        CHANNEL_D->do_channel( this_object(), "sys",
     sprintf("ϵͳ�Զ���� " + reclaim_objects() + " ���������ݰ��ͷ������\n"));
        remove_call_out("auto_clear");
        call_out("auto_clear", 480+random(120));
}
