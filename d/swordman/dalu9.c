// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹���

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu8",
        "east"    : __DIR__"dalu10",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

