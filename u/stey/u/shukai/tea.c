#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void create()
{
        set_name(HIG "���" NOR, ({"tea"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "һ����������Ƭ��ҶƮ���ڱ���ɫ��ˮ�У����ĵ�����������\n");;
      set("value", 120);;
       set("max_liquid", 100); 
       set("liquid_supply", 80);
        }
        set("liquid", ([
                "type": "water",
                "name": "���",
                "remaining": 400,
                "drunk_apply": 40,
        ]));
}
