// xiuxishi.c by yushu 2000.11

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short",HIR "��" HIY "����" HIR "��" NOR);
	set("long", @LONG

��������ȵ����ڵ���Ϣ�ң������е��ɣ����Ǵ�ɨ�ķǳ��ɾ���
һ�Ŵ��̿�ǽ���ţ������ȥ���Ǵ��������ϵ����˽�����Ϣ���Ѻ�
��ȥ�������ĵ��Ҹ�����˯��������
LONG
	);
        set("exits", ([
	    	     "east" : __DIR__"dating",
		]));

           set("sleep_room",1);  
       setup();
	replace_program(ROOM);
}

