inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�������ţ���֪��������һ������ǰ���������źܸߣ����Ծ����ĵģ�
���Ĵ�������һ�£�ȷ����������Ǵ������ȥ�ģ����ݶ��룬̧�ž��������ߣ�
�յ��ſڣ���Ȼ����������з�����

        վ �� �� ��           �� �� �� ȥ

������һ��䣬�ź���������ȫ����װ���ڱ���......
LONG);

    set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"workroom.c",
  "west" : __DIR__"workroom.c",
  "south" : __DIR__"workroom.c",
  "north" : __DIR__"huayuan.c",
]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/guard" : 2,
        ]));

        setup();
}
