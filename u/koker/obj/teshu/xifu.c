// xifu.c
//Ŷ���������

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

//inherit F_UNIQUE;

void create()
{
	set_name(HIY"��������"NOR, ({ "xifu", "fu" }) );
	set("long", "����˭����˭�������������Ը�������Ը����\n");
	set_weight(300);
	else {
		set("unit", "��");
		set("material", "cloth");
		set("armor_prop/armor", 500);
		set("armor_prop/spells", 500);
		set("armor_prop/dodge", 100);
                set("armor_prop/force", 500);
		set("value", 50000);
//Ը���Ĵ�����ʱû��
	}
	setup();
}