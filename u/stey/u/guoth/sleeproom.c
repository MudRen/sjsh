// Room: /u/guoth/sleeproom.c
inherit ROOM;
void create ()

{
           set ("short", "Hell");
           set ("long", @LONG

������Ϸ���ӵ�˯����<������ȱ>
LONG);

            set("exits", ([
                    "down" :  "/u/guoth/workroom",
                     ]));

        set("no_fight", 1);
       set("sleep_room",1);
       set("valid_startroom", 1);

        set("no_clean_up", 0);
       setup();

}
