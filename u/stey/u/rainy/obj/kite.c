#include <ansi.h>
#include <dbase.h>
#include <armor.h>
inherit NECK;
void create ()
{
set_name(HIC "ֽ�" NOR, ({ "kite"}));
set_weight(100);
set("long","˿�ʵĺ�������,��ӯ���ƺ�û��������."+query("name")+"��\n");;
set("unit", "ֻ");;
set("armor_prop/armor", 1);
set("armor_prop/personality", 10);;
set("wear_msg","$NȸԾ��һ·����,���������Խ��Խ��,����"+query("name")+"�ڿ��п��ֵķ����š�\n");;
set("unequip_msg", "$N���˲����ϵĺ���,һ��������˿��,Ҳ����������������Ϣ��"+query("name")+"��\n");;;;
setup();;
};
