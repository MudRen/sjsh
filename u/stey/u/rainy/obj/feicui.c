#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIB "�����" NOR, ({ "feicui"}));
set_weight(100);
set("long","ī��ɫ����仨����һ�����㣬�����ڻ�����˼�������µ�....."+query("name")+"��\n");;
set("unit", "��");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("wear_msg","$N��һ��"+query("name")+"�ó������ϣ����Ϸ���һ����ơ�\n");;
  set("unequip_msg", "$N��һ��"+query("name")+"����̺�֮�С�\n");;;
set("unit", "��");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
setup();;
};

