// Room: /d/tiankongjie/shenxiang.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��յ���������������������ƺ�����ս���쵼���ࡣ�������졣
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huiming" : 1,
]));
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tiankongshu-1",
]));

        setup();
        replace_program(ROOM);
}
