// ������ by Calvin

#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
          set_name(HIY"������"NOR, ({"fengshen fazhang", "fazhang", "zhang", "staff"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "һ�����µ�С����,���������������,�ǵ÷��ٷ���ʱʹ�õġ�\n");
           set("replace_file", "/d/nanhai/obj/budd_staff");
           set("weapon_prop/strength", 10);
                set("value", 10000000);
                set("material", "brass");
                set("no_sell", "1");
                set("wield_msg", "��Ȼ�������¡¡,ԭ����$N�ó�һ����ʺ����$n���������С�\n");
                set("unwield_msg", "$N�������е�$n��\n");
        }
        init_staff(100);
        setup();
}
