// changan wusheng
// indanlu.c

inherit ROOM;

void create()
{
  set ("short", "�Žŵ�¯��");
  set ("long", @LONG

һ���ܴ�ĵ�¯��������ͨ�������о�Ȼ��һ���������
LONG);
set("exits", ([ /* sizeof() == 4 */
"out": __DIR__"room1",
]));
set("objects", ([
               "/d/lingtai/npc/hufa": 1]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}

