//shulin ����

inherit ROOM;

void create ()
{
        set ("short", "�������");
        set ("long", @LONG

����������ǵ�������,��Ľ�ͨ����,·������
�����ر�Ķ�.������ȥ���ǻʹ���,������ʯͷ
���,��˵�ߵ�ͷ�����Ϻ�֮����;�������껨ʯ
·,����·ͨ���ĵط��ܶ� ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/����/����/������8",
                "south" : "/u/calvin/����/����/������1",
                "west" : "/u/calvin/����/����/ʯͷ���1",
                "east" : "/u/calvin/����/����/�껨ʯ·",
                "down" : "/u/calvin/����/����/����",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//          "/u/calvin/����/board" : 1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
          call_other( "/u/calvin/����/board", "???" );
        replace_program(ROOM);
}
