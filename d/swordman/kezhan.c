//shop.c
#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��孿�ջ");
	set("long", @LONG

��孳������Ŀ�ջ,�����������˺ܶ࣬��֮��Ǯ��������������
�ǳ�����¡�������ǿͷ���������������Ϣ��ҹ��

LONG
        );
	set("no_clean_up", 1);
	set("resource/water", 1);
	set("exits",([
		"north"  : __DIR__"dalu5",
		"south" : __DIR__"kefang",
        ]));
	set("objects", ([
                __DIR__"npc/waiter" : 1,
        ]));
        set("valid_startroom", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        if ( !me->query_temp("rent_paid") && dir == "south" )
                return notify_fail("û����Ǯ����ס�ꣿ\n");
        return ::valid_leave(me, dir); 
}
