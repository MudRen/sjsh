// sticker.c

#include <ansi.h>

inherit ITEM;

void init()
{
        add_action("do_stick","stick");
        add_action("do_remove","remove");
        add_action("do_remove","drop");
        add_action("do_remove","give");

	if(environment()->query_temp("banned_talk")) {
      add_action("do_commu","say");
      add_action("do_commu","whisper");
      add_action("do_commu","chat");
      add_action("do_commu","shout");
      add_action("do_commu","wiz");
      add_action("do_commu","party");
      add_action("do_commu","tell");
      add_action("do_commu","reply");
      add_action("do_commu","rumor");
      add_action("do_commu","es");
	}
}

void create()
{
	set_name(HIM"OK��"NOR, ({ "sticker" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("no_get",1);
		set("long", "����һ��С������OK����ר�ŶԸ���˵�����ˡ�\n");
	}
	setup();
}

int do_stick(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("������˭��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û������ˡ�\n");

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

	if(obj == me)
		return notify_fail("just shutup.\n");

	if(me->query_temp("banned_talk"))
		return notify_fail("you shutup!!!\n");

	message_vision(HIM "\n$N�ó�һ��OK����������ס$n���°ͣ��ȵ�������ȥ��\n\n" NOR, 
			me, obj);
	obj->set_temp("banned_talk",1);
	this_object()->move(obj);
	return 1;
}

int do_commu(string arg)
{
	object me=this_player();

	message_vision(BLU"$N�Ŵ�����ͣ�ȴʲ�ỰҲ˵��������\n"NOR,me);
	return 1;
}

int do_remove(string arg)
{
	object me=this_player();

	if(!me->query_temp("banned_talk")) return 0;

	if(!arg||arg!="С������OK��") {
		message_vision("$N������˺��OK��������û�ɹ���\n",me);
		return 1; }
	message_vision(HIR"$N��OK��������˺����������Ѫ����һ�ء�\n"NOR,me);
	return 1;
}