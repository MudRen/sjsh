// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹���������һ�һ���,�ڽ���
�������ŵ�һ���˱ǵ����㡣

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu5",
        "east"    : __DIR__"dalu7",
        "north"    : __DIR__"huadian",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

