#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", "ɽ��Сͤ");
    set("long", 
"������һҶ֪�﹤���ĵط�:\n\n"
HIY "           ���ɪɪ\n"
    "           ��ҶƮƮ\n\n"
HIG "     ��������:vikee@263.net\n\n" NOR
);
set("sleep_room", 1);
        set("no_death", 1);
        set("valid_startroom", 1);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
            "up" :"/d/wiz/wizroom.c",
            "city" :"/d/city/center.c",
            "lg" :"/d/sea/gate.c",
        ]));
        replace_program(ROOM);
}
