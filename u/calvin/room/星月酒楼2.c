#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "二楼雅座");
  set ("long", @LONG

这里布置井然,有条不理 ... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "down" : "/u/calvin/room/星月酒楼",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

  setup();
}
