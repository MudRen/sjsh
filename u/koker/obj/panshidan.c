//panshidan.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIC "��ʦ��" NOR,({"panshidan"}));
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	HIC "һ���ܹ���������ʦ������������鵤��\n"NOR);
		set("unit","��");
		set("value", 100000000);
	}
}

void init()
{
	if(environment()==this_player())
		add_action("eat_guo","eat");
}

int eat_guo(string arg)
{
	if ( arg == "panshidan")
	{
   message_vision(HIC"$NС������ķ���һ����ʦ����һ������ֱ�����ţ�����ʦ����������·𶼳��˹�ȥ��\n"NOR,this_player());
		this_player()->add("betrayer",-1);
		if (this_player()->query("betrayer")< 0) 
			this_player()->delete("betrayer");
//     this_player()->delete("family");
//     this_player()->set("title","��ͨ����");
//     this_player()->delete("class");
		destruct(this_object());
		return 1;
	}
	return	0; 
}
