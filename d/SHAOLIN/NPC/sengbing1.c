//gunseng.c

int ask_name(); 

inherit NPC;
#include <ansi.h>
void create()
{

set_name("执法僧兵", ({
		"seng bing",
		"seng",
		"bing",
	}));
        set("gender", "男性" );
        create_family("少林寺", 10, "弟子");
        set("title", HIG"少林寺"NOR );
	set("age", 28);
set("long",
		"他是一位身材高大的中年僧人，两臂粗壮，膀阔腰圆。他手持兵\n"
		"刃，身穿一袭灰布镶边袈裟，似乎有一身武艺。\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 1700);
        set("max_force", 900);
        set("force_factor", 70);
        set("mana", 1700);
        set("max_mana", 900);
        set("mana_factor", 20);
        set("combat_exp", 1000000);
        set("daoxing", 500000);

        set_skill("banruo-zhang", 130);
        set_skill("yijinjing", 130);
        set_skill("chanzong", 100);
	set_skill("spells", 100);
	set_skill("unarmed", 150);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("stick", 130);
        set_skill("zui-gun", 150);
        map_skill("unarmed", "banruo-zhang");
        map_skill("stick", "zui-gun");
        map_skill("parry", "zui-gun");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/jiedao")->wield();
        carry_object("/d/shaolin/obj/cloth")->wear();


}


