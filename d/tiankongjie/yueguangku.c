// Room: /d/tiankongjie/yueguangku.c

inherit ROOM;

void create()
{
        set("short", "�¹��");
        set("long", @LONG
�����ǽ�����ս��Ψһͨ������ɫ�Ĺ�â�Ӷ�������ĵ���������Χ
�����ˣ�����������ݡ�ʹ��о���һ������������Դ�ĸо����㽫Ҫ��
�����������б�����Ļ�������ס��
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"bianjing.c",
  "out" : __DIR__"tianshoudao.c",
]));

        setup();
        replace_program(ROOM);
}
