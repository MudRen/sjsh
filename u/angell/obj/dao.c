// blade.c
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
set_name(HIW"������", ({"blade", "shoushu dao", "dao"}) );
   set_weight(4000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
        set("unit", "��");
        set("value", 500);
        set("material", "iron");
set("long", "��������ʦר�������õ����������䣬���������ޱȡ�\n");
set("wield_msg", "$N���һֻ���������$n�������С�\n");
set("unequip_msg", "$N�����е�$n���뻳�еĵ��ҡ�\n");
   }
init_blade(125);
   setup();
}

