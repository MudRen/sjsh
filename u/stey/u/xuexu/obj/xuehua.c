// created 17/3/2001 by xuexu
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIW "ѩ��" NOR, ({ "xuehua"}));
set_weight(100);
set("long","��������"+query("name")+"��\n");
set("unit", "��");
set("armor_prop/armor", 1);
set("armor_prop/personality", 2);
set("unequip_msg","$N��"+query("name")+"����ظ�Ħ�˼��£�ѩ��������������ˮ�顭����\n");
set("wear_msg", "$N����"+query("name")+"��ѩ����ͬ������ˮ����������ҫ�ž����Ĺ�â��\n");
setup();
}
