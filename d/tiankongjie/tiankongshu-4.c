// Room: /d/tiankongjie/tiankongshu-4.c

inherit ROOM;

void create()
{
        set("short", "��������Ĳ�");
        set("long", @LONG
������ĳ�����, Ҳ�ǹ���֮Ȫ���ڵĵط����˵��������ƺ�Ҳ�о����Ŀ�������
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/jixiangtian" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-3",
  "down" : __DIR__"tiankongshu-5",
]));

        setup();
        replace_program(ROOM);
}
