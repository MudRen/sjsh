// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "�ֵ�");
  set ("long", @LONG

һ���������ʯ·�棬·����Ȼ���Ǻܿ���������������Ҳ��һƬ����
�ľ��󡣽ֵ��Ƕ�������������һ����Ȫ��
LONG);

  set("exits", ([
        "west"   : __DIR__"jiedao11",
        "east"   : __DIR__"qingquan",
        "northeast"   : __DIR__"jiedao10",        
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

