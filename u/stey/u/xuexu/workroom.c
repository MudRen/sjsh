#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIB" ��ˮ�� "NOR);
set ("long", @LONG

������̤���������������ķ��䣬�������ҵ�����ɫ���м����һ�����٣�
�Ա���ɢ����һЩ�鼮�������һ����ȥ��������д�š��������޵���������
��ͻȻ�����������������Ǹ�Ů�ӡ����ľ�֮�£���Ҫ�����˳�������һ��
����Ʈ����ı��ӣ���ͷ��ȥ��һ������ҫ�ۺ���ĳ�����ָ����ĺ���...

LONG);
set("exits", 
([ //sizeof() == 4
"rainy" : "/u/rainy/workroom",
"kz" : "/d/city/kezhan",
"repoo" : "/u/repoo/workroom",
"fayu" : "/u/fayu/workroom",
"wiz" : "/d/wiz/wizroom",
"east" : "/u/xuexu/changlang",
]));
set("no_fight", 1);
set("no_kill", 1);
set("no_time", 1);
set("sleep_room", 1);
set("no_clean_up", 0);
set("objects", ([
   "/u/xuexu/npc/feixue" : 1,
   "/u/xuexu/obj/xuehua" : 2,
]));
setup();
}
