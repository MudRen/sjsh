//kunlun
inherit ROOM;

void create ()
{
        set ("short", "���䳡");
        set ("long", @LONG

�������鶴ǰ��һ��ƽ�أ������ɵ�������֮�á�������ͯ
������ϰ������
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"lingyun",
                "north" : __DIR__"dadian",
        ]));
        set("objects", ([
                __DIR__"npc/xiao" : 2,
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

