//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�����");
        set ("long", @LONG
����һƬ����,һ�ж�����ô��Ʈ��...���...
ֻ��һЩС·,����ż�����õ���Щ�������˴�.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "east" : "/u/calvin/room/�����3",
                "west" : "/u/calvin/room/�����5",
               "south" : "/u/calvin/room/������Ժ",
              "north" : "/u/calvin/room/��ͼ��",
        ]));

        set("objects", 
        ([ //sizeof() == 1
             "/u/calvin/npc/������ʿ.c" : 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
