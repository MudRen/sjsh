//by koker@sjsh 2002

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIG"���ҵ�����"NOR);
        set ("long", @LONG

�����һ�ж��Ǻڵģ��ںڰ��У�һ������͸��ǽ�ϵ�һ��С
��Ͷ�����ϣ�˳���������ߣ��㿴����һ��˶�������(box)��
LONG);

        set("exits", 
        ([ //sizeof() == 4
              "east" : "/u/koker/giftroom3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
         "/u/koker/box.c" : 1,
        ]));

        set("no_clean_up", 0);
        set("no_kill", 1);
        set("no_cast", 1);
        set("no_fight", 1);
        set("no_perform", 1);
        set("no_move", 1);
        setup();
        replace_program(ROOM);
}
