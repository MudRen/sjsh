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
  "north" : __DIR__"zhanjianqianting",
  "south" : __DIR__"zoulang2",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/yushui" : 1,
]));

  setup();
}
int valid_leave(object me, string dir)
{       if (dir == "north") {
        if((string)me->query("title")!=WHT"ʮ���н���"NOR){
        if (objectp(present("yushui", environment(me))))
        return notify_fail("��ˮ�ὣ������ǰ���ܹ�ǿ���ҵĻ�������Դ����ȥ��\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
