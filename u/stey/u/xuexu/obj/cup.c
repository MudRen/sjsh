#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
set_name(HIY "�ջ���" NOR, ({ "cha"}));
set_weight(600);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "һ�����ż���С����ľջ��裬���滹ð��˿˿������\n");
set("unit", "��");
set("value", 120);
set("max_liquid", 100); 
set("liquid_supply", 80);
}
set("liquid", ([
"type": "water",
"name": "�ջ���",
"remaining": 90,
]) );
setup();
}
