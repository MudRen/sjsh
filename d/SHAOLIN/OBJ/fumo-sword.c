// fumo-sword.c ��ħ��
// writed by piao 2001-10-04

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIY"��ħ��"NOR, ({ "fumo sword", "sword" }));
        set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
                set("long", HIW"����һ������ѩ���ķ�ħ�������м�������Ѫ��������������ƥ��
ӳ���������˽�������ǰ�ɴ�Ħ����Я����ԭ��һ·��֮������ħ��
���Ƿ�����Ͻ�ħ������\n"NOR);
        set("value", 100000);
		set("material", "steel");
		set("wield_msg", HIY "ֻ�������һ������ħ�����ʷɳ�������Ծ��$N���С�
˲ʱ��ʼ���Ʊ�ɫ������������������һƬ�ޱ�ɱ�⡣\n" NOR);
		set("unwield_msg", HIY "��ħ����$N���з����ڰ����һת����ৡ���Ծ�뵶�ʡ�\n" NOR);
	}
        init_sword(160);
	setup();
}
