// by Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"骨龙城城门"NOR);
  set ("long", @LONG
只见这城门非金非木非石;上面雕刻这一条只剩
骨架的龙。城门周围到处都是白骨。
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"glcity",
]));
  create_door("southwest", "赤龙城城门", "northeast", DOOR_CLOSED);
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
