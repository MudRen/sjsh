#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIR"�� ��"NOR);
set("long", @LONG

           ��  ��  ��  ��         ��  ��  ˼  ��

LONG);
set("valid_startroom", 1);
set("no_fight", 1);
set("no_magic", 1);
set("no_sleep", 1);
set("no_quit", 1);
set("no_clean_up", 1);
set("outdoors", 0);
setup();
}
void init()
{
if (!wizardp(this_player()))
{
this_player()->set("startroom","/u/immortal/prison");
this_player()->save();
add_action("block_cmd","",1);
}
call_out("hehe", 2, this_player());
}
int block_cmd()
{
string verb = query_verb();
if (verb=="say") return 0;
if (verb=="help") return 0;
if (verb=="look") return 0;
return 1;
}
