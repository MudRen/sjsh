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
                "west" : "/u/calvin/����/����/С·1",
                "south" : "/u/calvin/����/����/С·3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
