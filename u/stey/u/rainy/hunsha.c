#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIW"ѩ�׻�ɴ"NOR, ({"hunsha", "cloth"}) );
        set("long", "�������ʱ�����İ�ɫ��ɴ���\n");
        set_weight(0);
  set("wear_msg", HIW"$N����ѩ�׵Ļ�ɴ������ͯ���еİ�ѩ������\n"NOR);
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

