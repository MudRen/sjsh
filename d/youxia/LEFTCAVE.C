inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "���С��");
        set("long", @LONG
�������̧ͷ��ȥ���ڰ�����ϡ����ɽ��������͹��ƽ������
��������ٽ�֯�ɵĳ�Ѩ��Ҳ��֪����ι̶�������ģ��պ���һ
ֻС���Ѩ�зɳ����ض�������һ�ܣ������������˻�ȥ��������
�Ǻ�����
LONG
        );
	set("frozen",10);
        set("item_desc", ([
                "����": "
һ���ƺ���ǧ�꺮���Ķ�����ס������ȥ·��\n",
        ]) );

set("exits", ([ /* sizeof() == 4 */
	"out" : __DIR__"waterfall",
	]));

        set("objects", ([
                __DIR__"obj/icy_boot" :1,
                __DIR__"obj/icy_cloth" :1,
                __DIR__"obj/icy_girth" :1,
                __DIR__"obj/icy_ribbon" :1,
                        ]) );
        set("coor/x",230);
	set("coor/y",-280);
	set("coor/z",40);
	setup();
}
