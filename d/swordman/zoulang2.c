// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mս������[2;37;0m");
  set ("long", @LONG

������ս�����ȣ�������ɬ�����������Ļ�ѹ�����������ս������
�˹��ص�ɫ�ʡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zoulang3",
  "south" : __DIR__"zoulang1",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/anci" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"ʮ���н���"NOR){
        if (objectp(present("anci", environment(me))))
        return notify_fail("����̧ͷ������һ�ۣ�����˵�����ⲻ��������ĵط���\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
