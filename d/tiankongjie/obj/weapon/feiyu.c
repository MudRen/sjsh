// �����硤���μǡ��汾��������
#include <ansi.h>
/* <SecCrypt CPL V3R05> */
 
//feiyu

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name(HIR"�����"NOR, ({ "fenghuang ling","ling" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",HIR"���ǻ������ϵ���ë������ȼ���Ż��档\n"NOR);
                set("unit", "Щ");
                set("base_unit", "֦");
                set("base_weight", 40);
                       set("value", 20000);
                set("base_value", 50);
        }
        set_amount(30);
        init_throwing(100);
        setup();
}

