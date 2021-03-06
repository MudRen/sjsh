inherit NPC;
inherit F_MASTER;
int ask_yanling();
int ask_miyan();
#include <ansi.h>

void create()
{
	set_name(WHT"志志雄真实"NOR, ({ "master zhizhixiong", "master", "zhizhixiong","zhenshi" }) );
       set("title", "");
	set("gender", "男性" );
	set("age", 30);
	set("long", "曾继承了剑心千人斩的地位，却因野心太大而被维新政府追杀。从昔
日同志手中逃出生天的志志雄，怀着对维新政府的强烈恨意以及对权利
的极度渴望组织了十本刃，以建立一个强者统治的国度而进行推翻维新
政府的恐怖活动。\n");
       set("class", "swordman");
       set("spi", 40);
       set("str", 40);
       set("con", 40);
       set("kar", 40);
       set("per", 25);
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 5000);
       set("max_sen", 5000);
       set("force", 8000);
       set("max_force", 5000);
       set("force_factor", 300);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 300);
       set("combat_exp", 5000000);
           set("daoxing", 5000000);
        create_family("剑客联盟", 1, "弟子");
        set("inquiry", ([
                 "焰灵" : (: ask_yanling :),
                 "密剑·焰灵" : (: ask_yanling :),
                 "最强剑客":(:ask_miyan :),
         ]) );

        set_skill("unarmed", 320);
        set_skill("dodge", 320);
        set_skill("parry", 320);
        set_skill("spells", 320);  
        set_skill("renshu", 320);
        set_skill("literate", 320);
        set_skill("sword", 360);  
        set_skill("doom-sword", 360); 
        set_skill("fengyu-piaoxiang", 320);
        set_skill("dodge", 320);  
        set_skill("force", 320);   
        set_skill("guixi-force", 320);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("dodge", "fengyu-piaoxiang");

        setup();
	 carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
//        if ( (int)ob->query("kill/pkgain") <100000){
//	  command("shake");
//	command("say 没见识过杀戮地狱的人，不适合学习我的杀人剑术。\n");
//	return;}

        if ( (int)ob->query("MKS") <3000){
	  command("shake");
	command("say 没见识过杀戮地狱的人，不适合学习我的杀人剑术。\n");
	return;}

        if ( (int)ob->query("combat_exp") <1500000){
	command("shake");
	command("say 你的修为不够，不适合学习我的杀人剑术。\n");
	return;}

        command("sneer ");
        command("say 我会带你见识地狱的真正模样。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	       ob->set("title", WHT"十本刃剑客"NOR);
              ob->set("class", "swordman");
              ob->set("swordman/zhizhixiong",1);
}

int ask_yanling()
{

    object ob=this_player();
    if(ob->query("family/master_id") != "master zhizhixiong")
    {
    command("say 密剑·焰灵不是你学得会的武功。");
    return 1;
    }
    if(ob->query("swordman/yanling_perform"))
    { 
    command("say 你不是问过了吗? ");
    return 1;
    }
    if(ob->query("family/master_id") == "master zhizhixiong")
    {
    command("say 以高速摩擦产生的热量，将附近空气燃烧起来，这就是焰灵的秘密！");
    ob->set("swordman/yanling_perform",1);
    return 1;
    }
}

int ask_miyan()
{
       object ob=this_player();
       if(ob->query("family/master_id") != "master zhizhixiong")
       {
	command("say 没见识过杀戮地狱的人，怎么能够成为最强的剑客。\n");
       return 1;
       }

           else
           {command("nod");
            command("say 以前有个叫明神弥彦的人也问过同样的问题。我告诉他
如果放弃一切的感情，将整个生命奉献给剑，是有可能成为最强的剑客。\n");
           command("say 我便带你去见见他。");
           ob->move("/d/swordman/anshi");
           return 1;
           }
}
