//兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵书局");
        set ("long", @LONG

刚一进门就闻到一股书香,真是难得的好地方啊
平时这里总是汇集着很多的书生,他们大都是
准备下届赴京城赶考的秀才.这里布局典雅大方.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
    "west" : "/d/calvin/lanling/jie6",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                  "/d/obj/其他/装备老板" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
