// Room: /d/mojie/shanfang.c
inherit ROOM;

void create()
{
  set ("short", "�ŷ�");
  set ("long", @LONG
����ħ����ŷ���һ��С�������շ����������������ŷ����㡣
�����Ҫ(serve) Щ�Եĺȵġ�
LONG);
   set("sleep_room",1);
   set("if_bed",1);
   set("no_get",1);
   set("no_fight",1);
   set("no_cast",1);
   set("no_flee",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guodao4",
]));
        set("objects", 
        ([ //sizeof() == 1
  __DIR__"npc/baomo" :1,
  __DIR__"npc/yao" :1,
        ]));
  setup();
  replace_program(ROOM);
}
