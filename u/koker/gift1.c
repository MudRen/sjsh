
inherit MAZE;

void create()
{
	object ob;
	string temp;
	int i;

	set("short", "�����ǰ�ڵ�һ��");
	set("long", @LONG
�ں�����ǽ�ڣ�ż���м����İ��Ļ�����Ż�ƵĹ⣬
һ�������Ĺֽ����;׽�������е��������������㻹����
����ǽ��Ϊ�Լ�׳��(knock)��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "up" : "/map/newsorpigal/goblin",
  "down" : "/map/newsorpigal/maze/goblin2",
	]));

	for(i=0;i<1;i++)
	{
        ob=new("/u/koker/npc/allbeast.c",1,1,1);
	ob->move("/u/koker/gift1");
	}

	ob=new("/u/koker/obj/box.c");
	ob->move("/u/koker/gift1");
	
	set("where","/u/koker/npc/allbeast.c");
	set("beastnum",1);
	setup();
}
