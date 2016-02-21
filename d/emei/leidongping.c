
//Room: leidongping.c �׶�ƺ
//Date: Oct. 2 1997 by That
#include <ansi.h>
inherit ROOM;

void create()
{
	  set("short","�׶�ƺ");
	  set("long",@LONG
�׶�ƺһ������·���պ��ˣ�·���Ǳ����������ɼ�֣�·���������
�ľ���Ͽ�ȡ����ﳤ���������֣����ɺڰ������Ͻ��������Ա���һ������
�ɴ������ǡ���ʮ�ŵ��ա��͡���ʮ���̡�ֱ����������µ�ϴ��ء�
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
message_vision(CYN"$N��˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����\n"NOR, me);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		   {
		  me->improve_skill("force", kee_cost+sen_cost);
		  }
	   me->receive_damage("kee", kee_cost );
	   me->receive_damage("sen", sen_cost );
	  }
	  else
	  {
	   message_vision(CYN"$N��˵��һ���֣�ɲ�Ǽ侪��Ѹ�磬�������������걩����
$Nһ���ӱ����У�ȫ���顣\n"NOR, me);
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
	 tell_object(me,HIW"�����Ͼ�ʮ�ŵ��գ���Щ���ˡ�\n"NOR);
	  }
	  return 1;
}

