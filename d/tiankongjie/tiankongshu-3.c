// Room: /d/tiankongjie/tiankongshu-3.c

inherit ROOM;

void create()
{
        set("short", "�����������");
        set("long", @LONG
�����ʦ�������ĳ����ء�����Ʈɢ����������������ƺ�����������˶���ϲ
�����֡�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-2",
  "down" : __DIR__"tiankongshu-4",
]));

        setup();
        replace_program(ROOM);
}

