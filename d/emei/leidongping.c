
//Room: leidongping.c 雷洞坪
//Date: Oct. 2 1997 by That
#include <ansi.h>
inherit ROOM;

void create()
{
	  set("short","雷洞坪");
	  set("long",@LONG
雷洞坪一带，道路艰险骇人，路左是蔽日遮天的冷杉林，路右是深不见底
的绝壁峡谷。这里长年云遮雾罩，空蒙黑暗。岩上建有雷神殿，旁边竖一铁碑。
由此往上是「九十九道拐」和「八十四盘」直至接引殿，北下到洗象池。
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "northdown"  : __DIR__"lingyunti",
          "westup"     : __DIR__"jsjdg",
	  ]));
	  set("no_clean_up", 0);
	  setup();
}

void init()
{
   add_action("do_say","say");
}
int do_say()
{
	  object me;
	  int kee_cost,sen_cost,c_exp,c_skill;
	  me = this_player();
	  c_exp=me->query("combat_exp");
	  c_skill=me->query_skill("force",1);
	  kee_cost = 10+c_skill/2+random(c_skill/2);
	  sen_cost = kee_cost/4+random(kee_cost/4);

	  if (me->query("kee")>kee_cost+2 && me->query("sen")>sen_cost+2) 
	  {
message_vision(CYN"$N刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。\n"NOR, me);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		   {
		  me->improve_skill("force", kee_cost+sen_cost);
		  }
	   me->receive_damage("kee", kee_cost );
	   me->receive_damage("sen", sen_cost );
	  }
	  else
	  {
	   message_vision(CYN"$N刚说出一个字，刹那间惊雷迅电，霹雳而作，风雨暴来。
$N一下子被打中，全身发麻。\n"NOR, me);
                me->unconcious();
	  }
	  return 1;
}

int valid_leave(object me, string dir)
{
	  int c_exp,c_skill;
	  me = this_player();
	  if (dir == "westup" )
	  {
	 c_exp=me->query("combat_exp");
	 c_skill=me->query_skill("dodge",1);
	 me->add("kee",-100);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_exp< 101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"你爬上九十九道拐，有些累了。\n"NOR);
	  }
	  return 1;
}

