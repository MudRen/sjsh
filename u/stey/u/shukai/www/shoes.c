#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_UNIQUE;

void create()
{
        set_name(HIW"̩ɽ��Ь"NOR,({ "shoes", "xie"}) );
        set_weight(1000);
                set("unit", "˫");
                set("value", 0);
                set("material", "cloth");
        set("armor_prop/armor", 50 );
        set("armor_prop/dodge", 50 );
        setup();
}

void init()
{
    add_action("do_break",({"break"}));
}

int do_break()
{
     object me, obj;
     me = this_player();
     obj = this_object();
     message_vision(HIY"\n<<<<<<<<<<>>>>>>>>>>\n"NOR, me);
     new("/u/shukai/www/leftshoe")->move(me, 1);
     new("/u/shukai/www/rightshoe")->move(me, 1);
     destruct(obj); 
     return 1;

}
