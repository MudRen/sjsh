//copy from manao by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(RED"�������"NOR, ({"liubian manao","manao"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��������ε���觡�\n");
     set("unit", "��");
    set("material", "stone");
       }
  setup();
}
