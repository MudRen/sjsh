// Room: /d/shaolin/cjlou1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "�ؾ����¥");
	set("long", @LONG
ǧ������������ִ��ԭ����֮ţ�����Դ�Ħ�������£�����
�˲ı����������в��ٸ�ɮ�������棬�㼯�����ճ���������
��������ʮ�����ա����־����������ڴˡ���¥���濪����ȷ��
ͨ�硣�м����������Ŵ���ܡ���������а������Թ��Ķ�����
λ��ɮ��ִ���������ڱ�Ŀ��˼��
LONG );
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
        set("objects",([
                "d/shaolin/obj/fojing1"+random(2) : 1,
                "d/shaolin/obj/fojing2"+random(2) : 1,
		
		
	]));
//	set("no_clean_up", 0);
	setup();
}
int valid_leave(object me, string dir)
{
     me = this_player();
     if ((dir == "down") && ( present("shu", me)))
     {
         return notify_fail
                ("����Ѿ������ߣ���ǰ����˵���������鲻��衣\n");
     }
     return ::valid_leave(me, dir);
}
