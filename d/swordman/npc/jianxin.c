inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
         set_name("�p�儦��"NOR, ({"master jianxin", "jianxin","master"}));
       set("long",
"Ļĩʱ�����ŷ�ɢ����ǧ��ն�ε�ի��ά�º��ʧȥ����Ӱ��ȡ
����֮�����˿ͽ��ģ�����Ų�ɱ�������������֮��������
����С֮�ˡ�\n");
         set("title", HIC"�w��R��������"NOR);
       set("gender", "����");
       set("age", 30);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("force", 8000);
       set("max_force", 4000);
       set("force_factor", 200);
       set("max_mana", 4000);
       set("mana", 8000);
       set("mana_factor", 200);
       set("combat_exp", 5000000);
       set("daoxing", 3000000);

       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 340);
       set_skill("spells", 300);
   set_skill("renshu", 280);
   set_skill("guixi-force", 280);
   set_skill("feitian-sword", 340);
   set_skill("fengyu-piaoxiang", 300);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "feitian-sword");
   map_skill("parry", "feitian-sword");
   map_skill("dodge", "fengyu-piaoxiang");
    set("inquiry", ([
	"��������"     : "[��������]��ʽ���ںݶ������²��Ὣ�������κ��˵ģ�",
                               ]) );

           set("chat_chance",2);
           set("chat_msg", ({
        WHT"����ЦЦ˵����ʦ���������ң�����������������ɱ����,�����������ûʵĽ��Ҳ�ڸǲ��������ʵ��\n"NOR,
        WHT"����ЦЦ˵����ѬС��Ҳ��˵������Ȼ������Ǿ��˽����Ǿ���ɱ�˵Ľ�����\n"NOR,
        WHT"����ЦЦ˵�������ʦ����˵��,ѬС���ֻ�Ǵ�δŪ����Լ����ֵ���˵����Ц����\n"NOR,
        WHT"����ЦЦ˵������������ʦ�����滰��ѬС�����Ц��֮�䣬�Ҹ�ϲ��ѬС�����Ц��һЩ��\n"NOR,
        }));

        create_family("��������", 1, "����");
        setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
          carry_object("/u/peaceful/sword")->wield();
}

void attempt_apprentice(object ob)
{
 if (((int)ob->query("PKS") > 0 )) {
   command("say " + RANK_D->query_respect(ob) +"��ɱ��̫�أ����ʺ�ѧϰ�ҵķ�����������\n");
   return;
   }

 if (((int)ob->query("swordman/zhizhixiong"))) {
   command("say " + RANK_D->query_respect(ob) +"�㲻�ʺ�ѧϰ�ҵķ�����������\n");
   return;
   }

 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +"�㲻�ʺ�ѧϰ�ҵķ�����������\n");
   return;
   }

 if (((int)ob->query("combat_exp") < 1200000 )) {
   command("say " + RANK_D->query_respect(ob) +"�����ȴ�û���������\n");
   return;
   }

   command("say �ã�ϣ��" + RANK_D->query_respect(ob) +"���Ŭ�����ý���������������С֮�ˡ�\n");
   command("recruit " + ob->query("id") );
   ob->set("title", WHT"��������������"NOR);
   ob->set("class", "swordman");
   return;
}
