#include <ansi.h>
#pragma save_binary

inherit F_DBASE;

void auto_save();

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�ڴ澫��");
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
        remove_call_out("auto_clear");
        call_out("auto_clear", 480+random(120));
}
