
inherit NPC;
void create()
{
	set_name("护岛使女", ({"guard" }));
	set("gender", "女性" );
	set("age", 16);
	set("long", "神龙岛女弟子。\n");
	set("class", "yaomo");
	set("combat_exp", 25000);
	set("daoxing", 30000);
	set("attitude", "peaceful");
	set("per", 21);
	set("max_kee", 300);
	set("max_sen", 300);
	set("force", 300);
	set("max_force", 250);
	set("force_factor", 5);
	setup();

	set("eff_dx", -8000);
	set("nkgain", 60);

}
void init()
{       
        object ob=this_player();
	object me=this_object();

        ::init();

        if ( ob->query("id")=="cnd")
        {
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
                command("chat* 只听神龙岛使女高声叫道：" + ob->query("name") + "，你私入神龙岛,岛主有灵,驱逐出岛！\n");
		ob->move("/d/city/center"));
}




