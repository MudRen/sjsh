// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹��������ǳ������ı�����,
�����Ÿ��ֳ��ñ�����

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu6",
        "east"    : __DIR__"dalu8",
        "south"    : __DIR__"bingqipu",

      ]));
  set("outdoors",__DIR__"");
  setup();
}

