
 inherit F_VENDOR_SALE;


void create()
{
         reload("xiaoer");
         set_name("���»�", ({"liu de hua","liu","andy"}));
       set("shop_id",({"waiter","xiaoer","xiao","er"}));
           set("title","������");
       set("gender", "����");
        set("combat_exp", 1000);
         set("age", 62);
         set("per", 40);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
                       "xo": "/u/yudian/xo",
        ]) );

  //      if( clonep() ) CHANNEL_D->register_relay_channel("rumor");
       setup();

       carry_object("/d/obj/cloth/linen")->wear();
       add_money("silver", 1);
        remove_call_out("clear_room");
        call_out("clear_room",300);
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
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                            say( name()+"�����Ϲ���˵����ӭ����!\n");
                        break;
        }
}

