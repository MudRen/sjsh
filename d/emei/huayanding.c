
//Room: huayanding.c ���϶�
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","���϶�");
	  set("long",@LONG
���϶�ͦ�θ��ͣ���ɲ���������ʣ��羰���ա�������Ұ����������
����ΡΡ��������Ⱥ�����У����׷�ɽ�����ԺҲ���۵ס��ɴ�������ʮ
���̣���������ʯ��������һ����ǡ�
LONG);
	  set("objects", ([
           __DIR__"npc/yingke" : 1,
	  ]));
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
          "northup"   : __DIR__"shierpan",
	  ]));
//	  set("no_clean_up", 0);
	  setup();
	  replace_program(ROOM);
        "obj/board/emei_b"->foo();

}

