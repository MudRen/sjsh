// Room: /d/tiankongjie/diyu.c

inherit ROOM;

void create()
{
        set("short", "����Ѫ��");
        set("long", @LONG
�������ǳ�����ɫ�������������ƺ�����������Ҳ�������������塣
LONG
        );
        set("no_clean_up", 0);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xiewu" : 1,
]));


        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"pingchengmen",
]));

        setup();
        replace_program(ROOM);
}
