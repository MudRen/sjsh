//mace.c
//created 6-31-2001 by piao

#include <weapon.h>
#include <ansi.h>

inherit MACE;

void create()
{
  set_name(HIW"�����"NOR, ({"dashen whip", "mace", "dashen","whip"}));
  set_weight(17000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 1000);
    set("material", "iron");
    set("long", "һ����ͨ����ڱޡ�\n");
    set("wield_msg", "$N����һ��$n�����˸���ʽ��\n");
    set("unwield_msg", "$N��$n������䡣\n");
  }
  
  init_mace(150);
  setup();
}

