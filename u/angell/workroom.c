inherit ROOM;
#include <ansi.h>

void create()
{
  set ("short","��ʹ֮��ļ�");
        set("long", HIC@LONG

          ___     ____    . .     . .    _  |
         __|__   `|_|_   -|-|-   .|_|_   L|-|-
          / \    `|=|=   _|_|_   || |    L|`|
         /   \   /j_|_   /   \   ---`-      J

     ________________O___o__._______________________/
                    ----- --------------------  -  ---
LONG NOR);
 set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/wiz/wizroom",
  "out" : "/u/angell/room",
  "up" : "/d/wiz/entrance",
  "center" : "/d/city/center",
  "kz" : "/d/city/kezhan",
]));
  set("objects", ([ /* sizeof() == 1 */
  //"/u/angell/obj/angell_b.c" : 1,
]));
        set("no_time",1);
        set("freeze",1);
        set("no_magic",1);
        set("no_fight", 1);
       set("valid_startroom", 1);
        
        setup();
        replace_program(ROOM);
      call_other("/obj/board/angell_b", "???");
}

