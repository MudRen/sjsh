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
    "down" : "/d/calvin/lanling/xingyuejiulou",
]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

  setup();
}
