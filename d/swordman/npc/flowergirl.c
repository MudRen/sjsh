// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_dai_jie");
  set_name("������Ů", ({"shao nu", "girl"}));
  set("shop_id", ({"shaonu", "girl"}));
  set("gender", "Ů��");
  set("combat_exp", 2000);
  set("age", 20);
  set("per", 40);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
"guihua":"/d/swordman/obj/guihua",
              "rose":"/d/swordman/obj/rose",
               "sakura":"/d/swordman/obj/sakura",

"baimei":"/d/swordman/obj/baimei",
"changpu":"/d/swordman/obj/changpu",

      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/pixie")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

