//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
��ɽɽ·��
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "northup" : __DIR__"paifang",
  "southdown" : __DIR__"shanjiao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
