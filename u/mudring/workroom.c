// Room: /u/mudring/workroom.c

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","��֮��");
  set ("long", @LONG

............................................................................................
............................................................................................
............................................................................................
............................................................................................
............................................................................................

LONG);
  set("exits", ([ /* sizeof() == 4 */
  "north" : "/d/wiz/wizroom",
  "down" : "/d/city/kezhan",
]));
  set("valid_startroom", 1);
set("outdoors", "������");
  setup();
}

void init()
{
    if (this_player()->query("id") != "mudring")
        message_vision("$N͵͵���˹�����\n", this_player());
    if (this_player()->query("id") != "mudring")
        message_vision("��������һƬ����"+this_player()->name(1)+"���Ŀں�����$N��װû������\n", this_player());
}

int clean_up()
{
    return 0;
}

void reset()
{
        tell_room(this_object(), BLINK+HIR"Reset.\n"NOR);
        ::reset();
}

