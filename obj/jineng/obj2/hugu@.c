 // hugujiu.c 

#include <ansi.h>
#include "medicine2.h"

void create()
{
        set_name( GRN"���Ǿ�" NOR, ({"hugu jiu", "jiu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ɫ�Ļ��Ǿƣ����˵����ƺܼ���Ч��\n");
                set("base_unit", "ƿ");
                set("value", 300);
                set("unit","ƿ");
                set("drug_type", "yaodan"););
             }
        setup();
}

int do_eat(string arg)
{
        object me=this_player();
        mapping my;
       
        if ( !arg || arg != "hugu jiu" )
        {
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/hugu") < 5)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

         my = me->query_entire_dbase();
        if (my["eff_kee"] == my["max_kee"])
        {
                write("�����ڲ�û�����ˣ����ط���" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/hugu", time());

        message_vision(HIW "$N" HIW "��ཹ�ཱུع�������" + name() +
                       HIW "������ȥ����ö��ˡ�\n" NOR, me);

        me->receive_curing("kee", 150);
        me->receive_heal("kee", 150);

//        me->start_busy(1);
        destruct(this_object());
        return 1;
}
