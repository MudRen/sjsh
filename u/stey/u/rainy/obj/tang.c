#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;
void create()
{
set_name(HIW "ǧ��ѩ֮¶" NOR, ({ "xuelu"}));
set_weight(600);
if( clonep() )
set_default_object(__FILE__);
else {
set("long", "һ������ɽ�ϸղ�����ǧ��ѩ�����������ڵ��µİ���ջ��꣬���Ƴɵ���ˮ����¶��\n");
set("unit", "��");
set("value", 120);
set("max_liquid", 100); 
set("liquid_supply", 80);
};
set("liquid", ([
"type": "water",
"name": "ǧ��ѩ֮¶",
"remaining": 90,
]) );
setup();
}
