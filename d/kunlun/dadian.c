//kunlun
inherit ROOM;

void create ()
{
        set ("short", "���");
        set ("long", @LONG

�������鶴ǰ��һ��ƽ�أ������ɵ�������֮�á�������ͯ
������ϰ������
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "south" : __DIR__"lianwu",
                "northwest" : __DIR__"mishi",
        ]));
        set("objects", ([
                 __DIR__"npc/zhangmen" : 1,
                __DIR__"npc/luya" : 1,

   ]));
       setup();
	replace_program(ROOM);
        "obj/board/kunlun_b"->foo();

}

