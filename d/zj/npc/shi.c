// ��� ��� by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIG"���"NOR, ({"tian chi", "tian", "chi","tianshen"}));
       set("title", HIW"���ͯ��"NOR);
       set("gender", "Ů��");
       set("age", 3000);
       set("int", 25+random(5));
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("daoxing", 10000000);
       set("rank_info/respect", "���ͯ��");
       set("per", 30);
set("max_kee", 5000);
set("max_sen", 5000);
       set("force", 6000);
       set("max_force", 6000);
       set("force_factor", 1000);
       set("max_mana", 6000);
       set("mana", 6000);
       set("mana_factor", 1000);

       set_skill("literate", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
       set_skill("fork", 1000);
       set_skill("spells", 1000);
       set_skill("seashentong", 1000);
       set_skill("dragonfight", 1000);
       set_skill("dragonforce", 1000);
       set_skill("fengbo-cha", 1000);
       set_skill("dragonstep", 1000);

       set_skill("dengxian-dafa", 1000);
       set_skill("gouhunshu", 1000);
       set_skill("whip", 1000);
         set_skill("bawang-qiang", 1000);
         set_skill("axe", 1000);
         set_skill("sanban-axe", 1000);
        set_skill("bawang-qiang", 1000);
        set_skill("baguazhou", 1000);
        set_skill("yanxing-steps", 1000);

  map_skill("spells", "gouhunshu");
  map_skill("axe", "sanban-axe");
  map_skill("parry", "sanban-axe");
  map_skill("dodge", "yanxing-steps");
  map_skill("spear", "bawang-qiang");
  map_skill("whip", "bawang-qiang");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("unarmed", "dragonfight");
       set("chat_chance_combat", 100);
       set("chat_msg_combat", ({
//             (: cast_spell, "hufa" :),
                (: perform_action, "fork", "fengbo" :),
                (: cast_spell, "gouhun" :),
                (: perform_action, "axe.kai" :),
                (: exert_function, "jingxin" :),
                (: perform_action, "spear.lei" :),
        }) );
  set_temp("apply/armor", 100);
  set_temp("apply/dodge", 100);
  setup();

//        carry_object("/d/milin/obj/bsd");
//  carry_object("/d/obj/baowu/shuizhu")->wear();
//  carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}
