#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(RED "��Ҷ" NOR, ({ "miss"}));
set_weight(100);
set("long","���ƺ�Ҷ��ң����˼֮�顣��ҶƮƮ����˼����.....һƬ"+query("name")+"��\n");;
set("unit", "Ƭ");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("wear_msg",RED"$N����һƬ��Ҷ�����ţ�������������ƪ����.....��\n");;
set("unequip_msg", RED"$N����ҶС�ĵļ������У��������㣬������Դ���¡�\n");;;
set("unit", "Ƭ");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
setup();;
};

