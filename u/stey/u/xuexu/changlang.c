#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIR" ���� "NOR);
set ("long", @LONG

һ���޾��ĳ��ȣ������ƺ���ͨ��һ���ط�ȥ�ġ�һ����ò�׺ݵľ���
��ס�����ȥ·����̧ͷ��ȥ�����ɵ���������һ����

LONG);
set("exits", 
([ //sizeof() == 2
"west" : "/u/xuexu/workroom",
"east" : "/u/xuexu/jobroom",
]));
set("no_time", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/npc/luohou" : 1,
]));
setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "east" ) {
if (objectp(present("luo hou", environment(me))))
return notify_fail("�޲T�ȵ��������Ǳ���֮�أ�Ҫȥ�ȹ����Ϸ���أ�\n");
}   
return ::valid_leave(me, dir);
}
