// Room: /d/mojie/zuodian
inherit ROOM;

void create()
{
  set ("short", "��ƫ��");
  set ("long", @LONG
����һƬħ��֮�����������һ�߾Ÿ�ʯ�����������ʮ����ħ
��֮�񣬸��������ֲ������˲���������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dadian",
]));
  set("objects",([
  __DIR__"npc/juxie" : 1,
]));
  setup();
  replace_program(ROOM);
}
