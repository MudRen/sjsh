//���� yaopu

inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short","����ҩ��" );
        set ("long", @LONG

��������һ�Ҳ����ҩ�̣��������ҩƷ��Ӧ�о���
�����������������������,���Գ�������һЩ����
����������·��.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "south" : "/u/calvin/room/�����5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
  "/u/boy/npc/shenyi" : 1,
        ]));

//        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
