// blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("���ǵ�", ({"duopo dao", "dao", "blade"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 500000);
		set("material", "steel");
		set("long", "���صĹֽв����ڶ����ù����һ�ѵ���\n");
		set("wield_msg", "$N���һ��$n��৵��������У���ɽ��Ұ�ƺ���һ����ɭ֮�������֡�\n");
		set("unequip_msg", "$N�����е�$n��������ĵ��ʣ�һ���ֶ�ƽ���ˡ�\n");
	}
	init_blade(125);
	setup();
}
