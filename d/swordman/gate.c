// Room: /d/4world/northgate.c
inherit ROOM;

void create ()
{
  set ("short", "���֮������");
  set ("long", @LONG

һ���ߴ�ĳ�ǽ������ǰ�ߣ����ϲ������سǵĹٱ��߹�������
�����������˺ܶ࣬��孹��˷紾�ӣ��񸻶�֪�㣬����Ҳ����
һ��ϲ������ľ�ɫ��
LONG);

  set("light_up", 1);
  set("no_magic", 1);
  set("outdoors", __DIR__"");
  set("objects", ([
                __DIR__"npc/jianshi": 4]) );

  set("exits", ([ /* sizeof() == 2 */
      "east"  : __DIR__"dalu1",
      "west":__DIR__"haian",
]));
  set("no_fight", 1);

  setup();
}
