// changjian.c ����

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;

void create()
{
    set_name(HIW "���˽�" NOR, ({"sword", "jian"}));
    set_weight(20000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "����һ���������ĳ�����\n");
        set("value", 1);
                set("replace_file", "/d/obj/weapon/sword/changjian");
		set("material", "steel");
		set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
		set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
	}
    init_sword(125);
	setup();
}
