// Room: /d/liwu/happyjie.c

inherit ROOM;

void create()
{
	set("short", "���ֽ�");
	set("long", @LONG
������һ��ӵ���Ľֵ��ϣ������ֱ�ǻ��ֵĺ���������ڽ��ϳ��衢��
�裬���Ϸ���һ�����ֵĹ㳡����������һ��Ư���ĺ�׷��ӣ��������ڻ����
�ա����ϱ���һ���������������Կ����������ڿ���ᣬ�ò����֡�
LONG	);
        set("outdoors", "city");


	set("exits", ([
        "northeast" : __DIR__"lipinroom",
		"southeast" : "/d/city/guangchang",
                "southwest" : __DIR__"partyroom",
	]));

	set("objects", ([
		__DIR__"npc/happyboy" : 1,
                __DIR__"npc/happygirl" : 1,
                __DIR__"npc/shaofu" : 1,
                __DIR__"npc/jentleman" : 1,
	]));

	setup();
	replace_program(ROOM);
}

