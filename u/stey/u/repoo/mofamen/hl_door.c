// by Repoo
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", HIB"�����ǳ���"NOR);
  set ("long", @LONG
ֻ������ŷǽ��ľ��ʯ;��������һ����ɫ
�ľ����������ӣ�Ӧ���Ǻ����ǵĻ�����
LONG);
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"hlcity",
]));
  create_door("east", "�����ǳ���", "west", DOOR_CLOSED);
  set("objects", ([
]));
  set("outdoors", 1);
  setup();
}
