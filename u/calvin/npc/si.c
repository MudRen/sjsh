// �������� calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��������", ({"si tianshen", "si", "sichong", "tianshen"}));
        set("title", "�칬����");
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","��������������ػ�����,�������������,�ֳ�һ�Ѵ�,����òɷ������!\n");

        set("attitude", "aggressive");
  set("combat_exp", 4000000);
        set("daoxing", 4000000);
  set("int", 30+random(5));
  set("cor", 30+random(10));
  set_skill("unarmed", 220);
  set_skill("dodge", 220);
  set_skill("parry", 220);
  set_skill("spells", 300); 
  set_skill("yaofa", 300);
  set_skill("sword",220);
  set_skill("qixiu-jian",220);
  set_skill("blade", 220);
  set_skill("kugu-blade", 220);
  set_skill("lingfu-steps", 220);
  set_skill("yinfeng-zhua", 220);
  set_skill("force", 220);   
  set_skill("huntian-qigong", 220);
  map_skill("force", "huntian-qigong");
  map_skill("spells", "yaofa");
  map_skill("unarmed", "yinfeng-zhua");
  map_skill("sword", "qixiu-jian");
  map_skill("parry", "kugu-blade");
  map_skill("blade", "kugu-blade");
  map_skill("dodge", "lingfu-steps");

  set("per", 50);
  set("max_kee", 3000);
  set("max_sen", 3000);
  set("force", 4000);
  set("max_force", 4000);
  set("force_factor", 220);
  set("mana",4000);
  set("max_mana", 4000);
  set("mana_factor", 200);

  set("chat_chance_combat", 60);

   set("chat_msg_combat", ({
     (: exert_function, "zhangqi" :),
//             (: cast_spell, "suliao" :),
//                (: cast_spell, "huanying" :),
                (: cast_spell, "bite" :),
//    (: perform_action, "blade.diyu" :),
//    (: perform_action, "blade.pozhan" :),
//    (: perform_action, "blade.sword" :),
   }) );
  setup();
  carry_object("/d/obj/weapon/blade/yanblade")->wield();
  carry_object("/d/calvin/armor/tianjia")->wear();
}
void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fight");
add_action("do_error", "fly");
add_action("do_error", "perform");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}
