#include <ansi.h>
#include <weapon.h>

inherit STICK;

void create()
{
        set_name( HIY "���ǰ�" NOR, ({ "star bang", "starbang", "bang" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("Can_avoid_find", 1);
                       set("value", 5000);
                set("material", "gold");
set("long", "����������Сħ��,ͷ�ϵ���һ�Ž��ɫ��С���ǡ���\n");
                set("wield_msg", "����һЦ���������ѽѽ�����˼��������һ������������Ǳ��һ��"+query("name")+"����������˸���������\n");
                set("unwield_msg", "$Nһ������������ȣ�С��С��С��$n��$N����ת�˼�ת����Ȼ�����ˡ�\n");
        }
        init_stick(1000);
        setup();
}
