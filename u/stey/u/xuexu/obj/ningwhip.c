// ��˪��
#include <weapon.h>
#include <ansi.h>
inherit WHIP;
inherit F_UNIQUE;
void create()
{
        set_name(HIW"��˪��"NOR, ({"ningshuang whip", "whip"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","һ������ɫ�ĳ��ޣ���ͬ˪ѩ����֮�п̹�֮���⡣\n");
                set("unit", "��");
                set("replace_file", "/d/obj/weapon/whip/pibian");
                set("value", 20000);
                set("wield_msg", HIW"$N����һЦ������������һ̽��һ��ѩ��ɫ�ĳ�������������һ��Ȧ��\n"NOR);
set("unwield_msg", HIW"$N��̾һ����������$n�������䡣\n"NOR);
set("weapon_prop/courage", 20);
}
        init_whip(150);
        setup();
}
