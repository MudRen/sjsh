//by koker@sjsh 2002

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIG"����֮��"NOR);
        set ("long", @LONG

һ�������Ĺ��������߶���һ���ĺ�ɫ���ţ���֪�����Ǹ������
��ʱ�Ĵ����ҽ�������ɭ�ĺٺ�����
LONG);

        set("exits", 
        ([ //sizeof() == 4
              "east" : "/u/koker/giftroom1",
              "west" : "/u/koker/giftroom3",
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
