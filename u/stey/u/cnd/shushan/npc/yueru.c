//Cracked by Roath
//����ɽ���ɡ�dhxy-evil 2000.7.5
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("������", ({ "lin yueru", "yueru"}));
        set("long", 
"������Ů��ǧ�𣬱������׶����ģ�\n");
        set("gender", "Ů��");
        set("age", 15);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("spi", 50);
        set("per", 40);
        set("kee", 2000);
        set("max_kee", 2000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 4000);
        set("max_force", 2000);
        set("mana", 6000);
        set("max_mana", 3000);
        set("force_factor", 60);
        set("mana_factor", 100);

        set("combat_exp", 1500000);
        set("daoxing", 2000000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("yirubian", 200);
        set_skill("whip",180);
        set_skill("force",120);
        setup();
        create_family("��ɽ����", 2, "��");
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/cloth/xiuhuaxie")->wear();
}
int attempt_apprentice(object me)
{
  if ( (me->query("per") < 20 ) && 
       (me->query("gender") != "Ů��") )
     {
           command("heng "+me->query("id");
		command("say " + "������Ե���α�ǿ��\n");
		return;
	}
  command("ok "+me->query("id"));
  command("say Ե���춨����Ҳֻ����ˡ�");
  command("recruit " + me->query("id") );
  return 1;
}
