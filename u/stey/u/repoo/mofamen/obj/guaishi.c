//By Repoo
// guaishi.c

#include <ansi.h>
inherit ITEM;

void create()
{
         set_name(RED"奇怪的石头"NOR, ({"guai shi", "shi", "stone"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","一块大石头,看上去象一根神杖。");
                set("weight", 4000);
                 set("no_get","这东西拿不起来！\n");
        }
        setup();
}
void init()
{
  add_action("do_hammer", "hammer");
}

int do_hammer(string arg)
{       
  object me;
  me=this_player();
  if ( !present("hammer", me) || (arg != "stone"))
    return notify_fail("你挥起拳头往石头上砸去，砸的满手都是鲜血！\n");
  else
    message_vision("$N挥舞大锤，往石头上砸去．\n", me);
  if((int)me->query_temp("mark/怪石") < 1)
    {
    me->set_temp("mark/怪石", 1);
  }
  me->add_temp("mark/怪石", 1);
  me->receive_damage("kee", 40);
   if((int)me->query_temp("mark/怪石") > 3)
    {
    message_vision("$N把石头砸成了三块。\n", me);
 message("system", HIW"一道白光闪过，消失在东方。\n"NOR+HIG"\n一道绿光闪过，消失在西方。\n"+HIR"\n一道红光闪过，消失在南方。\n\n"NOR,users());
 message("channel:rumor",YEL+"【"+HIB" 八部天龙 "NOR+YEL"】某人："+me->query("name")+"把奇怪的石头砸成了三块，分别向东、西、南三个方向飞去！\n"+NOR,users() );
    me->set_temp("mark/怪石", 1);
     destruct(this_object());
    return 1;
}
  return 1;
}
