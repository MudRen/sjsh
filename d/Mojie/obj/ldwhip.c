#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(HIG"������"NOR, ({"liudu whip", "whip", "lian"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ�������ı��ӣ�����մ����Ѫ��\n");
                set("unit", "��");
                set("value", 500);
        }
        init_whip(125);
        setup();
}

