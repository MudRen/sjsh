#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
set_name( HIY "̫��֮��" NOR, ({ "sun staff", "sun", "staff" }) );
set_weight(100);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("Can_avoid_find", 1);
set("value", 5000);
set("material", "gold");
set("long", "̫��֮������֮�ߡ���\n");
set("wield_msg", "$N�����������Ĩ��һ˿�������Ц���ó�һ��"+query("name")+"�������У�Ӣ���ˬ�����г���֮�ơ�\n");
set("unwield_msg", "$N��"+query("name")+"�ջأ����Ϊ֮��Ȼ�������ˡ�����أ�����ꡯ֮ħ�ȡ�\n");
}
init_staff(1000);
setup();
}
