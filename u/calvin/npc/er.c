// �������� calvin,2001.5

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIC"����"NOR, ({"ruo lan", "ruo", "lan","er", "tianshen"}));
        set("title", HIW"¥������"NOR);
        set("gender", "Ů��" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","����Ƕ��������ػ�����,�����ϴ���������ָ,�ֳ�һ������,����òɷ������!\n");

        set("attitude", "aggressive");
  set("class", "youling");
  set("shen_type", 1);
  set("int", 30+random(5));
  set("nkgain",790);
  set("max_kee", 3000);
  set("max_gin", 2500);
  set("max_sen", 2000);
  set("force", 3500);
  set("max_force", 2000);
  set("force_factor", 200);
  set("max_mana", 2500);
  set("mana", 2000);
  set("mana_factor", 200);

  set("combat_exp", 2000000);
        set("daoxing", 3200000);

   set_skill("unarmed", 180);
  set_skill("whip", 180);
  set_skill("hellfire-whip", 180);
  set_skill("dodge", 180);
   set_skill("parry", 180);
   set_skill("literate", 180);
   set_skill("spells", 300);
  set_skill("force", 180);
  set_skill("tonsillit", 180);
  set_skill("ghost-steps", 180);
     set_skill("gouhunshu", 300);
   set_skill("jinghun-zhang", 180);
  set_skill("kusang-bang", 180);
   set_skill("zhuihun-sword", 180);
   set_skill("sword", 180);
   set_skill("stick", 180);

  map_skill("force", "tonsillit");
  map_skill("unarmed", "jinghun-zhang");
  map_skill("dodge", "ghost-steps");
  map_skill("spells", "gouhunshu");
  map_skill("parry", "hellfire-whip");
  map_skill("whip", "hellfire-whip");
   map_skill("sword", "zhuihun-sword");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip.three" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :),
                (: cast_spell, "inferno" :),
        }) );
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

  create_family("���޵ظ�", 1, "�й�");
  setup();

carry_object("/d/calvin/armor/jiezhi")->wear();
 carry_object("/d/obj/weapon/whip/snakewhip")->wield();
}
void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "perform");
add_action("do_error", "fight");
add_action("do_error", "fly");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}
