// /d/changan/playerhomes/stdbed.c
// this  is a standard bed for married couples.
// wiz should modify /d/changan/playerhomes/h_playername  to 
// connect here.
// IMPORTANT: should copy this to bed_playername, otherwise...  

inherit ROOM;

void create()
{
        set("short", "����ʯ");
        set("long", @LONG

LONG
        );

        set("exits", ([
                "down": "/u/calvin/room/���ְ���1",
            ]));
        set("sleep_room",1);
        set("if_bed",1);                             

        setup();
}
