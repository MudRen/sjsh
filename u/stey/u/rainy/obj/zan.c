#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIC "��˿��" NOR, ({ "fazan"}));
set_weight(100);
set("long","��ϸ��һ���������澫�ɵ���������Ϸ�����˿˿ϸϸ��ѩ�� ��������ӯӯ��Ʈ......"+query
("name")+"��\n");
set("unit", "֦");;
set("armor_prop/armor", 1);;
set("armor_prop/personality", 10);
set("unequip_msg","$N��"+query("name")+"����ж�£��������У���ɫ��Ȼ����������Ϧ�Ǻ�Ϧ����\n");;
set("wear_msg", "$N΢΢һЦ�����������˿˿�㷢����һ֦ "+query("name")+"���ڷ��С�\n");;;
setup();;
}
