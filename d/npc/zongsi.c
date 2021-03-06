inherit NPC;
inherit F_MASTER;
int ask_wu();
#include <ansi.h>
void create()
{
       set_name(HIY"冲田总司"NOR, ({"master zongsi", "zongsi","master","chongtian"}));
       set("long",
"幕末最强剑客联盟新撰组的最强剑客，天才的美少年，身犯肺痨，
身体非常虚弱，完全以天赋挥动着手中的剑。\n");
       set("title", HIC""NOR);
       set("gender", "男性");
       set("age", 35);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 40);
	set("int", 40);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 4000);
       set("force_factor", 200);
       set("max_mana", 4000);
       set("mana", 6000);
       set("mana_factor", 200);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);
        set("inquiry", ([
                 "无式" : (: ask_wu :),
                 "wu" : (: ask_wu :),
         ]) );

       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 300);
       set_skill("spells", 300);
   set_skill("renshu", 300);
   set_skill("guixi-force", 300);
   set_skill("lixin-sword", 300);
   set_skill("fengyu-piaoxiang", 300);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "lixin-sword");
   map_skill("parry", "lixin-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("剑客联盟", 1, "弟子");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"你不适合在我的门下学习。\n");
   return;
   }

         if ( (int)ob->query("combat_exp") <1000000){
           command("shake");
 command("say " + RANK_D->query_respect(ob) +
"还是先打好基础再来。\n");
 return;}
        if ( (int)ob->query("int") <25){
	  command("shake");
	command("say 以在下看这位" +
RANK_D->query_respect(ob) + "的天赋并不适合在我门下学习剑术，还是另请高就吧。\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;}

        if ( (int)ob->query("per") <25){
	  command("shake");
	command("say 以在下看这位" +
RANK_D->query_respect(ob) + "的天赋并不适合在我门下学习剑术，还是另请高就吧。\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;
   }
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把新撰组的信念继续坚持下去。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "剑客警官");
	   ob->set("class", "swordman");
   return;
   }
int ask_wu()
{

    object ob=this_player();
    if(ob->query("family/master_name") != HIY"冲田总司"NOR)
    {
    command("say 你不是在下弟子，恕在下不能将牙突·无式的秘密告诉你。");
    return 1;
    }
    if(ob->query("combat_exp") < 1500000 ) 
    {
    command("say 你的修为不够，无法领会到牙突·无式的秘密。");
    return 1;
    }
    if(ob->query("swordman/wu_perform"))
    { 
    command("say 你不是问过了吗? ");
    return 1;
    }
    if(ob->query("family/master_name") == HIY"冲田总司"NOR)
    {
    command("say 以无招胜有招，这就是牙突·无式的秘密！");
    ob->set("swordman/wu_perform",1);
    return 1;
    }
}
