// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

С·�������˰�ɫ��С��ʯ�ӡ�Խ������,����Խ��ԽƫƧ��

LONG);

  set("exits", ([
        "north"   : __DIR__"dalu10",
        "southeast"   : __DIR__"xiaolu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



