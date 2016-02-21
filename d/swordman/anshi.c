inherit ROOM;
void create ()
{
  set ("short","暗室");
  set ("long", @LONG

一间阴暗的房间，房间的大门(men)紧紧地关闭着，看来不推开门是走不
出这里的。房间的正中站着一个十多岁的少年,与他年龄不相符的是那冰
一般的眼神以及无法克制住的摄人杀气。
LONG);
   set("exits", ([      
  ]));
   set("objects", ([ 
      __DIR__"npc/mingshen" : 1,
       ]));
  set("no_magic", 1);
  set("no_quit", 1);
  setup();
}

void init()
{
  add_action("do_push", "push");
}

int do_push(string arg)
{
  object me=this_player();

  int delay;
  if ((arg != "men" && arg != "门") || !arg)
  return notify_fail("你要推什么？\n");
  if (me->is_busy()) return notify_fail("你忙着呢！\n");
  if (me->query_temp("no_move")) return notify_fail("你被定住了，什么也干不了。\n");

  message_vision("\n$N用尽全身的力气推向大门，只听一阵“轧轧”声过后，大门倒是
缓缓地打开了，自己却累得动弹不得。\n", me);
  delay=7;
  me->start_busy(delay);
  me->start_call_out( (: call_other, __FILE__, "delay_effect", me, delay:), delay);
  return 1;
}

void delay_effect(object me,int power)
{
        mapping action;
        mapping new_act=([]);
         message_vision("\n$N擦了擦汗，赶紧闪进了门内，石门随即又合上了。\n\n", me);
        me->move(__DIR__"zhanjiandating");
}
