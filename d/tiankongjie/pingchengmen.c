// Room: /d/tiankongjie/pingchengmen.c

inherit ROOM;

void create()
{
        set("short", "ƽ����");
        set("long", @LONG
������Ϳ��Խ�����ս��ˡ���ս�Ĵ��š���ΰ����ս����ΡȻ�����������������������ŷ�����ڡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "down" : __DIR__"diyu.c",
  "southdown" : __DIR__"tianshoudao.c",
  "up" : __DIR__"tiankongshu-7.c",
]));
//  set("objects", ([ /* sizeof() == 4 */
//  __DIR__"npc/heimukai" : 1,
//]));

        setup();
        replace_program(ROOM);
}

