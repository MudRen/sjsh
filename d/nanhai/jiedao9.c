// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "̫�ͽ�");
  set ("long", @LONG

̫�ͽִ�ϙ�����Ĺ㳡ֱ�ﶫ���⣬��������ǳ�����Ҫ�ֵ���������
����ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ���������һ���ߴ����¥��
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao10",
        "west"   : __DIR__"jiedao8",
        "south"  : __DIR__"feiyue",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

