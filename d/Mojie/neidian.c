// Room: /d/mojie/neidian
inherit ROOM;

void create()
{
  set ("short", "�ڵ�");
  set ("long", @LONG
������������Ϣ�ĵط�������һƬ�������ơ��������������޴�ʯ
����ʯ�����Ͽ����˺�������̨����һ��������̨��������������
��ڤ˼������
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"dadian",
]));
  set("objects",([
   __DIR__"npc/wutian" : 1,
]));
  setup();
  replace_program(ROOM);
}
