//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
  set ("short", "山脚");
  set ("long", @LONG

这里是蜀山的山脚。
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
