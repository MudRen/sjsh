#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", "��ª�İ칫��");
    set("long", 
"��������������һЩ��ֽ�š�һ��д��̨�Ͼ�һ̨�ƾɵĵ��ԡ�
���ܶѷ���һЩ�飬���Ҳ���������������ȴ�ƺ��ܷ���\n"
HIY "           �¶�����\n"
   "           ��������\n\n"
HIG "     ��������:jie_xixi@cnnb.net\n\n" NOR
);
set("sleep_room", 1);
        set("no_death", 1);
        set("valid_startroom", 1);
        set("exits", ([
            "down" :"/d/city/kezhan.c",
            "up" :"/d/wiz/wizroom.c",
            "city" :"/d/city/center.c",
           "moon" :"/d/moon/lotuspond.c",
        ]));
       setup();
        replace_program(ROOM);
}
