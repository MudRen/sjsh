#include <ansi.h>

inherit F_SAVE;
inherit COMBINED_ITEM;

void create()
{
  set_name("��õ��", ({ "flower","rose","hua" }) );
  set("unit","��");
  set("base_weight",10);
  set("long","һ��ˮ����˵ĺ�õ�壬ɢ����һ˿���������㡣\n");
  set("base_unit","��");
  set("material", "flower");
  set_amount(1+random(3));
  setup();
}
