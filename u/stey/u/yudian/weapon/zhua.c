// dagger.c : an example weapon

#include <weapon.h>

inherit DAGGER;

void create()
{
          set_name("�޳�צ", ({"zhua"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                 set("unit", "ֻ");
                 set("long", "����һֻ��צ�����Ű���ɫ�Ĺ�â���ƺ������������á�\n");
		set("value", 50);
		set("material", "steel");
	}
          init_dagger(88);

// These properties are optional, if you don't set them, it will use the
// default values.

          set("wield_msg", "$N��˫��ӭ��һ�Σ�ֻ���̹�һ����$n����$N���С�\n");
          set("unwield_msg", "$N��˫��ӭ��һ�Σ�ֻ���̹�һ����$n�Ѿ�������\n");

// The setup() is required.

	setup();
}
