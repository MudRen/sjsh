//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
// int accept_object(object me, object ob);
void create()
{
       set_name(HIR"��������"NOR, ({"dongfang bubai", "dongfang", "bubai","master"}));
       set("long",
"�������书���µ�һ��������̽�����\n");
       set("title", HIR"��"HIC"��"HIW"��̽���"NOR);
       set("gender", "����");
       set("age", 20);
       set("class", "swordsman");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("per", 40);
       set("int", 30);
       set("max_kee", 10000);
       set("max_sen", 10000);
       set("force", 100000);
       set("max_force", 100000);
       set("force_factor", 1000);
       set("max_mana", 20000);
       set("mana", 20000);
       set("mana_factor", 1000);
       set("combat_exp", 50000000);
       set("daoxing", 50000000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("force", 500);
       set_skill("parry", 500);
       set_skill("qin", 200);
       set_skill("sword", 500);
       set_skill("spells", 500);
   set_skill("buddhism", 500);
   set_skill("lanhua-shou", 500);
   set_skill("jiuyin-xinjing", 500);
   set_skill("shushan-sword", 500);
   set_skill("ghost-steps", 500);
   map_skill("spells", "buddhism");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "shushan-sword");
   map_skill("parry", "shushan-sword");
   map_skill("dodge", "ghost-steps");
   set("chat_chance",5);
   set("chat_msg", ({
        HIR"�����������쳤̾:��������,��ɽ���ң�\n"NOR,

        }));


create_family("��ɽ����", 1, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{

        if (((int)ob->query("combat_exp") < 90000000 )){
//      this_player()->set("mark/pansi_bai", 1);
        command("shake");
        command("say ƾ�������Ϊ��");
        return;}
//        if(!ob->query_temp("marks/zui")){
//        this_player()->set("mark/pansi_bai", 1);
//          command("shake");
//          command("say ������Ե����������߾Ͱɡ�\n");
//          return ;
//        }
        else{
        command("curtain");
        command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£����ձ������ɣ�\n");
        command("recruit " + ob->query("id") );
        ob->set("title", HIY"�������ֽ�ɽ����"NOR);
        ob->set("class", "swordsman");
        return ;}
}

