//ҩ��ϵ��-duhuo.c

#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(RED "����" NOR, ({"du huo"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "һ���ϻ��Ĺ�ͷ��\n");
    set("value", 0);
    set("drug_type", "yandan");
   // set("yaocai_remaining", 3);
  }
  setup();
}




