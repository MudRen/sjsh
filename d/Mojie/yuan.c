// Room: /d/mojie/yuan.c
inherit ROOM;

void create()
{
  set ("short", "��ˮ֮Ԩ");
  set ("long", @LONG
���Ǳ���������Ϊ֮�����ĺ�ˮ֮Ԩ����ˮ�Գ�������Ԫ˧
�ܶɹ�������֮�������ܶɡ������������Ļ����ǲ�����
�ٳ����ˡ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yuan",
  "west" : __DIR__"yuan",
  "east" : __DIR__"yuan",
  "north" : __DIR__"yuan",
]));
  setup();
  replace_program(ROOM);
}
