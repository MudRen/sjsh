// Room: /d/tiankongjie/tiankongshu-1.c

inherit ROOM;

void create()
{
        set("short", "���������");
        set("long", @LONG
��յ����Χ������������ڵء�����������������
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yintuoluo" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"shenxiang.c",
  "down" : __DIR__"tiankongshu-2",
]));

        setup();
        replace_program(ROOM);
}
