// bed : /u/fayu/bed.c
inherit ROOM;
void create ()
{
set ("short",  "����");
set ("long", @LONG
     �����Ǻڶ��;�Ө�Ĵ���
     ���������˰ٺ�
     ��׽�׵ģ��������ˡ�
LONG);

set("exits", ([
"out" : "/u/fayu/bedroom.c",
]));  
set("no_fight",1);
set("sleep_room", 1);
set("valid_startroom", 1);
set("no_clean_up", 0);
       setup();
}
