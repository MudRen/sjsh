//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5

inherit ROOM;

void create()
{
        set("short", "�㳡");
        set("long", @LONG
��������ɽ���ɵĹ㳡��ͨ���������ɽ���ɵ����ڴ�ϰ������������
����ӭ�⡣
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"dadian",
  "east" : __DIR__"jinglou",
  "south" : __DIR__"paifang",
]));

        set("objects",([
        __DIR__"npc/jiantong" : 2,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
