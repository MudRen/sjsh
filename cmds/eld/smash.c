// smash.c 2-22-95
 
#include "globals.h"
#include <ansi.h>
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string name1, name2;

	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�Ҳ���������\n");
   if ((string)ob->query("id")=="syb")  {
       ob = me;
    }

        if( wiz_level(me) < wiz_level(ob) )  {
        ob = me;
    }    
	name1 = (string)me->query("name");
	name2 = (string)ob->query("name");
	tell_room(environment(me),
	name1+"�߾�˫�ִ�ȣ�ȥ���ɣ�ֻ������һ�����粻ƫ���еػ���"+name2+
	"����֮��Ϊһ�ѻҽ���\n", ({me, ob}));
	if(living(ob))
	    tell_object(ob, name1+
		"�߾�˫�ִ�ȣ�ȥ���ɣ�ֻ������һ�����粻ƫ���еػ����㡣\n");
	
	write("��߾�˫�ִ�ȣ�ȥ���ɣ������Ͻ���һ�����罫"+name2+
		"����һ�ѻҽ���\n");
	if (!wizardp(ob)){
    	message("channel:chat",HIG"�����꾫�顿ĳ�ˣ�"+"��˵"+me->query("name")+"�����罫 "HIW+ob->query("name")+HIG" ���������졣\n"NOR,users());
	}
	if(living(ob)) { // mon 10/17/98
	  ob->set("env/immortal", 0);
	  ob->die();
	} else
	  destruct(ob);
	  return 1;

}
 
int help(object me)
{
   write(@HELP
ָ���ʽ: smash <����>
 
hehehehehe...........

HELP
   );
   return 1;
}
