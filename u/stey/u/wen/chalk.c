// chalk.c
// by kittt

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"�۱�" NOR, ({ "chalk" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "֧");
	      set("long","С�����Ŀռ佻������\n");
		set("value", 0);
	}
	setup();
}

void init()
{
        add_action("do_circle","circle");
}

int do_circle(string arg)
{
	object me, obj, ob;
	
	me = this_player();
	ob = me->query_temp("circle_obj");

	if( !arg )
		return notify_fail("���������ﻭȦ��\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("����û�����������\n");

	if(obj == me)  
		return notify_fail("you can't circle yourself.\n");

	if(ob == obj) return notify_fail("you just circled it .\n");
	if(ob && present(ob, environment(obj))) 
		return notify_fail("They are already in the same room lah.\n");

		message_vision(HIW "$N��$n����Χ����һ��ԲȦ��\n" NOR,me,obj);
		if(ob) { 
	tell_room(environment(obj), MAG"���"+obj->name()+"�漣�����ʧ����ԲȦ�����"+ob->name()+"��������ԲȦ�С�\n"NOR, ({obj}));
	tell_room(environment(ob), MAG"ͻȻ"+ob->name()+"��ʧ����ԲȦ�����"+ob->name()+"��������ԲȦ�С�\n"NOR, ({ob}));

			obj->move(environment(ob));
			ob->move(environment(me));
			write (ob->name()+"��"+obj->name()+"�ռ佻���ɹ���\n");
			me->delete_temp("circle_obj");
			 return 1; }			
		me->set_temp("circle_obj",obj);
		return 1;
}

