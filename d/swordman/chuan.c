// Room: /changan/mufa.c

inherit ROOM;

void create ()
{
  set ("short", "ľ��");
  set ("long", @LONG

ľ���ں��к��У������ǰ�ãã��һƬ����
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"haian.c",
]));
set("zuo_trigger", 0);
  set("outdoors", 1);

  setup();
}
