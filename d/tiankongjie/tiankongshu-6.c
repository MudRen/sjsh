// Room: /d/tiankongjie/tiankongshu-6.c

inherit ROOM;

void create()
{
        set("short", "�����������");
        set("long", @LONG
��ս�ľ����ס�ĵط������������У�һƬ���ٵľ���
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-5",
  "down" : __DIR__"tiankongshu-7",
]));

        setup();
        replace_program(ROOM);
}
