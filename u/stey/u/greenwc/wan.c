// wan.c ��Ѫ����

#include <ansi.h>

inherit ITEM;

void create()
{
            set_name(HIR"��Ѫ"HIY"����"NOR, ({ "wan","dabu wan" }) );
        set("long",
HIG"��Ѫ��������糴彣�ĵ��ط����ɼ��������ҩ�ģ���ʱ�������ƶ��ɵ��鵤����ǿ����֮��Ч\n"NOR);
        set("unit", "��");
        set("weight", 5);
        set("value", 100);
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
          ob->set("daoxing",2000000);
           ob->set("max_kee",1000);
           ob->set("max_sen",1000);
              ob->set("eff_kee",1000);
              ob->set("eff_sen",1000);
             ob->set("kee",1000);
             ob->set("sen",1000);
            ob->set("combat_exp",1600000);
          ob->set("potential",15000);
         ob->set("max_force",2000);
          ob->set("max_mana",2000);
         ob->set("force",2000);
         ob->set("mana",2000);
         ob->set("maximum_force",2000);
         ob->set("maximum_mana",2000);
           ob->add("balance",200000);
write(HIR+"�����һ����Ѫ���裬ֻ����һ�����������������!����hp��һ�°�...\n"NOR);

        message("vision", HIR + ob->name() + 
"����һ����Ѫ���裬ֻ����һ�����������������!����hp��һ�°�...\n"+NOR,
                environment(ob), ob);
        destruct(this_object());
        return 1;
}
