// xiuxishi.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR "��" HIY "����" HIR "��" NOR);
	set("long", @LONG

�ܼ�ª��һ�����ң�������ǽ�Ǽ��Ŵ����������û�������İ�
����Ʒ�ˡ�
LONG
	);
        set("exits", ([
	    	     "south" : __DIR__"workroom",
                                 "east":__DIR__"mishi",
		]));

           set("sleep_room",1);  
       setup();
	replace_program(ROOM);
}

