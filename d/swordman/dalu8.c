// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹������������������ȵ���,
��糴彣��������ȵ�����,�����ĵ�����һ���һ�����������

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu7",
        "east"    : __DIR__"dalu9",
        "north"     :__DIR__"wuguan",
      ]));
  set("objects", ([
        __DIR__"npc/people"    : 2,
          __DIR__"npc/zuozhizhu"    : 1,
      ]));

  set("outdoors",__DIR__"");
  setup();
}

