// Room: /d/tiankongjie/tianshoudao.c

inherit ROOM;

void create()
{
        set("short", "���ֵ�");
        set("long", @LONG
������̤����ս�����塣������һƬ��ɫ�Ĳݵĺ���
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"pingchengmen.c",
  "enter" : __DIR__"yueguangku.c",
]));

        setup();
        replace_program(ROOM);
}
