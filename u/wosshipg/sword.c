// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
  inherit SWORD;

void create()
{
              set_name( HIR "һ�����"+ HIC"****"+HIY "ս��"+HIC"****" NOR, ({ "sword", "jian" }) );
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
                 set("replace_file", "/d/obj/weapon/sword/snowsword");
  set("long", query("name")+"���ȹ�ʱ�����������ı����������޴�\n");
    set("wield_msg", "$N����ɱ��һ�֣�������ʱ����һ��$n��\n");
          set("unwield_msg", "$Nһ��������$n��$N�������˸���������Ȼ�����ˡ�\n");
	}
       init_sword(200);
	setup();
}
