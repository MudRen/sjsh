

#include <ansi.h>
void test_me(object me);
inherit ROOM;

void create()
{
	set("short",  HIR "����" NOR );
	set("long",HIR @LONG
���b��Ψһ��һ���������ܵ�����������һ����������ͷʹ�Ľ�ɫ��
����һ��������˵�ͷ�Ͳ�ʹ�ˣ����ͷӦ�ÿ�ʼʹ�˰ɣ�����
LONG
      NOR);
        

	set("no_fight", 1);
	set("no_magic", 1);
	set("no_spells", 1);
	setup();
}
void init()
{
        if(!wizardp(this_player()))
	{
	"/cmds/std/look"->look_room(this_player(),this_object());
	this_player()->set("startroom", __FILE__);
        add_action("do_nothing", "");
	add_action("do_quit","quit");
	}
}	

int do_nothing()
{
write("������������డ����������\n");
return 1;
}

int do_quit()
{
"/cmds/usr/quit"->main(this_player(),"");
return 1;
}
