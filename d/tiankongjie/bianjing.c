// Room: /d/tiankongjie/bianjing.c

inherit ROOM;

void create()
{
        set("short", "�߾�");
        set("long", @LONG
���������ս�ı߾��ˡ������ƺ��Ѿ���һ���ˡ�һ��ֱ·���ϣ��������ޱ�
�ƺ��������ƺ��л�������һ���ʺ磬�ʺ����Χ���м�ֻ�ɺ��ڷ��裬�Ե������
���������ס�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"yueguangku.c",
]));

set("valid_startroom", 1);
        set("outdoors", "tiankongjie");
        setup();
        replace_program(ROOM);
}
