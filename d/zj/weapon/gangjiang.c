// �ɽ��� by Calvin 

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIW"�ɽ���"NOR, ({ "ganjiang sword", "ganjiang","jian", "sword" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("material", "steel");
                set("no_sell",1);
                set("long", "����һ����ؼ���Ȼ�γɵ�һ�Ѵ���ɫ����������͸��,�����ޱȡ�\n");
                set("wield_msg", "һ���׹�������$N�����Ѷ��˰�$n��\n");
                set("unequip_msg", "$N�������е�$n��\n");
        }
        init_sword(80);
        setup();
}
