// by happ@YSZZ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"


void create()
{
        set_name("�����", ({ "shouhuzhe", "shouhu zhe", "zhe" }) );
        set("gender", "����" );
	set("long",
		"�ػ��ڰ�������ػ���----��ڤ��˾�����\n"
	);
  set("str", 20);
  set("per", 130);
 set("age", 86);
  set("cor", 30);
  set("family/family_name","���޵ظ�");

  set("cps", 75);
  set("kar", 100);
  set("int", 40);
  set("con", 40);
  set("spi", 40);
  set("title", "�ػ���");
  set("combat_exp", 4600000);
  set("daoxing", 4600000);
  set("max_sen", 6000);
  set("max_kee", 6000);
  set("force", 6000); 
  set("max_force", 6000);
  set("force_factor", 40);
  set("max_mana", 6000);
  set("mana", 6000);
  set("mana_factor", 50);
	
     set_skill("unarmed", 350);
    set_skill("whip", 350);
    set_skill("hellfire-whip", 350);
    set_skill("dodge", 350);
     set_skill("parry", 350);
   set_skill("literate", 350);
   set_skill("spells", 200);
  set_skill("force", 350);
  set_skill("tonsillit", 350);
  set_skill("ghost-steps", 350);
     set_skill("gouhunshu", 350);
   set_skill("jinghun-zhang", 350);
  set_skill("kusang-bang", 350);
   set_skill("zhuihun-sword", 350);
   set_skill("sword", 350);
   set_skill("stick", 350);

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
        }) );

	setup();
   carry_object("/d/obj/weapon/whip/longsuo")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}


void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","exert");

        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("������磬������������\n",me);
        return 1;
} 

void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("9sky/qi")=="done") && (ob&&ob->query("9sky/ba")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"�������졿�켫(Tian ji):"+ob->name()+
        "�����˰��ء���Ӱ��\n"NOR,users());
        ob->set("9sky/ba","done");
        ob->add("9sky/number",1);
         ob->add("daoxing", 70000);
           ob->save();
         tell_object(ob,"��Ӯ���˰�ʮ�����");

        }
       ::die();
}


