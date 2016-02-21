inherit F_VENDOR_SALE;

void create()
{
    reload("boss");
        set_name("�������ϰ�", ({"lao ban", "boss"}));
        
        set("gender", "����");
        set("age", 50);

        set("combat_exp", 70000);
        set_skill("sword", 50);
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 5);

        set("vendor_goods", ([
                "sword": "/d/obj/weapon/sword/changjian",
                "blade": "/d/obj/weapon/blade/blade",
        ]) );

        setup();
        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting",1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {
                case 0:
                        say( name()+"���˸���,��м�Ŀ��˿���\n");
                        break;
        }
}
int accept_fight(object me)
{
        command("say �ߣ����ӵĵ�����Ҳ����Ұ��\n");
        return 1;
}


