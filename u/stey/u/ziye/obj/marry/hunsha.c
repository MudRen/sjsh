#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"��׻�ɴ"NOR, ({"hunsha", "cloth"}) );
        set("long", "�������ʱ�����İ�ɫ��ɴ���\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/per", 20);
                set("value", 0);
                set("female_only", 1);

        }
        setup();
}

