#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "�� �� ��" NOR);
set ("long", @LONG

          ڤ  ˼  ��  ��         ��  ��  ��  ��

LONG);
set("exits", ([
"east": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("sleep_room",1);
set("if_bed",1);
set("objects", ([
__DIR__"obj/rack": 1,
]) );
setup();
}
