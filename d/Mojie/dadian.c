// Room: /d/mojie/dadian
inherit ROOM;

void create()
{
  set ("short", "�޷����");
  set ("long", @LONG
�������ħ����޷��������컨�˽�ʮ����Ѫ��������������
���ɽ�������ɵġ��������м乩����������񡣵�ǰ���м���
���ţ���ר�Ÿ�ħ����Ӳΰ��õġ�
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"guodao",
  "east" : __DIR__"youdian",
  "west" : __DIR__"zuodian",
  "northup" : __DIR__"neidian",
]));
  set("objects",([
   __DIR__"npc/zhangmen" : 1,
]));
  setup();
  replace_program(ROOM);
}
