//changan city

inherit ROOM;

void create ()
{
        set ("short", "������");
        set ("long", @LONG

��һ���žͿ����������ϰ��Ÿ��ֱ��������ϰٽ��صĴ󵶵������
�ӵķɻ�ʯ����Ӧ�о��С�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : __DIR__"dalu7",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
        ]));


//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

