// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "����С��");
  set ("long", @LONG

�������ź��ߵ�һ��С����Խ����ȥ����·Խ��᫣�����ɽ��
ͻ�𣬹�ľ�������㲻�������ؼӿ첽����

LONG);

  set("exits", ([
        "south"    : __DIR__"haian",
        "northeast"    : __DIR__"searoad2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

