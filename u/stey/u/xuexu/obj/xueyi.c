// created 19/3/2001 by xuexu
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
set_name(HIW"ѩ������"NOR, ({"xueyi", "cloth"}) );
set("long", "���������Ϥ��ѩ�������ѩ�������ɵ��·�����˵���˿��Ե�������֮��\n");
set_weight(0);
set("wear_msg", HIW"$N΢΢һЦ����ѩ������������ȫ��������ɴ������Ŀ��ֻ����һ���������ʡ�\n"NOR);
set("unequip_msg",HIW"$N���ֽ����ϵ���ɴժ��������һ�ɴ��ź�����������������ռ䡣\n"NOR);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "��");
set("material", "cloth");
set("armor_prop/per", 100);
set("armor_prop/dodge", 200);
set("armor_prop/armor", 100);
set("value", 0);
set("female_only", 1);
}
setup();
}
