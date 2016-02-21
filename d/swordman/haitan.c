
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "海滩");
        set ("long", @LONG

一艘漆黑巨大的战舰停靠在岸边，远远的便可以看到两个凶神
恶煞般的人物守在船旁。
LONG);

      
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"crass4",
  "enter" : __DIR__"zhanjian1",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 2,
]));

  setup();
}


int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"十本刃剑客"NOR){
        if (objectp(present("jian ke", environment(me))))
        return notify_fail("十本刃剑客横剑挡在面前：擅闯私人重地，这不是找死吗？\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
