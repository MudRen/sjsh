#include <weapon.h>
#include <ansi.h>

inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"��页�"NOR,({ "suoluo dao", "dao", "blade" }) );
        set_weight(29000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("treasure", 1);
                set("unit", "��");
                set("value", 1000000);
                set("unique", 1);
                set("rigidity", 6);
                set("sharpness", 4);
                set("weapon_prop/dodge", -8);
                set("weapon_prop/parry", 8);        
                set("material", "gold");
                set("wield_force", 300);
                set("wield_maxforce", 1100);
                set("wield_str", 25);
                set("wield_msg", HIY"ֻ������ž����һ������页�Ծ��$N���У�������������������\n"NOR);
                set("long", HIY"\nһ�ѽ�ɫ�ĳ�����������з�ħ�������ԡ�����Խ�����(fen)����\n"NOR);
                set("unwield_msg", HIY "$N����页����£��������˿�����\n" NOR);               
        }
        init_blade(120);
        setup();
}

void init()
{
    add_action("do_sub",({"fen", "��"}));
}

int do_sub()
{
     object me, obj;
     me = this_player();
     obj = this_object();

     message_vision(HIY"\nֻ������ һ�����죬$N����页�������������页��ڿ���һ��Ϊ������Ϊ��������ַɻ���$N�����У�\n"NOR, me);
     new("/u/xintai/weapon/fumodao")->move(me, 1);
     new("/u/xintai/weapon/xiangyaochan")->move(me, 1);  
     destruct(obj); 
     return 1;

}
