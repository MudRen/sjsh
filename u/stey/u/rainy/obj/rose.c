#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(MAG "��Ǿޱ" NOR, ({ "rose"}));
set_weight(100);
set("long","����ɫ�Ļ���ӯ�����ư��㣬�峿�������£�������΢Ц��....."+query("name")+"��\n");;
set("unit", "��");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("unequip_msg","$N�ŵ�һ�ư��㣬��������̽��������һ�䵭��ɫ��"+query("name")+"��Ц�ڻ���֮�С�\n");;
set("wear_msg", "$N��Цٻ�⣬�����ϵ���������ȡ��һ֦����¶ˮ��"+query("name")+"�����ڱ�ǰ����һ�����㡣\n");;;
set("unit", "��");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("unequip_msg","$N�ŵ�һ�ư��㣬��������̽��������һ����ɫ��"+query("name")+"��Ȼ�ڻ���֮�С�\n");;
set("wear_msg", "$N��Цٻ�⣬�����ϵ���������ȡ��һ֦����¶ˮ��"+query("name")+"�����ڱ�ǰ����һ�����㡣\n");;;
setup();;
};
