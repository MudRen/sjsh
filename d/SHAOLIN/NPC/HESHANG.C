// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("和尚", ({"he shang", "heshang"}));
        set("gender", "男性" );
	create_family("少林寺", 39, "弟子");
        set("title",HIG"少林寺"NOR);
        set("age", 30);
        set("long", "一个中年和尚手持数珠，正在喃喃念经。\n");
        set("combat_exp", 30);
        set("attitude", "peaceful");
        setup();
}

