
//Room: jldongkou.c ���϶���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","���϶���");
	  set("long",@LONG
���϶����ɷ����⡣��˵Զ��ʱ���о�λ����ס����������֪����
���ں��꣬���ں��ꡣ��ԯ�ʵ۷õ��ڴˣ���һ���ţ���Ի�������º�������
Ի�������ˡ�������Ǿ��϶������������������������˽�ȥ��ֻ��Щ��
վ�ڶ���̸Ц���У�chat����������������ʮ�ŵ��յ�ǧ���֣�һ·�򱱵���
��ʯ��
LONG);
	  set("objects", ([
           __DIR__"npc/little_monkey" : 1,
	  ]));
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "enter"	 : __DIR__"jiulaodong",
	  "northwest" : __DIR__"lianhuashi",
	  ]));
//	  set("no_clean_up", 0);
	  setup();
}

void init()
{
	add_action("do_chat", "chat");
}

int do_chat(string arg)
{
	object me;

	me = this_player();
	message_vision("$Nվ�ڶ��������У���0��\n", me);
	write("���ڴ���һ���������0������0������0��������\n");
	return 1;
}
