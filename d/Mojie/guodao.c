// Room: /d/mojie/guodao.c
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG
����һ���ֳ���խ�Ĺ������������Բ����˻�ѣ������������յ�
ͨ����������ǽ���Ͽ���������˵�ʯ����ǰ�߾����޷���
��������������������ŷ���
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guodao1",
  "east" : __DIR__"guodao3",
  "south" : __DIR__"chang",
  "north" : __DIR__"dadian",
]));
        set("objects", 
        ([ //sizeof() == 1
        ]));

  setup();
  replace_program(ROOM);
}
