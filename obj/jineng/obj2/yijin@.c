// baochi.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name(HIW "��������ɢ" NOR, ({"yiqi san", "yiqi"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ɢҩ�棬������ȫ�ָ�����������Ч����\n");
                set("base_unit", "��");
                set("value", 50000);
                set("unit", "��");
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
                write("��Ҫ��ʲôҩ��\n");
                return 1;
        }
        if (time() - me->query_temp("last_eat/yqs") < 50)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        my = me->query_entire_dbase();
        if (my["kee"] >= 3*my["max_kee"]/4)
        {
                write("�������������棬�������" + name() + "��\n");
                return 1;
        }

        me->set_temp("last_eat/yqs", time());

        message_vision(HIW "$N" HIC"��" + name() +"Ӳ������ȥ"
                       HIW "����ʱ���������������\n" NOR, me);
       
        me->set("eff_kee",me->query("max_kee"));
        me->set("kee",me->query("max_kee"));
//      me->start_busy(1);
        destruct(this_object());
        return 1;
}
