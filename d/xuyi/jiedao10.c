// �����硤���μǡ��汾�����ͣ�
/* <SecCrypt CPL V3R05> */

//created by night 7/24/2000
 
inherit ROOM;

void create ()
{
  set ("short", "̫�ͽ�");
  set ("long", @LONG

̫�ͽִ�ϙ�����Ĺ㳡ֱ�ﶫ���⣬��������ǳ�����Ҫ�ֵ���������
����ڴ�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ���������ǳ��ţ�������
ʿ�ڳ�����Ѳ�ӣ��鿴�����������ǡ�
LONG);

  set("exits", ([
        "east"   : __DIR__"dongmen",
        "west"   : __DIR__"jiedao9",
        "southwest"   : __DIR__"jiedao12",
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}


