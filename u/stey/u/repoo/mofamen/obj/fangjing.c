//copy from fangjing by repoo

#include <ansi.h>
inherit ITEM;

void create()
{
  set_name(HIW"����"NOR, ({"fang jing","jing","shuijing"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "һ�������ε�ˮ��ʯ��\n");
    set("unit", "��");
    set("material", "stone");
     }
  setup();
}
