// Room: /d/liwu/dogjie.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ����������ʯ�ֵ��������뻶�ֽ����������Խֵ��ϳ�����ϲ�õ����ա�
���ϱ��������֣��Ǿ��ǻ��ֽ��ˣ�������ͨ�������Ļ������С����ϱ���һ��
��̫��ĳ�������ݣ�����԰���ĳ�����������
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"southeast" : __DIR__"happyjie",
		"southwest" : __DIR__"dog_room",
//                "northwest" : "/d/city/bank",
	]));

	set("objects", ([
                __DIR__"npc/shaofu" : 1,
                __DIR__"npc/jentleman" : 1,
                __DIR__"npc/youke" : 2,
	]));

	setup();
	replace_program(ROOM);
}

