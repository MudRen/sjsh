
//Room: huacangan.c ������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	  set("short","������");
	  set("long",@LONG
�������ǽ𶥵���Ҫ��������ģ������������������������
LONG);
	  set("outdoors", "emei");
	  set("exits",([ /* sizeof() == 1 */
	  "enter"	  : __DIR__"hcazhengdian",
	  "north"	  : __DIR__"jinding",

	  ]));
	  set("no_clean_up", 0);
	  setup();
	  replace_program(ROOM);
}
