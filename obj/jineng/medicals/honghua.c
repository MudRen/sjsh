//ҩ��

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(RED "�컨" NOR, ({"hong hua","honghua","yao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���Ի�Ѫ���ٵĺ�ҩ�ġ�\n");
    set("value", 100);
    set("drug_type", "yaodan");
  }
  setup();
}