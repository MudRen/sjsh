//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("长空无忌", ({"changkong wuji", "wuji","changkong"}));
       set("long","峨嵋山第三代弟子中最杰出的人物之一, 雷炎剑的传人。\n");
       set("title", HIG"峨嵋派雷炎剑传人"NOR);
       set("gender", "男性");
       set("age", 25);
       set("class", "xian");
       set("attitude", "friendly");
       set("per", 50);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("sen", 3000);
       set("kee", 3000);
       set("max_gin", 600);
       set("max_force", 2000);
       set("max_mana", 2000);
       set("mana", 2000);
       set("force", 2000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 4000000);
       set("daoxing", 3000000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 180);
       set_skill("literate", 180);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("spells", 180);
       set_skill("leiyan-sword", 180);
       set_skill("emeiforce", 180);
       set_skill("zhutian-bu", 180);
       set_skill("mahayana", 180);
       set_skill("jinding-zhang", 180);
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("sword", "leiyan-sword");
       map_skill("parry", "leiyan-sword");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       create_family("峨嵋派", 3, "弟子");
 
 setup();
        carry_object("/d/lingtai/obj/heao")->wear();
        carry_object("/d/emei/obj/leiyan")->wield();
        
}

void attempt_apprentice(object ob)
{

        if( (string)ob->query("gender") != "男性" )
	 {
		command ("say 你是女性之身无法学习雷炎剑，还是去找李英奇学习天玑剑吧。");
		return;
        }
       
              if (((int)ob->query("combat_exp") < 500000 )) 
        { 
             command("say " + RANK_D->query_respect(ob) + "的武学修为不够高深，有些绝学秘法恐怕难以领悟。\n"); 
              return;
        }

        if(((int)ob->query_skill("huifeng-sword",1) > 1))
        {
              command("say 这位" + RANK_D->query_respect(ob) + "，你还是先放弃所学的剑法，才能拜我为师。");
              return;
        }


	 command("say 好，希望" + RANK_D->query_respect(ob) + "多加努力，把我们峨嵋发扬光大。\n");
        command("recruit " + ob->query("id"));
        ob->set("title", HIG"峨嵋派雷炎剑传人"NOR);
}

