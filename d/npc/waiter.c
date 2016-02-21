// waiter.c

inherit F_VENDOR_SALE;
void create()
{
        set_name("��С��", ({ "waiter", "xiao", "xiao er"}) );
        set("gender", "����" );
        set("age", 22);
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("per",25);
        set("vendor_goods", ([
		"jiudai": "/d/moon/obj/jiudai",
		"gourou": "/d/ourhome/obj/gourou",
 		"jitui": "/d/ourhome/obj/jitui",
		"huasheng": "/d/ourhome/obj/huasheng",
	]));
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
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("��С��˵������λ" + RANK_D->query_respect(ob)
		+"����������������ϼ�����\n");
}
int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 200) 
        {
                tell_object(who, "��С��һ������˵������л���ϣ�������롣\n
");
                who->set_temp("rent_paid",1);
                return 1;
        }
        return 0;
}
