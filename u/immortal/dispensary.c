#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "ҩ ��" NOR);
set ("long", @LONG

          ұ  ��  ��  ҩ         ��  ��  ��  ��

LONG);
set("exits", ([
"north": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("objects", ([
"/u/immortal/obj/cabinet": 1,]));
setup();
}
