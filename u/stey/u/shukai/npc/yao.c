inherit NPC;

void create()
{
    set_name("��", ({"yao"}));
    set("title", "����");
    set("gender", "����");
    set("age", 35);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);
    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("yaofa", 301 );
    set_skill("huntian-qigong", 301 );
    set_skill("dao", 301 );
    set_skill("pingtian-dafa", 301 );
    set_skill("dengxian-dafa", 301 );
    set_skill("ningxie-force", 301 );
    set_skill("huomoforce", 301 );
    set_skill("blade", 301 );
    set_skill("sword", 301 );
    set_skill("parry", 301 );
    set_skill("spear", 301 );
    set_skill("stick", 301 );
    set_skill("fork", 301 );
    set_skill("spells", 321);
    set_skill("force", 301);
    set_skill("dodge", 301);
    set_skill("unarmed", 301);
      map_skill("force", "ningxie-force");
      map_skill("spells", "dengxian-dafa");

  setup();
    carry_object("/u/shukai/weapon/cc")->wear();
    carry_object("/u/shukai/weapon/cloth")->wear();
    carry_object("/u/shukai/weapon/jia")->wear();
    carry_object("/u/shukai/weapon/pifeng")->wear();
    carry_object("/u/shukai/weapon/shoes")->wear();
    carry_object("/u/shukai/weapon/sword")->wield();
}

int accept_fight(object me)
{
        write("......\n");
        return 0;
}

int recognize_apprentice(object me)
{
       if(me->query("yao-learn"));
        return 1;
       return notify_fail("���̲��̣�\n");
}

int accept_object(object who, object ob)
{
        object me=this_object();

        if (ob->query("name")=="�����ͷ­"){
        if ((string)who->query("family/family_name")=="�ݿ�ɽ�޵׶�"
         || (string)who->query("family/family_name")=="��ѩɽ"
         || (string)who->query("family/family_name")=="���ƶ�"
         || (string)who->query("family/family_name")=="��˿��"
) {
             who->set("yao-learn", 1);
             write("�úã�\n");
//           call_out("destroy", 1, ob);
             return 1;
         } else { 
             command("say лл\n");
//           call_out("destroy", 1, ob);
             return 1;
               }
        }
}
