#include <weapon.h>
#include <ansi.h>

inherit FORK;
inherit F_UNIQUE;
void create()
{
        set_name(HIY"������"NOR,({ "xiangyao chan", "cha","fork" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 500000);
                set("unique", 1);
                set("rigidity", 5);
                set("sharpness", 1);
                set("weapon_prop/dodge", -5);
                set("weapon_prop/parry", 5);        
                set("material", "gold");
                set("wield_force", 100);
                set("wield_maxforce", 700);
                set("wield_str", 22);
                set("wield_msg",HIY"ֻ������ৡ���һ������߷���һ��ϼ�⣬����һ����$N����
                ����һ�ѽ����\n"NOR);
                set("long", HIY"\nһ����������ؽ�棬�������ն����������ϸ��ȥ����ͷ�ƺ��е��\n
                �֣�������Խ�ʲô������\n"NOR);                
                set("unwield_msg", HIY "ն���������շɳ����ַɻ���$N�����С�\n"NOR);               
        }
        init_fork(80);
        setup();
}

