// by snowcat oct
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("�������", ({"xioujin pifeng", "pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "����һ������ĸ���ﲻС�Ķ��������硣\n");
    set("material", "leather");
    set("unit", "��");
    set("value", 150000);
    set("armor_prop/armor", 80);
  }
  setup();
}
