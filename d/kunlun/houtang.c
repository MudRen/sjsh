//kunlun
inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "����");
        set ("long", @LONG

����һ��ʯ�ң�����ֻ��һλ�ϵ���������ȫ��ʯ�ڣ�
ֻ�е��������һ����ϸ������(rope)ͨ������һ�ߣ�
���������(climb) ��
LONG);

           set("item_desc", ([ /* sizeof() == 1 */
  "rope" : "һ�����ӡ�",
]));

         
        set("exits", 
  ([ //sizeof() == 2
                "south" : __DIR__"mishi",
        ]));
        set("objects", ([
                __DIR__"npc/guang" : 1,

   ]));
       setup();
}

void init()
{
  add_action("do_climb", "climb");
}



int do_climb(string arg)
{
  object me=this_player();
 
  if( (!arg) || !((arg == "rope") || (arg == "����")))
    return notify_fail("��ʲô��\n");
	  message_vision(HIR"$N��ǰһ��,�����˻����С�\n"NOR, me);
          me->move(__DIR__"hundun");
      return 1;
}
