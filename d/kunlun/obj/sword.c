
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIC"���ɽ�"NOR, ({ "zhuxian sword", "zhuxian", "sword" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","����һ�ѽ�������һ������ɫѪ�۵ĳ�����\n");
                set("value", 2400);
                set("material", "blacksteel");
                set("wield_msg", "$N����ɫ�����г��һ����һ������ɫѪ�۵�$n�������С�\n");
                set("unequip_msg", "$N�����е�$n�����������ɫ���ʡ�\n");
        }
        init_sword(160);
        setup();
}
 