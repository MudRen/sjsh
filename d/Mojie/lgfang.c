// Room: /d/mojie/lgfang.c
inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG
������ħ��ĵ������������������ĵط��������и�ʽ�����ı�����

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"guodao2",
]));
  set("objects", ([ 
   __DIR__"npc/xiongmo" : 1,
]));
  setup();
  replace_program(ROOM);
}
