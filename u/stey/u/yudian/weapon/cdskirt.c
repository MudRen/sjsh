#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void init()
{
  cloth::init();
}
void create()
{
              set_name(HIB"����ȹ"NOR, ({"chao duan qun", "skirt","qun" }) );
          set("long", "һ���̵Ĳ����ٶ̵�ȹ�ӡ�\n");
        set_weight(0);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("unit", "��");
                  set("material", "lamp");
                set("female_only", 1);
                  set("armor_prop/armor", 20);
                set("armor_prop/personality", 10);
                set("value", 0);
        }
        setup();
}
