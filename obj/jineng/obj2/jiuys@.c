// jiuys.c

#include <ansi.h>
#include "medicine.h"

void create()
{
        set_name( MAG"��ת���赤" NOR, ({"jiuzhuan dan", "dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ��ʮ������ҩ�裬�����ӹ��������洦��\n");
                set("unit", "��");
                set("value", 60000);
                set("drug_type", "yaodan");
                set("base_unit","��");
        }
        setup();
}

int do_eat(string arg)
{
        mapping my;
        object me=this_player();
        int lv;
        if(! arg || arg!="jiuzhuan dan")
                {
                write("��ʹ��ʲôҩ��\n");
                return 1;
                }
        if (time() - me->query("last_eat/jz") < 90000)
        {
                write("��շ��ù�ҩ����ҩ�Է�����Ч���Ժ���ܼ������á�\n");
                return 1;
        }

        lv = me->query("level",1);
        
        if (lv < 50 )
        {
                write("�������ɽ�ȼ�̫�ͣ�����" + name() + "Ҳ��û�á�\n");
                return 1;
        }

        me->set("last_eat/jz", time());

        message_vision(CYN "$N" CYN "����" + name() +
                       CYN "����ʱ������\n" NOR, me);

        me->add_maximum_force(50);
        me->add_maximum_mana(50);
        me->start_busy(3);
        destruct(this_object());
        return 1;
}
