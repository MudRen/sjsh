// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mս��ǰ��[2;37;0m");
  set ("long", @LONG

����ս����־־����ʵ��������ȡ�����ձ���Ҫ�ĵ��ߣ�����ǰȥ��
������ս����ָ�����ġ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zoulang3",
   "north":__DIR__"zhanjiandating",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zongcilang" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"ʮ���н���"NOR){
        if (objectp(present("zongcilang", environment(me))))
        return notify_fail("�ڴ���΢Ц��˵����־־�۴��˲������˴��������������ذɡ�\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
