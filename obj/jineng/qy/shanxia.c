// ҩ�� ·�� shanxia by Calvin

inherit ROOM;
void create()
{
  set ("short", "ɽ��");
  set ("long", @LONG

����һ�����Ͽ�,ʵ���ǿ�������,�߸ߵ�����,�е�����������η��

LONG);

  set("exits", ([ 
  ]));

  set("outdoors", __DIR__"");
  setup();
}

void init ()
{
  add_action ("do_climb","climb");
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
  who->move(__DIR__"shanpo");
  return 1;
}
