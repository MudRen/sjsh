//xiaojie.c

inherit F_VENDOR_SALE;
// inherit NPC;
void create()
{
        

	set_name("����", ({"boss yuzhen", "boss", "yuzhen"}));
	set("gender", "Ů��" );
	set("age", 22);
        set("title", "С�ɰ�");
	set("long", "һ���ɰ���С������˶����۰�֮�ġ�\n");
	set("combat_exp", 26000);
	set("attitude", "peaceful");
	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);

	set("per", 40);
	set("max_kee", 350);

        set("vendor_goods", ([
                "spear":  "/u/wen/obj/weapon/shoumoqiang",
                "sword": "/u/wen/obj/weapon/yitianjian",
                "blade": "/u/wen/obj/weapon/duopodao",
                "staff": "/u/wen/obj/weapon/guanyin",
				"hammer": "/u/wen/obj/weapon/manglong",
				"fork":  "/u/wen/obj/weapon/xumicha",
				"stick":  "/u/wen/obj/weapon/shehunbang",
				"jujue": "/u/wen/obj/weapon/jujue",

        ]) );


	setup();
	carry_object("/d/obj/cloth/sunglass")->wear();
       add_money("coin", 100);

        
}

void init()
{
   add_action("do_vendor_list", "list");
}


int ask_name() {
  this_object()->command("shutup boss yuzhen");  
  return 1;
}
