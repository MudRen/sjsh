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
  "west" : __DIR__"lgfang.c",
  "east" : __DIR__"guodao1",
]));
        set("objects", 
        ([ //sizeof() == 1
    __DIR__"npc/shimo" : 1,
        ]));

  setup();
  replace_program(ROOM);
}
