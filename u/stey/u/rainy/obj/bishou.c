#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
set_name( HIW "ذ��" NOR, ({ "bi shou", "bishou", "dao" }) );
set_weight(100);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("Can_avoid_find", 1);
set("value", 5000);
set("material", "gold");
set("long", "���ɫ��ذ�ף���������һ˿���⣬�����ޱȣ�һ��������Ѫ���ӵ����ϵ���������\n");
set("wield_msg", HIW"$N�����Լ����������ڿ��л���һ��Ư���Ļ�����̾������������������ڣ�����������"+query("name")+HIW"���������������ϵ��Ǹ�����......\n"NOR);
set("unwield_msg", HIW"$N���е�ذ�׵����ڵأ�����һ������������ѩ�׵���������������Ѫ�����������Ȼ��ͷת���������������Լ���������Ʈ��...Ʈ�ţ��롰��ڣ��Խ��ԽԶ���Ǹ�����С���  �á���\n"NOR);;
}
init_blade(100);
setup();
}
