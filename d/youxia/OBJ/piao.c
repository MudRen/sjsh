// pdan.c ƮƮ�� by piao
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"ƮƮ��"NOR, ({ "dan","piao dan" }) );
        set("long",HIW"ƮƮ������ʦ����Ʈ������ֶ��Ӿ������Ƶĵ�ҩ����;���ء�\n"NOR);
        set("unit", "��");
        set("weight", 5000);
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
        ob=this_player(); 
        ob->add("daoxing",0);
        ob->add("combat_exp",0);
        ob->add("potential",180000);
        ob->set("max_force",2700);
        ob->set("max_mana",2700);
        ob->set("max_kee",1000);
        ob->set("max_sen",1000);
        ob->set("max_gin",1000);
        ob->set("age",18);
        ob->set("int",30);
//      ob->set("title","��ͨ����");
      write(HIW+"�����һ��ƮƮ�����Լ�Ҳ��֪�����׷�����ʲô�仯��\n"NOR);
        destruct(this_object());
        return 1;
}

