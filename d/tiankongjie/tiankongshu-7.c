// Room: /d/tiankongjie/tiankongshu-7.c

inherit ROOM;

void create()
{
        set("short", "��������߲�");
        set("long", @LONG
�������ĳ����ء��������ڱ������֮����ԭ������, �����������������������ԭҰ�����ġ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-6",
  "down" : __DIR__"pingchengmen.c",
]));

        setup();
        replace_program(ROOM);
}
