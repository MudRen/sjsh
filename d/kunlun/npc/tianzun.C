//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("Ԫʼ����", ({"yuanshi tianzun","tianzun"}));
       set("long","�����������ˡ�\n");
        set("title",HIW"����"NOR);
       set("gender", "����");
       set("age", 200);
       set("class", "kunlun");
       set("attitude", "friendly");
       set("rank_info/respect", "ʥ��");
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
       set("combat_exp", 5800000);
       set("daoxing", 5800000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 200);
       set_skill("literate", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("wugou-jian", 220);
       set_skill("sword", 200);
       set_skill("mace", 200);
       set_skill("spells", 200);
       set_skill("xuanzong-force", 220);
       set_skill("huntian-jian", 220);
       set_skill("lingyunbu", 220);
       set_skill("yuxu-spells", 220);
       set_skill("kaitian-zhang", 220);
       set_skill("dashen-bian", 220);
       map_skill("sword", "huntian-jian");
       map_skill("mace", "dashen-bian");
       map_skill("parry", "wugou-jian");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("dodge", "lingyunbu");
       map_skill("force", "xuanzong-force");
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "jinding-zhang");
       create_family("����ɽ���鶴", 1, "��ʦ");

setup();

           carry_object("/obj/cloth")->wear();
           carry_object("/d/obj/weapon/sword/changjian")->wield();
        
}

void attempt_apprentice(object ob,object me)
   {
              if (me->query_skill("yuxu-spells")  < 160 ) 
       tell_object("��������ɷ�����������ذɡ�\n");
              else {
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������������ɷ�����\n");
        command("recruit " + ob->query("id") );
        ob->set("title", HIG"��������"NOR);
        ob->set("class","kunlun" );
}

   return;
}

