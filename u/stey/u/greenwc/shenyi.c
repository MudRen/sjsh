// teller.c
//cglaem...12/16/96.

inherit NPC;


void create()
{
            set_name("小掌柜", ({"zhang gui","boss"}));
        set("gender", "男性" );
         set("age", 80);
           set("age", 30);
          set("long", "长安城里有名的神医，他的大补丸有神奇的功效。\n");
            set("long", "这里的一种饮料有神奇的功效，听说要2两黄金呢！\n");
        set("daoxing", 80000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 350);
        set("max_gin", 300);
        set("max_sen", 300);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
}


int accept_object(object me, object ob)
{
          object cola;

                if( (string)ob->query("name")=="桂花酒袋" )
        {
        command("say 这位" + RANK_D->query_respect(me) + "这听饮料(cola)请笑纳，快喝(drink)吧！\n");
                  carry_object("/u/yudian/cola");
                 command("give cola to " + me->query("id"));
       		return 1;
        }
}
