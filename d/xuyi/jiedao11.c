// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ���������������Ҳ��һƬ����
�ľ��󡣽ֵ��Ƕ���������������ͨ��ʮ��·�ڡ�
LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao4",
        "east"   : __DIR__"jiedao12",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

