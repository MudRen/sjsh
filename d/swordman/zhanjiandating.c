// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37mս������[2;37;0m");
  set ("long", @LONG

����ս����־־����ʵ��������ȡ�����ձ���Ҫ�ĵ��ߣ�����������
����ս����ָ�����ġ�־־����ʵ���������ڴ����ľ�ͷ���õ����
�۹�ע�����㡣
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"zhanjianqianting",
  ]));
  
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhizhixiong" : 1,
  __DIR__"npc/youmei":1,
]));

  setup();
}
