// ҩ�� ·�� shanxia by Calvin
#include <room.h>
inherit ROOM;
int grass_number;
void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

������ɽ��֮��,һ�ۿ���ȥȫ�ǹ������ʯͷ,��������һ��
�ƺ��и�СС��ɽ���������ɽ���ϳ��ŵ�С���ƺ�����һ��
�ϵȵ�ҩ��,��������Բɼ�һ�����ȥ����һ�¡�

LONG);

  set("exits", ([ 
  ]));

  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
  add_action ("do_jump","jump");
 add_action("do_dig", "dig");
 grass_number=1;
}

int do_climb (string arg)
{
  object who = this_player();

  message_vision ("$N����������ȥ��\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)
  {
    message_vision ("$N��һ�����˴�ʯ����һ������������\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"shanpo1");
  return 1;
}

int do_jump (string arg)
{
  object who = this_player();
  message_vision ("$N����������ȥ��\n",who);
  if (who->query("combat_exp") < 5000 ||
      who->query("kee") < 100)
  {
    message_vision ("$N��һ�����˴�ʯ����һ������������\n",who);
    who->unconcious();
    return 1;
  }
  who->add("kee",-100);
  who->move(__DIR__"shanxia");
  return 1;
}


 int do_dig(string arg)
{
   object me = this_player();
   object cao;
   if ( !arg || ( arg != "grass" ) ) 
     return notify_fail("��Ҫ��ʲô��\n");
   else if(grass_number==0)  
     return notify_fail("ҩ���Ѿ����ι��ˣ���Ѿ��ˡ�\n");
   else if(me->query("kee")<100) 
     {
     me->unconcious();
     return 1;
     }
   else 
     {
     me->add("kee",-100);
     cao = new ("/obj/jineng/medicals/tianqi.c");
     cao->move(me);
     message_vision("$N����һ��ҩ�ݡ�\n", me);
     grass_number--;
     }
     return 1;
}
