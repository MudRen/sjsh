inherit ROOM;

#include <ansi.h>

void create ()
{
  set ("short",HIC"帮派俱乐部"NOR);
  set ("long", @LONG

帮派都喜欢有自己的一个总坛，他们通常就是喜欢在总坛里面进行平
常的事务处理、开会、命令发布等事宜。俱乐部里面有一个持牌人，
你看他样子经常笑嘻嘻地就知道他是多么的友善了。

LONG);

  set("exits",([ "down" : "/d/city/changan", ]));
  set("objects",
  ([
  __DIR__"boss" : 1,
  __DIR__"topclub" : 1,
  ]));
  set("outdoors", 0);
  set("no_clean_up", 1);
  setup();
  replace_program(ROOM);
}
