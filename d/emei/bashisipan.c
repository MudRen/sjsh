
//Room: bashisipan1.c ��ʮ����
//Date: Oct. 2 1997 by That

inherit ROOM;
#include <ansi.h>
void create()
{
	  set("short","��ʮ����");
	  set("long",@LONG
���������ġ���ʮ���̡�����·���ն��ͣ��ػ����ۣ����˲��ܴ�Ϣ��·
���Ǳ����������ɼ�֣�·��������׵ľ���Ͽ�ȡ��ɴ��������������
�µ�����ʮ�ŵ��ա���
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
          "southeast"  : __DIR__"jieyindian",
          "eastdown"  : __DIR__"jsjdg",
	  ]));
	  set("no_clean_up", 0);
	  setup();
}
int valid_leave(object me, string dir)
{
	  int c_exp,c_skill;
	  me = this_player();
	  if (dir == "southeast" )
	  {
	 c_exp=me->query("combat_exp");
	 c_skill=me->query_skill("dodge",1);
	 me->add("kee",-100);
	 if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
		 me->improve_skill("dodge", (int)me->query_skill("dodge", 1));
	 tell_object(me,HIW"�����ϰ�ʮ���̣����ڵ��������ˣ������ˡ�\n\n"NOR);
	  }
	  return 1;
}

