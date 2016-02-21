#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "��ľ��");
  set ("long", @LONG

���˸ߵĹ�ľ��(guanmu)��ȫ�ĵ�ס�˵�·���������ƿ�
�������޷�ǰ�����ˡ�
LONG);


  set("outdoors", 1);

  set("exits", ([ /* sizeof() == 2 */
    "up" : "/d/swordman/crass2",
]));

  setup();
}

void init()
{
  add_action("do_clean", "bo");
  add_action("do_clean", "clean");
  add_action("do_clean", "push");
  add_action("do_clean", "pushaside");
}
int do_clean(string arg)
{	int i;
	object ob=this_object();
	object me=this_player();
	object obj;
        if(!arg || arg != "guanmu" )
                return notify_fail("��Ҫ��ʲô��\n");
	
        if(query("clean"))
                return notify_fail("��Χ�Ѿ�û�й�ľ���ˡ�\n");

	if((int)me->query("kee") <200)
                return notify_fail("��̫���ˣ�ЪЪ�ɣ�\n");

	if(!(obj = me->query_temp("weapon")) ){
		message_vision("$N������ȥ���ǹ�ľ�ԣ�ȴ����������Ѫ��\n", me);
		return 1;
	} else {
		message_vision("$N��������$n��С�ĵ�ȥ�����ǶѶѹ�ľ�ԡ�\n", me, obj);
		me->receive_damage("kee", 150);
		i=(int)me->query_str();
		ob->set("coe",(int)ob->query("coe") + i );
		
		if( i < 30 ){
			tell_room(environment(me), "���ֻ������֦С�̡�\n"); 
		}
		else if (i < 50 ) { 
			tell_room(environment(me), "�������һƬ��ľ�ԡ�\n");
		}
		else if (i < 100 ) {
			tell_room(environment(me), "ֻ����ľ�Ա��ƵĲ�ס���ˡ�\n");
                }
		else tell_room(environment(me), "ֻ����ľ���糱ˮ���˺�\n");
	}
	
	if( (int)ob->query("coe") >= 1000 ) {
		tell_room(environment(me), "��ľ�Ա��Ƶ����ԣ�����һ����·��\n\n");
		me->set_temp("obstacle/guanmu/clean_1", 1);
		call_out("done", 0);
	}
	return 1;
}
int done()
{
	set("long", @LONG

�ƿ��ԴԹ�ľ��,һ����·���������˳�����
LONG);
	set("clean", 1);
	set("coe", 0);
	set("exits/down", __DIR__"crass4");
	return 1;
}
