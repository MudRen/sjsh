//Cracked by Roath
//shulin 密林

inherit ROOM;

void create ()
{
        set ("short", "密林");
        set ("long", @LONG

这里是森林的深处,很少有些人出没,一眼看不到边的这里阴森可惧
这在附近难得有少些人出没,好象都是些黑市商人,谁也不知道他们都
买卖些什么东西.天空总是很黑,和这里的人心一样的黑... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/shulin/lin8",
                "south" : "/d/changan/eside5",
                "enter" : "/u/calvin/room/密林暗室.c",
               "west" : "/u/calvin/room/密林深处1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//       "/d/shulin/npc/密林使者":1,
              "/d/obj/flower/红玫瑰":2
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
