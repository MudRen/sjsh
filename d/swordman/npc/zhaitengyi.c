inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIY"ի��һ"NOR, ({"master zhaiteng", "zhaiteng","master","yi"}));
       set("long",
"��������׫�������Ӷӳ���Ļĩ��Ͷ��ά�������������еĽ���
��������Ŷ񡤼���ն�����\n");
       set("title", HIC"������"NOR);
       set("gender", "����");
       set("age", 35);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);

       set_skill("literate", 200);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 240);
       set_skill("spells", 200);
   set_skill("renshu", 200);
   set_skill("guixi-force", 200);
   set_skill("lixin-sword", 240);
   set_skill("fengyu-piaoxiang", 200);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "lixin-sword");
   map_skill("parry", "lixin-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("��������", 2, "����");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
 if ( (string)ob->query("family/family_name")=="��������") {
 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"�㲻�ʺ����ҵ�����ѧϰ��\n");
   return;
   }

 if (((int)ob->query("combat_exp") < 800000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�����ȴ�û���������\n");
   return;
   }
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����Ѷ񡤼���ն����������ȥ��\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "���;���");
	   ob->set("class", "swordman");
   return;
   }
}