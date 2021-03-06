inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_mieyao(object me);
string ask_cancel();
string expell_me(object me);


void create()
{
       set_name(HIY"神谷熏"NOR, ({"master xun", "xun","master"}));
       set("long",
"在父亲死后，年纪轻轻的她就挑起了整个神谷道场的重任。在
她的眼中，有着和她年龄不相称坚强和毅力。\n");
       set("title", HIC"神谷道场馆主"NOR);
       set("gender", "女性");
       set("age", 18);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1500);
       set("max_sen", 1500);
       set("force", 1500);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1500000);
       set("daoxing", 1500000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("sword", 150);
       set_skill("spells", 150);
   set_skill("renshu", 150);
   set_skill("guixi-force", 150);
   set_skill("huoxin-sword", 200);
   set_skill("fengyu-piaoxiang", 150);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "huoxin-sword");
   map_skill("parry", "huoxin-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("剑客联盟", 2, "弟子");
setup();
set("inquiry", ([

"leave": (: expell_me :),
           "斩恶": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
]) );


        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="剑客联盟") {
   if (((int)ob->query_skill("huoxin-sword",1) < 60 )) {
   command("say " + RANK_D->query_respect(ob) +
"还是先在弥彦那里打好基础再来。\n");
   return;
   }

 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"你不适合在我的门下学习。\n");
   return;
   }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们神谷道场发扬光大。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "神谷道场弟子");
	   ob->set("class", "swordman");
   return;
   }
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("哎，我也不怪你，以后你可得努力哦！");
}
else
{
     return ("你有任务吗？！");
}
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="剑客联盟") {
    tell_room(environment(me),"阿薰说道.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("本姑娘不知道你在说些什么。");
}
string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="剑客联盟") {
                message_vision("阿薰叹了口气，但依然顽皮的对你眨了眨眼睛。\n", me);
                me->set_temp("betray", 1);
                message_vision("阿薰对$N嘟噜着：小家伙，你说话是真心话(true)？\n", me);
                return ("好吧，你可不要后悔哦！\n");
        }
        return ("问什么问！自己想去！\n");
}
void init()
{
        add_action("do_true", "true");
  ::init();
}

int do_true(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N答道：弟子讲的真心话！\n\n", this_player());
                message_vision("阿薰叹道，既然如此，你便去吧！\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->add("betray/count", 1);
                this_player()->add("betray/hell", 1);
                this_player()->delete("family");
                this_player()->delete_skill("renshu");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("阿薰突然向天空一指，$N便消失得无影无踪。。。\n", this_player());
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"房梁上噗噗嗦嗦几声响，掉下个人来！\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}