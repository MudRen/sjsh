// dan.c ������

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"�㺮�鵤"NOR, ({ "dan" }) );
        set("long",
HIM"�¹������ϳ˵��鵤��ҩ��\n"NOR);
        set("unit", "��");
        set("weight", 5);
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob;
        if( !id(arg) ) return notify_fail("��Ҫ��ʲ�᣿\n");

          if( living( this_player())==0) return 0;

          if( living( this_player())==0) return 0;

        ob=this_player(); 
        ob->set_skill("dodge",50);
        ob->set_skill("force",50);
        ob->set_skill("spells",50);
        ob->set_skill("unarmed",50);
        ob->set_skill("sword",50);
        ob->set_skill("parry",50);
        ob->set_skill("literate",50);
        ob->set_skill("baihua-zhang",50);
        ob->set_skill("moondance",50);
        ob->set_skill("moonforce",50);
        ob->set_skill("moonshentong",50);
        ob->set_skill("snowsword",50);
write(HIW+"�����һ�Ź㺮�鵤��ֻ����һ�����������������!��ʱ����¹����书��������\n"NOR);

        message("vision", HIM + ob->name() + 
"����һ�Ź㺮�鵤��ֻ����һ������������������!��ʱ�����¹����书��������\n"NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}