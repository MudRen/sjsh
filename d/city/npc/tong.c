// tong.c Сҩͯ by piao
inherit F_VENDOR_SALE;
#include <ansi.h>
void create()
{
reload("yangzhongshun");
        set_name("Сҩͯ", ({"yao tong","tong"}));
        set("title", "ҩ��С��");
        set("vendor_goods", ([
        "yao"   :"/d/obj/drug/jinchuang",
        "dan"   :"/d/obj/drug/hunyuandan",
        ]) );
          setup();
}

void init()
{
           object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

