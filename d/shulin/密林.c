//Cracked by Roath
//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "����");
        set ("long", @LONG

������ɭ�ֵ��,������Щ�˳�û,һ�ۿ������ߵ�������ɭ�ɾ�
���ڸ����ѵ�����Щ�˳�û,������Щ��������,˭Ҳ��֪�����Ƕ�
����Щʲô����.������Ǻܺ�,�����������һ���ĺ�... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/d/shulin/lin8",
                "south" : "/d/shulin/lin1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//         __DIR__"npc/japan":2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
