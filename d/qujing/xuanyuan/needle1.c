#include <weapon.h>
inherit SWORD;

void create()
{
        set_name("֯����", ({ "zhen", "needle" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����槼��������ʱ�򶪵�һЩ��Ʒ.\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N����һ��,���������һ��$n��\n");
                set("unwield_msg", "����һ��,���е�$n������.\n");
        }
        init_sword(70);
        setup();
}
