// Room: /d/nanhai/zhulin
inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

���Ӻ�ɽ�������֡�Ҳ�ǹ������������������ڡ�����ϸ�裬
���΢���������ڴˣ�����֮���Ŷ�ʱ������ɢ����������һ
С������
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"zhulin",
  "east" : __DIR__"zhulin"+sprintf("%d",random(8)),
  "west" : __DIR__"zhulin"+sprintf("%d",random(8)),
  "south" : __DIR__"zhulin"+sprintf("%d",random(8)),
]));

   set("objects", ([ /* sizeof() == 1 */
  "/d/youxia/npc/tianji" : 1,
]));

  setup();
  replace_program(ROOM);
}
