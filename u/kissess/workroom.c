#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW"���е�"BLINK HIG"��ŵ"NOR);
set ("long",@LONG

��Ҫô������Ҫô����Ҫô������Ҫô��........
�����Ҹ���ĳ�ŵ��û������...
�ɲ����Ը��Ҹ������ȣ���������������
�Ҹ���ĳ�ŵ����û�����ɵġ�������
������е��Ƕ��õ��,ҡҷ��Ī�������ġ�����
׷������δ��У�Ȫ��mud����Ѱ����

LONG
BLINK HIC @LONG
��ӭ��������׷��ļ�!

LONG NOR);
set("exits",([
"kz":"/d/city/kezhan",
"wiz":"/d/wiz/wizroom",
]));
        set("objects", 
        ([
           __DIR__"npc/announcer" : 1,
        ]));
set("outdoors", 1);
        set("no_time",1);
        set("no_upgrade_age",1);
        replace_program(ROOM);
set("no_clean_up", 1);
set("valid_startroom", 1);
set("if_bed",1);
setup();
call_other( "obj/board/kissess_bbs","???");
}
