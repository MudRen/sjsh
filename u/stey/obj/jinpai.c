// jinpai.c ����

#include <ansi.h>

inherit ITEM;
int do_eat(string);                                                                         
void init();
   
void create()
{
	set_name(HIY "����" NOR, ({ "jin pai", "pai"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ�Ž�������Ľ��ƣ�������Ľ���ѡ�\n");
                set("value", 100000);
		set("unit", "��");
	}
	 set("is_monitored",1);
	 setup();   
}

void init()
{
	if (!wizardp(this_player())) {                                                            
    set("no_get",1);                                       
    set("no_give",1);                                        
    set("no_drop",1);                                        
    set("no_sell",1);
    }
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object victim = this_player();

        if (! id(arg))
                return 0);

        me = this_player();
        message_vision(HIM "$N����һ�����ƣ���ʱ�����Ժ��������泩�� \n" 
        NOR, me);
        me->add("potential, 10000);
        destruct(this_object());
	return 1;
}
