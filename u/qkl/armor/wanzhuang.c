// lianyi.c ������װ
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIM"������װ"NOR, ({"lianyi wanzhuang","wanzhuang", "cloth"}));
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", HIM"һ����ϯʢ����ᴩ�����³�ȹ��\n¶�����أ�ȹ�ŵ��أ�������£���ʶ�Ŀ��\n˭����ȥ��һ�����޶��ˣ���ѹȺ����\n"NOR);
                set("material", "cloth");
                set("value", 10000);
                set("armor_prop/armor", 255);
                set("armor_prop/spells", 255);
		set("armor_prop/dodge", 255);
        }
        setup();
}
