// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ʯ�ֵ�");
  set ("long", @LONG

ӵ���Ķ�孽ֵ�����·����ɫСʯ�̳ɡ��������У��־�����������
Ŀ��Ͼ���������в����������شҴ��߹���������һ���ľ߹�ģ�Ŀ�
ջ,�˳�ӿ��ӿ��,���ּ��ˡ�

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu4",
        "east"    : __DIR__"dalu6",
        "south"   :__DIR__"kezhan",
      ]));
  set("outdoors",__DIR__"");
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));

  setup();
}

