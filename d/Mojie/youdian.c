// Room: /d/mojie/youdian
inherit ROOM;

void create()
{
  set ("short", "��ƫ��");
  set ("long", @LONG
����һƬħ��֮�����������һ�߾Ÿ�ʯ�����������ʮ����ħ
��֮�񣬸��������ֲ������˲���������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dadian",
]));
  set("objects", ([
   __DIR__"npc/heipao" : 1,
]));
  setup();
  replace_program(ROOM);
}
