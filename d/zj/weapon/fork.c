// ������ by Calvin

#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name(HIB"������"NOR, ({ "hujing fork", "hujing","cha","fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 500000);
                set("material", "iron");
                set("no_sell", 1);
                set("long", "һ������������Ƴɵ����,����һ��ר�ñ�����\n");
                set("wield_msg", "$N����һ��$n���ε��������\n");
        }
        init_fork(100);
        setup();
}
