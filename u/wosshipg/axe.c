// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
inherit AXE;

void create()
{
             set_name( HIR "һ�����"+ HIC"****"+HIY "ս��"+HIC"****" NOR, ({ "axe", "fu" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                  set("unit", "��");
                  set("no_give", "��ô�õı�����ҲҪ���ˣ���");
        set("value", 1000000000000);
      set("no_sell","С��С����Ӫ��������ô���صı��\n");
		set("material", "gold");
               set("no_drop", "��ô���������ı���������ӣ�");
                   set("replace_file", "/d/obj/weapon/axe/xuanhua-fu");
  set("long", query("name")+HIW "���ȹ�ʱ�����������ı����������޴�\n");
          set("unwield_msg", CYN "$Nһ��������$n��$N�������˸���������Ȼ�����ˡ�\n");
          set("unwield_msg", "$Nһ��������$n��$N�������˸���������Ȼ�����ˡ�\n");
	}
init_axe(200);
	setup();
}
