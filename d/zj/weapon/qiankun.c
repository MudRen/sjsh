// Ǭ���� by Calvin

#include <weapon.h>
#include <ansi.h>
inherit STICK;
void create()
{
        set_name(HIY"Ǭ����"NOR, ({ "qiankun stick","qiankun", "bang","stick" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 50000);
                set("material", "gold");
                set("no_sell", 1);
                set("no_give", 1);
                set("no_drop", 1);
                set("long", "һ��������������ר�õİ��ӡ�\n");
                set("wield_msg", "$N����һ��$n��˳�����˸�������\n");
                set("unwield_msg", "$N����һ������$n��غ�����\n");
        }
        init_stick(100);
        setup();
}
