// �����硤���μ�֮�����ͣ�
 
// create by night 2000.7.24

inherit ROOM;

void create ()
{
  set ("short", "̫�ͽ�");
  set ("long", @LONG

̫�ͽִ�ϙ�����Ĺ㳡ֱ�ﶫ���⣬��������ǳ�����Ҫ�ֵ���������
����ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ����ֵ���������һ�����ӣ�
��дһ�����ġ������֡�
LONG);

  set("exits", ([
        "east"   : __DIR__"jiedao9",
        "west"   : __DIR__"center",
        "north"   : __DIR__"dangpu",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

