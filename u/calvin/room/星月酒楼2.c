#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��¥����");
  set ("long", @LONG

���ﲼ�þ�Ȼ,�������� ... ...
LONG);

  set("outdoors", 1);
  set("exits", ([ /* sizeof() == 2 */
    "down" : "/u/calvin/room/���¾�¥",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

  setup();
}
