// ���� by Calvin

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
   set_name(HIM"����"NOR, ({"bu ma","bu","ma","tianshen"}));
   set("title", HIW"��������"NOR);
   set("gender", "Ů��");
   set("long", "����������ߡ�\n");
   set("attitude", "peaceful");
   set("combat_exp", 2000000);
   create_family("��ׯ��", 1, "��ʦ");
      set("age", 3000);
      set("per", 40);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "��������");
   set("max_kee", 5000);
   set("max_sen", 5000);
   set("force", 2400);
   set("max_force", 2400);
   set("force_factor", 40);
   set("max_mana", 2400);
   set("mana",2400);
   set("mana_factor", 50);

   set_skill("spells", 350);
   set_skill("taiyi", 350);
   set_skill("force",350);
   set_skill("zhenyuan-force",350);
   set_skill("parry", 350);
   set_skill("dodge", 350);
   set_skill("baguazhen", 350);
   set_skill("unarmed", 350);
   set_skill("wuxing-quan", 350);
   set_skill("sword",350);
   set_skill("xiaofeng-sword",350);
   set_skill("blade",350);
   set_skill("yange-blade",350);

   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("dodge", "baguazhen");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "xiaofeng-sword");
   map_skill("blade", "yange-blade");

        set("inquiry", ([
     "name"     : "С������������Ҳ��\n",
     "here"     : "����������Ҳ��\n",
        ]));

   set("time", 1);
   setup();
//        carry_object("/d/zj/weapon/lingyue")->wield();
      carry_object("/d/zj/armor/lingyue")->wear();   
      carry_object("/d/zj/armor/kui")->wear();   
//    carry_object("/d/penglai/npc/obj/bag");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="��ׯ��" )
   {
     if( (int)ob->query("family/generation") < 1  )
     {
        command("say ���ҵ������ҵ���\n");
     }
     else if( (int)ob->query("family/generation") ==1  )
     {
        command("say �Ǻǣ���" + ob->query("family/master_name") + "��ͽ�ܰ�,���ҾͲ������ˡ�\n");
        command("recruit " + ob->query("id") );
     }
     else 
     {
        if( ob->query_skill("taiyi", 1) >= 200 )
        {
          command("say �ã��г�Ϣ�����ͽ���������ˡ�\n");
          command("recruit " + ob->query("id") );
        }
        else
        {
          command("say �����ɼ�����ɷ����㻹�����ⷽ���¿๦��\n");
        }
     }
  }
   else
   {
     command("say �ã������㻹�����Ұ���������һЩ���ŵĹ���ɡ�\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}
