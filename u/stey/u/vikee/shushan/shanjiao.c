//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

��������ɽ��ɽ�š�
LONG);
set("exits", ([ /* sizeof() == 4 */
"south" : __DIR__"road1",
"northup" : __DIR__"path1",
]));

        set("outdoors", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
