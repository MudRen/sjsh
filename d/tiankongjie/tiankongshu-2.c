// Room: /d/tiankongjie/tiankongshu-2.c

inherit ROOM;

void create()
{
        set("short", "������ڶ���");
        set("long", @LONG
�����������ĳ����ء�������Ϊ�������������ʰ�����Ϊ������֪��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-1",
  "down" : __DIR__"tiankongshu-3",
]));

        setup();
        replace_program(ROOM);
}
