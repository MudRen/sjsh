// Room: /d/tiankongjie/tiankongshu-5.c

inherit ROOM;

void create()
{
        set("short", "����������");
        set("long", @LONG
��¥�����ĳ����ء�����з����Ÿ��ָ��������ࡣ��˹��Ĺ�âҫ�۶�Ŀ��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"tiankongshu-4",
  "down" : __DIR__"tiankongshu-6",
]));
  set("objects", ([ /* sizeof() == 4 */
  __DIR__"npc/lijia" : 1,
]));

        setup();
        replace_program(ROOM);
}
