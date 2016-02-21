// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("С��", ({"xiao yao","xiao","yao"}));
        set("gender", "����" );
        set("class", "mo" );
        create_family("ħ��", 4, "����");
        set("age", 30);
        set("long", "ħ���һ���Ե����ֵ�С���������ջ�\n");
        set("combat_exp", 300000);
        set("daoxing", 300000);
        set("max_mana", 1000);
        set("max_force", 1000);
        set_skill("dodge",100);
        set_skill("moshenbu",100);
        set_skill("shifo-zhi",100);
        set_skill("unarmed",100);
        map_skill("dodge","moshenbu");              
        map_skill("unarmed","shifo-zhi");              

        set("attitude", "peaceful");
        setup();
}

void init()
{
::init();
        add_action("do_serve", "serve");
}

int do_serve(string arg)
{
        object m,mm;
        message_vision("$N��С���ʵ����ֵܣ���������\n", this_player());

        if((int)this_player()->query("food") >=
(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("С��Ц����û�ǣ��ȿ���ʱ�����ɣ�\n");

        if((present("bao zi", this_player())))
        return notify_fail("С��Ц������Ҫ��������ģ������Ź���ģ�����\n");
	
	if ( present("bao zi", environment()) )
                return notify_fail("С��Ц�����ǲ�����һ�����������˵��\n");

        m=new("/d/obj/food/baozi");
        mm=new("/d/obj/food/baozi");


        m->move(this_player());
        mm->move(this_player());

        message_vision("С����$NЦ�������˰ɣ�����ԡ�\n", this_player());
return 1;
}


