//copy from bone by repoo

#include <ansi.h>
#include <armor.h>
inherit F_UNIQUE;
inherit ARMOR;

void create()
{
  set_name(HIY"����"+HIB"֮��"NOR, ({"long yi","yi"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�Գ������ϵ���\n");
    set("unit", "��");
    set("material", "cloth");
                set("value", 0);
                 set("armor_prop/armor", 150);
                set("armor_prop/dodge", 100);
  }
  setup();
}
void init()
{
        check_owner();
}
