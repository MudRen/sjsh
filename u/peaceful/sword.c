// ������.c


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
  set_name(HIC  "������" NOR, ({ "niren sword", "jian", "sword" }) );
  set_weight(10000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("value", 10000);
    set("material", "blacksteel");
    set("long", "��һ�o����������,���h���o��,���Ǿp�儦�ĵı�����\n");
    set("wield_msg", "һ������������$N�����Ѷ��˰�$n��\n");
       set("unequip_msg", "$N�������е�$n��\n");
  }
  init_spear(490);
  setup();
}

