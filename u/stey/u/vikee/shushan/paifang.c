//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "ӭ���Ʒ�");
        set("long", 
"��������ɽ���ɵ�ӭ���Ʒ����ߴ���Ʒ��Ϸ����ţ�  \n"+
HIG"    ��      ɽ      ��      ��  \n"NOR
);
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"square",
  "southdown" : __DIR__"path1",
]));

        set("objects",([
        __DIR__"npc/zhike" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
