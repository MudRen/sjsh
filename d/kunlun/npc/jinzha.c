// jinzha.c by piao
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("��߸", ({"jin zha","zha","jin"}));
        set("long","��Ĵ���ӣ����鹬����ȼ�Ƶĵ��ӡ�\n");
       set("title", HIG"����ɽ���鶴����������"NOR);
       set("gender", "����");
       set("age", 27);
       set("class", "kunlun");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("sen", 1000);
       set("kee", 1000);
       set("max_gin", 1000);
       set("max_force", 1000);
       set("max_mana", 1000);
       set("mana", 1000);
       set("force", 1000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 800000);
       set("daoxing", 1200000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 120);
       set_skill("literate", 120);
       set_skill("dodge", 120);
       set_skill("force", 120);
       set_skill("parry", 120);
       set_skill("sword", 120);
       set_skill("spells", 120);
       set_skill("xuanzong-force", 120);
       set_skill("wugou-jian", 120);
       set_skill("lingyunbu", 120);
       set_skill("yuxu-spells", 120);
       set_skill("kaitian-zhang", 120);
       map_skill("sword", "wugou-jian");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("dodge", "lingyunbu");
       map_skill("force", "xuanzong-force");
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "jinding-zhang");
       create_family("����ɽ���鶴", 3, "����");

setup();

           carry_object("/d/obj/cloth/linen")->wear();
           carry_object("/d/obj/weapon/sword/qinghong")->wield();
        
}

void attempt_apprentice(object ob)

   {
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������������ɷ�����\n");
        command("recruit " + ob->query("id") );
        ob->set("title", HIG"����ɽ���鶴���ŵ���"NOR);
        ob->set("class","kunlun" );


   return;
}


