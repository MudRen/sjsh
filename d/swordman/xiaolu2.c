// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "С·");
  set ("long", @LONG

С·�������˰�ɫ��С��ʯ�ӡ�Խ������,����Խ��ԽƫƧ��

LONG);

  set("exits", ([
        "northwest"   : __DIR__"xiaolu1",
        "southup"   : __DIR__"xiaolu3",
      ]));
  set("outdoors", __DIR__);

  setup();
}


