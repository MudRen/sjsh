// Room: /d/liwu/partyroom.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"��ĩparty��"NOR);
        set("long", @LONG
   ��������ĩparty�ݣ�ÿ����ĩ���ﶼ�����¡�ص�party����ʱ��ÿ�����μ�
party���˶������õ�һ�����ص����ף��Һ��ˣ�
LONG
        );
        set("no_fight", 1);
        
         set("objects", ([
        "/d/liwu/obj/cabinet" : 1,
        ]));
        set("exits", ([
                "northeast" : __DIR__"happyjie",
        ]));

        setup();
        replace_program(ROOM);
}
