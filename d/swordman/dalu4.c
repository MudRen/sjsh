// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��·");
  set ("long", @LONG

����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ֱ��
��孳���,������Լ���Կ������֮����

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu3",
        "east"    : __DIR__"dalu5",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

