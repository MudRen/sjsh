// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
// by night 24/7/2000


inherit F_VENDOR_SALE;

void create()
{
  reload("nanhai_xue_laoban");
  set_name("Ѧ�ϰ�", ({"xue laoban", "xue", "laopan"}));
  set("shop_id", ({"laoban", "xue"}));
  set("gender", "����");
  set("combat_exp", 2000);
  set("age", 40);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "skirt": "/d/nanhai/obj/ziskirt",
        "doupeng": "/d/nanhai/obj/doupeng",
        "guazi": "/d/nanhai/obj/guazi",
        "scarf": "/d/nanhai/obj/scarf",
        "ao": "/d/nanhai/obj/kenao",
      ]) );

  setup();
  carry_object("/d/nanhai/obj/guazi")->wear();
  carry_object("/d/nanhai/obj/scarf")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

