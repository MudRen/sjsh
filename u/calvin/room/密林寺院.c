//���� ��Ժ

inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short","������" );
        set ("long", @LONG
�����������ֵ���Ψһ��һ���������Ժ,��Ϊ������ʢԶ
�����ⳣ�������Զ��������������Ů,�����˻ʵ����ո�
����ɽ�˺���
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "north" : "/u/calvin/room/�����4",
              "east" : "/u/calvin/room/������",
              "south" : "/u/calvin/room/�ؾ���",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                 "/u/calvin/npc/����" : 2,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
