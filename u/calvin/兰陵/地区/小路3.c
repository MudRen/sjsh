//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "С·");
        set ("long", @LONG

����һ������С�ݵ�С��,·�˲���ܶ� ... ...

LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/u/calvin/����/����/С·2",
                "south" : "/u/calvin/����/����/С·4",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
