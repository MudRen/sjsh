#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "�� ��" NOR);
set ("long", @LONG

          ��  ��  Ū  ī         ��  ��  ʶ  ��

LONG);
set("exits", ([
"south": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("objects", ([
__DIR__"obj/table": 1,
]) );
setup();
}
