#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW" ������� "NOR);
set ("long", @LONG

������һ���������¿�����С���䡣���⿴ȥ�����Ǻɻ�ҡ������������
ʱ��ֵʢ�ģ�������ȴ�Ǹо�ʮ���������ԱߵĲ輸�Ϸ��žջ��裬����
���ż��ξ������ı��飬���˾�������������

LONG);
set("exits", 
([ //sizeof() == 1
"west" : "/u/xuexu/changlang",
]));
set("no_fight", 1);
set("no_kill", 1);
set("no_time", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/obj/cup" : 2,
]));
setup();
}
