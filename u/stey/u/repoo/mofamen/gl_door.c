// by Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIW"�����ǳ���"NOR);
  set ("long", @LONG
ֻ������ŷǽ��ľ��ʯ;��������һ��ֻʣ
�Ǽܵ�����������Χ�������ǰ׹ǡ�
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"glcity",
]));
  create_door("southwest", "�����ǳ���", "northeast", DOOR_CLOSED);
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
