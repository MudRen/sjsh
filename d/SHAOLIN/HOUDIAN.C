// Room: /d/shaolin/houdian.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����ģ�������߶���ˮĥʯ�ڣ��ο���ʮ���޺���Ф��
�����ˣ�������һ��ˮ����ˮ�澻���������������ᣬ��Ի����
��������������ˮ������������и��Ŷ���ͨ�����೤�������ȡ�
LONG );
	set("exits", ([
                 "west" : __DIR__"zoulang1",
		"east" : __DIR__"zoulang3",
		"southdown" : __DIR__"guangchang4",
		"north" : __DIR__"wuchang",
	]));
	set("valid_startroom",1);
	set("resource/water",1);
	set("objects",([
                                __DIR__"npc/sengbing" : 2,
                                __DIR__"npc/huiru" : 1,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
