// jingubang.c

#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE; 
    inherit WHIP;

void create()
{
                set_name( HIR "һ�����"+ HIC"****"+HIY "ս���"+HIC"****" NOR, ({ "whip", "bian" }) );
	set_weight(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                  set("unit", "��");
                  set("no_give", "��ô�õı�����ҲҪ���ˣ���");
        set("value", 1000000000000);
      set("no_sell","С��С����Ӫ��������ô���صı��\n");
		set("material", "gold");
                  set("no_drop", "��ô��������ԯ�����ù��ı���������ӣ�");
                 set("replace_file", "/d/obj/weapon/sword/snowsword");
                  set("long", "�˽�����ԯ�ȵ�����ʹ�õı����������ޱȣ������޴��ֱ��Ͽ��ţ�����ԯ�����֡�\n");
          set("wield_msg", "$Nһ���֣����ȼ����������������ɣ����Ǻ�����������ʱ����һ��$n��\n");
          set("unwield_msg", "$Nһ��������$n��$N�������˸���������Ȼ�����ˡ�\n");
	}
         init_whip(200);
	setup();
}
