//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","������" );
        set ("long", @LONG

���ǳ�����һ�����ֺŵ�ҩ�̵����ã���ҽ��٢����������
�·��������ˣ�����Ը���ѧЩҽ����
LONG);

        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"yaopu",
                "east" : __DIR__"yaofang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shenyi" : 1,
        ]));


        set("no_fight", 1);
        set("no_magic", 1);
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


