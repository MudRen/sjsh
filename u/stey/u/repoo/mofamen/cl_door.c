// by Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", HIY"�����ǳ���"NOR);
  set ("long", @LONG

ֻ������ŷǽ��ľ��ʯ;��������һ����ͮͮ
��������������ƣ��㵨�Ӷ��ŵ���һ�롣

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"clcity",
]));

  create_door("northwest", "�����ǳ���", "southeast", DOOR_CLOSED);

  set("objects", ([
]));

  set("outdoors", 1);

  setup();
}
