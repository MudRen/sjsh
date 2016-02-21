// baochi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIW "易气护心散" NOR, ({"yiqi san", "yiqi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是一包散药面，具有完全恢复体力的神奇效果。\n");
                set("base_unit", "包");
                set("value", 50000);
                set("unit", "包");
                set("drug_type", "yaodan");
        }
        setup();
}
int do_eat(string arg)
{
       object me=this_player();
       mapping my;
        if( !arg || arg != "yiqi san" )
        {
                write("你要用什么药？\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/yqs") < 50)
        {
                write("你刚服用过药，需药性发挥完效用以后才能继续服用。\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["kee"] >= 3*my["max_kee"]/4)
        {
                write("你现在体力充沛，无需服用" + name() + "。\n");
                return 1;
        }

        me->set_temp("last_eat/yqs", time());

        message_vision(HIW "$N" HIC"把" + name() +"硬吞了下去"
                       HIW "，顿时浑身充满了力量。\n" NOR, me);
       
        me->set("eff_kee",me->query("max_kee"));
        me->set("kee",me->query("max_kee"));
//      me->start_busy(1);
        destruct(this_object());
        return 1;
}
