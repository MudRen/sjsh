#include <armor.h>

#include <ansi.h>
inherit FINGER;

void create()
{
  set_name(HIW"�����ָ"NOR, ({ "zuan jie", "zuanjie", "ring" }));
  set("long","��Ө��͸��"+query("name")+"�������������۶��ڹ�Ԫ������һ����¶�ʮ���ճɻ�"+"��\n");
  set("weight", 0);
                set("armor_prop/armor", 50);
                set("armor_prop/dodge", 50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "ö");
    set("value", 12000);
    set("material", "diamond");
    set("armor_prop/armor", 1);
    set("armor_prop/personality", 10);
  }
  setup();
}       
int query_autoload() { return 1; }
