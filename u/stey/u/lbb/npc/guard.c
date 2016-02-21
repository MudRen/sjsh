inherit NPC;

void create()
{
  set_name("ֵ���ڱ�", ({"guard", "bing"}));
  set("gender", "����");
  set("combat_exp", 2000000);
  set("age",23);
  set("per", 40);
  set("attitude", "friendly");
  set("shen_type", 1);
  set("people", "people");
  set("force_factor",60);
  set("max_gin",6000);
  set("max_kee",600);
  set("max_sen",600);
  set("max_force",4000);
  set("max_mana",4000);
  set_skill("unarmed", 400);
  set_skill("dodge", 400);
  set_skill("parry", 400);
  set_skill("force", 400);
  set_skill("spells", 400);
  setup();
  carry_object("/u/lbb/obj/junfu")->wear();
  carry_object("/u/lbb/obj/weichong")->wield();
  set("no_nk_reward",1);
}

void init ()
{
  object ob = this_player();
  object me = this_object();

  if(living(ob))
  call_out("greeting", 1, ob);
}

void greeting(object ob)
{
  if( !ob || environment(ob) != environment() ) return;
  if (ob && interactive(ob))
  {
    if (! ob->query_temp("weishi_kill"))
      message_vision ("$Nһ�����ȣ�ι��Ҳ����������ƣ����Ϻ�����ԺҲ���Ҵ���\n",this_object());
    this_object()->kill_ob(ob);
    ob->set_temp("weishi_kill",1);
  }
}
