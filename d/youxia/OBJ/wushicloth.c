// cloth.c
//created 17-06-2001 ����Ʈ(piao)


#include <armor.h>

inherit CLOTH;
#include <ansi.h>
void create()
{
	set_name(HIW "��ʿ����" NOR, ({ "whitecloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "���Ǽ�ֻ���书���ߵ���ʿ�ſ��Դ��İ��ۡ�\n");
		set("value", 10000);
		set("material", "cloth");
		set("armor_prop/armor", 60);
	}
	setup();
}
