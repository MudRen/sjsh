//hugu.c

#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW "����" NOR, ({"hu gu"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���ϻ��Ĺ�ͷ��\n");
    set("value", 1000);
    set("drug_type", "yaodan");
  //set("yaocai_remaining", 3);
  }
  setup();
}