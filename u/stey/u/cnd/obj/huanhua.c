
inherit NPC;
void create()
{
	set_name("����ʹŮ", ({"guard" }));
	set("gender", "Ů��" );
	set("age", 16);
	set("long", "������Ů���ӡ�\n");
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
                command("chat* ֻ��������ʹŮ�����е���" + ob->query("name") + "����˽��������,��������,���������\n");
		ob->move("/d/city/center"));
}




