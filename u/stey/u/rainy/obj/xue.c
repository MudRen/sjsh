#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name(HIB"����ѥ"NOR, ({"meng wuxue", "shoes"}) );
set("long", "ˮ��ɫ����ѥ��װ�����������������������һ�����׵���֮�á�n");
set_weight(0);
set("wear_msg", HIB"$N����ɫ����ѥ���ڽ��ϣ���ϸ��ϵ��˿�����趯��һ�����ε����ѡ�......\n"NOR);
set("unequip_msg",HIB"$N����ѥ�ϵĻҳ���С�ĵ��������У����ɵ�˼�������е��˶�����\n"NOR);;
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "˫");
set("material", "shoe");
set("armor_prop/per", 10);
set("value", 0);
set("female_only", 1);
}
setup();
}
