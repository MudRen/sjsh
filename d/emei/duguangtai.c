
//Room: duguangtai.c �ù�̨
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","�ù�̨");
	  set("long",@LONG
�����ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ������޵ף�����
���ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ��
�������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���
̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ������
�����г�������֮�⡣
LONG);
	  set("objects", ([
           __DIR__"npc/dan" : 1,
	  ]));
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "west"	 : __DIR__"dgtsheshenya", 
	  ]));
//	  set("no_clean_up", 0);
	  setup();
	  replace_program(ROOM);
}
