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
                "north" : __DIR__"yuxu",
                "south" : __DIR__"hundun3",
                "east" : __DIR__"hundun2",
                "west" : __DIR__"hundun1",

        ]));
        set("objects", ([

   ]));
       setup();
	replace_program(ROOM);
}

