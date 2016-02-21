// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
//master.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��ʥ��ʦ������", ({"guoshiwang pusa","pusa", "guoshiwang"}));
       set("long", "�������ˣ�����ѧ��һ����ʦ����Ŀ����Ȼ��¶��һ����ɱ֮����\n");
       set("title", "�ն�����");
       set("gender", "����");
       set("age", 90);
   set("class", "hero");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ʥ��ʦ��");
       set("per", 26);
   set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 1000);
       set("max_sen", 5000);
       set("force", 5000);
       set("max_force", 2500);
       set("force_factor", 150);
       set("max_mana", 2500);
       set("mana", 5000);
       set("mana_factor", 150);
       set("combat_exp", 2000000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 180);
       set_skill("parry", 200);
   set_skill("halberd", 150);
   set_skill("spells", 170);
     set_skill("buddhism", 180);
   set_skill("lianhuan-tui", 150);
   set_skill("lotusforce", 180);
   set_skill("force", 170);
   set_skill("hammer", 150);
   set_skill("pangu-hammer", 150);
   set_skill("tianlong-halberd", 200);
   set_skill("tianwei-shi", 180);
     map_skill("spells", "buddhism");
   map_skill("unarmed", "lianhuan-tui");
   map_skill("hammer", "pangu-hammer");
   map_skill("force", "lotusforce");
   map_skill("halberd", "tianlong-halberd");
   map_skill("parry", "tianlong-halberd");
   map_skill("dodge", "tianwei-shi");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
//      (: cast_spell, "freeze" :),
     (: cast_spell, "wanlei" :),
     (: cast_spell, "sword" :)
        }) );

              create_family("�Ϻ�����ɽ", 1, "����"); 
setup();

        carry_object("/d/obj/cloth/xianpao")->wear();
        carry_object("/d/xuyi/obj/shield")->wear();
        carry_object("/d/xuyi/obj/tianlong")->wield();
}

void attempt_apprentice(object ob)
{   ob=this_player();
       if( (string)ob->query("family/family_name")=="�Ϻ�����ɽ") {
   if ((int)ob->query("combat_exp") < 250000 ) {
     command("say ƾ����ô����У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
   return;
   }

   if( (int)ob->query_skill("buddhism", 1) < 110 ) {
   command("say ��λ" + RANK_D->query_respect(ob) + "�������ţ���Ҫ��һ���ķ�����������Ĵ�˷�̫�ͣ����ܴ����²���\n");
   command("sigh");
   return;
   }
        command("smile");
        command("say �ܺã���λ" + RANK_D->query_respect(ob) + "�������£��Ӵ������ֶ���һ���ȱ���ʿ��");
        command("recruit " + ob->query("id") );
     ob->set("mark/xuyi_pusa",1);
   return;
   }
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "hero");
}

int accept_fight(object me, object ob)
{   ob=this_player();
   command("say " + RANK_D->query_rude(ob) + "��������Թ��ʱ�ˣ��α�Ҫ���ɱɱ�أ�\n");
   return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n��ʥ��ʦ������̾����������������ǰ�ˣ��Ժ�������������˵������ˣ���\n\n", environment());
        command("sigh");
        message("sound", "\n��ʥ��ʦ����������һ�Σ�ƮȻ��ȥ����\n\n", environment());
        }

        destruct(this_object());
}


