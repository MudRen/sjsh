//kunlun
inherit ROOM;

void create ()
{
        set ("short", "С·");
        set ("long", @LONG

        С·һֱ������ȥ������������·�ľ�ͷ��
LONG);

        set("exits", 
  ([ //sizeof() == 4
                "west" : __DIR__"xiaolu",
                "east" : __DIR__"xiaolu2",
        ]));
        set("objects", ([
   ]));
        set("outdoors", "changan");
       setup();
	replace_program(ROOM);
}

