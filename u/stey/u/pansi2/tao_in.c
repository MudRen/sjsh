#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "�һ�����");
        set("long",@LONG
����һƬ�һ��ĺ�������һ���޼ʣ�ȫ��ʢ�����һ���΢�������
��Ӣ�ͷס���Χ�����ĵġ�Զ��ż������һ����С�������һƬ��
���֣�����ԶԶ������ֻ���ӡ�
LONG );
       set("exits", ([
           "south" : "/d/dntg/hgs/houshan3",
           "north" : __DIR__"tao0",
       ]));
	   set("objects",([
		__DIR__"npc/xiang" : 1,
	]));

       set("outdoors","taohua");
//       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
void init()
{
        object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/south")) 
			 myfam = (mapping)ob->query("family");
			if(myfam && myfam["family_name"] == "��˿��")
        {
        delete("exits/south");
        set("exits/south", "/d/dntg/hgs/houshan3");
	return ;
        }       
        if ((int)ob->query_skill("spells",1) >= 100 )
        {
        delete("exits/south");
        set("exits/south", __DIR__"tao0");
	return ;
        }

             
	delete("exits/south");
        set("exits/south", __DIR__"/d/dntg/hgs/houshan4");
}
