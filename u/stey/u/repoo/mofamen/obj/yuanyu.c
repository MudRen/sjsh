//copy from yuanyu by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIG"Բ��"NOR, ({"yuan yu","yu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ��Բ�εĴ���\n");
     set("unit", "��");
    set("material", "stone");
       }
  setup();
}
