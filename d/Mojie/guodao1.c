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
  "east" : __DIR__"guodao.c",
  "west" : __DIR__"guodao2",
]));
        set("objects", 
 ([        __DIR__"npc/shemo" : 1,
        ]));

  setup();
  replace_program(ROOM);
}
