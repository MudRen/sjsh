//changan city

inherit ROOM;

void create ()
{
        set ("short", "��ȵ�������");
        set ("long", @LONG

���������������ȵ��������������һ���������Ѭ��Ŭ���£���
���Ĺ�ģ������������š�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
              "south" : __DIR__"dalu8",
                "north":__DIR__"dating",
        ]));

        set("objects", 
        ([ //sizeof() == 4
          "/d/swordman/npc/dizi" : 2,
          "/d/swordman/npc/miyan" : 1,
            "/d/swordman/npc/zhangmen" : 1,
        ]));


        set("no_clean_up", 0);
        setup();
}

