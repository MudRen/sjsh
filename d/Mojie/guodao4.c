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
  "west" : __DIR__"guodao3",
  "east" : __DIR__"shanfang",
]));
        set("objects", 
        ([ //sizeof() == 1
  __DIR__"npc/shumo" :1,
        ]));
  setup();

  setup();
  replace_program(ROOM);
}
