// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹���������ȥ���ǽ��;�ʾ��
�ˡ�

LONG);

  set("exits", ([
          "south"    : __DIR__"xiaolu1",
        "west"    : __DIR__"dalu9",
        "east":__DIR__"jingshiting",
      ]));
  set("outdoors",__DIR__"");
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));

  setup();
}

