

#include <ansi.h>
int do_lingwu(string arg);

inherit ITEM;

 void create()
{
        set_name(HIW "��ҳ��ֽ" NOR, ({"gao zhi", "zhi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "��ҳ�����ù��ĸ�ֽ��������������(lingwu)��ʲô��\n");
                set("value", 20000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," �ٺ٣����ΰ�! \n");
        set("no_drop","��ô����Ķ�������������! \n");
        set("no_give","��̫�����˰ɣ�\n");
       }
        add_action("do_lingwu", "lingwu");
       
}

int do_lingwu(string arg)

{
        int exper,improve=0;
        
	object me = this_player();
 

        if (!id(arg))
	return notify_fail("��Ҫ����ʲô��\n"); 


        exper = me->query("combat_exp");
        improve=exper/30+random(exper/30)+100;
     
        me->set("combat_exp",exper+improve);
        message_vision(HIY"$N����һ�����ֽ�����ý��������������\n"NOR,me);
        destruct(this_object());
        return 1;	
	
       
}


