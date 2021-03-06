//Cracked by Roath
//【蜀山剑派】koker 2001.3.10
inherit NPC;

void create()
{
        set_name("明月", ({ "ming yue", "yue" }));
        set("long", 
"明月是蜀山剑派年轻一代的顶尖人才。\n");
        set("gender", "女性");
        set("age", 26);
        set("attitude", "peaceful");
        set("str", 25);
        set("int", 23);
        set("con", 24);
        set("cor", 22);
        set("class","swordsman");
        
        set("max_kee", 1500);
        set("max_sen", 1500);
        set("force", 3000);
        set("max_force", 1500);
        set("force_factor", 60);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 60);
        set("combat_exp", 500000);
        set("daoxing", 700000);

        set_skill("force", 100);
        set_skill("zixia-shengong", 100);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("taoism", 110);
        set_skill("unarmed", 100);
        set_skill("whip", 180);
        set_skill("spells", 110);
        set_skill("sevensteps", 110);
        set_skill("hunyuan-zhang", 100);
        set_skill("yujianshu", 120);
        set_skill("yirubian", 180);
        set_skill("literate", 100);

        map_skill("force", "zixia-shengong");
        map_skill("dodge", "sevensteps");
        map_skill("spells", "taoism");
        map_skill("unarmed", "hunyuan-zhang");

        create_family("蜀山剑派", 6, "弟子");
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
        }) );
   add_temp("apply/damage", 15);
   add_temp("apply/armor", 15);

        setup();
        carry_object("/d/obj/cloth/daopao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
        if (ob->query("family/family_name") == "蜀山剑派" && ob->query("family/generation") < 7){
                command("say " + RANK_D->query_respect(ob) + "不要开玩笑。");
                return; 
        }
        if ((int)ob->query_cor() < 15) {
                command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不合？");
                return;
        }
        if ((string)ob->query("race") == "异型" || (string)ob->query("race") == "妖精") {
                command("say 阁下开什么玩笑！我怎么能够收妖魔之徒为徒呢？");
                return;
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "swordsman")
                ob->set("class", "swordsman");
}
