//kunlun
inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

����һƬ����ʹ���Ҫ�ֲ��巽�򣬻��ǳ��ܿ���
·��ʱ��Ͽ��߰ɡ�
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "north" : __DIR__"hundun2",
                "south" : __DIR__"hundun1",
                "east" : __DIR__"hundun",
                "west" : __DIR__"hundun3",

        ]));
        set("objects", ([

   ]));
       setup();
	replace_program(ROOM);
}

