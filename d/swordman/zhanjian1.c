// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mս�����[2;37;0m");
  set ("long", @LONG

����ս������ڴ���ǰ����ǳ�����ս�����ȣ�������ɬ���㲻�ɵ÷���
��ǰ���ĽŲ���
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"haitan",
  "north" : __DIR__"zoulang1",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard" : 2,
]));

  setup();
}

int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"ʮ���н���"NOR){
        if (objectp(present("jian ke", environment(me))))
        return notify_fail("ʮ���н��ͺὣ������ǰ���ô�˽���صأ��ⲻ��������\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}