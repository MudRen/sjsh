inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string ask_mieyao(object me);
string ask_cancel();
string expell_me(object me);


void create()
{
       set_name(HIY"���Ѭ"NOR, ({"master xun", "xun","master"}));
       set("long",
"�ڸ�������������������������������ȵ��������Ρ���
�������У����ź������䲻��Ƽ�ǿ��������\n");
       set("title", HIC"��ȵ�������"NOR);
       set("gender", "Ů��");
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

create_family("��������", 2, "����");
setup();
set("inquiry", ([

"leave": (: expell_me :),
           "ն��": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
]) );


        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="��������") {
   if (((int)ob->query_skill("huoxin-sword",1) < 60 )) {
   command("say " + RANK_D->query_respect(ob) +
"�����������������û���������\n");
   return;
   }

 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"�㲻�ʺ����ҵ�����ѧϰ��\n");
   return;
   }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������ȵ���������\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "��ȵ�������");
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
     return ("������Ҳ�����㣬�Ժ���ɵ�Ŭ��Ŷ��");
}
else
{
     return ("���������𣿣�");
}
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="��������") {
    tell_room(environment(me),"��޹˵��.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
     return ("�����ﲻ֪������˵Щʲô��");
}
string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="��������") {
                message_vision("��޹̾�˿���������Ȼ��Ƥ�Ķ���գ��գ�۾���\n", me);
                me->set_temp("betray", 1);
                message_vision("��޹��$N����ţ�С�һ��˵�������Ļ�(true)��\n", me);
                return ("�ðɣ���ɲ�Ҫ���Ŷ��\n");
        }
        return ("��ʲô�ʣ��Լ���ȥ��\n");
}
void init()
{
        add_action("do_true", "true");
  ::init();
}

int do_true(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N��������ӽ������Ļ���\n\n", this_player());
                message_vision("��޹̾������Ȼ��ˣ����ȥ�ɣ�\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->add("betray/count", 1);
                this_player()->add("betray/hell", 1);
                this_player()->delete("family");
                this_player()->delete_skill("renshu");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("��޹ͻȻ�����һָ��$N����ʧ����Ӱ���١�����\n", this_player());
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"�������������¼����죬���¸�������\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}