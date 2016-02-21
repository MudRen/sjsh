#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
      if(this_player()==environment())
        add_action("do_eat", "eat");
}

void create()
{
        set_name(BLINK "��ɮ��" NOR, ({"tangseng rou", "tangseng rou", "rou"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
              set("no_sell",1);
                        set("no_drop",1);
                         set("no_give",1);
                set("drug_type", "��Ʒ");
        }
  
        set("is_monitored",1);
        setup();
}

int do_eat(string arg)
{
        int howmany;

        object me = this_player();
  
        if (!id(arg)) return notify_fail("��Ҫ��ʲô��\n");

        howmany = (int)me->query("rsg_eaten");
  
        me->set("food", (int)me->max_food_capacity());

        me->set("rsg_eaten", howmany+5);

        message_vision(HIW "$N����ɮ��������һ��������ؽ���������\n" NOR, me);  

        me->set("obstacle/wuzhuang","done");
            me->add("cps",-1);

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"���������ɮ�⣬�����޳��˲����ֻأ��Ӵ����������⣬���������У��������������ˣ�" );
        }

        destruct(this_object());

        return 1;
}
