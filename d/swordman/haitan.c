
#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", "��̲");
        set ("long", @LONG

һ����ھ޴��ս��ͣ���ڰ��ߣ�ԶԶ�ı���Կ�����������
��ɷ����������ڴ��ԡ�
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
        if((string)me->query("title")!=WHT"ʮ���н���"NOR){
        if (objectp(present("jian ke", environment(me))))
        return notify_fail("ʮ���н��ͺὣ������ǰ���ô�˽���صأ��ⲻ��������\n");

        }

        return ::valid_leave(me, dir);
        }
        return ::valid_leave(me, dir);

}
