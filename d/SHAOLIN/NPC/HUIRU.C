//gunseng.c
#include <ansi.h>

int ask_name(); 

inherit NPC;
inherit F_MASTER;
void create()
{

set_name("��������", ({
                "huiru zunzhe",
                "huiru",
		"zunzhe",
	}));
        set("gender", "����" );
        create_family("������", 3, "����");
        set("title",HIC"��ɽ�����»�������"NOR );
        set("age", 58);
set("long",
		"����һλ���ް߰׵���ɮ������һϮ�಼������ġ��������Ըߣ�\n"
		"̫��Ѩ΢͹��˫Ŀ��������\n"
	);
	set("class", "bonze");
	set("attitude", "heroism");

        set("force", 2200);
        set("max_force", 2200);
        set("force_factor", 70);
        set("mana", 2200);
        set("max_mana", 2200);
        set("mana_factor", 20);
        set("combat_exp", 1800000);
        set("daoxing", 1500000);

        set_skill("yijinjing", 200);
        set_skill("chanzong", 200);
        set_skill("spells", 200);
        set_skill("force", 200);
        set_skill("dodge", 180);
        set_skill("shaolin-shenfa", 180);
        set_skill("jingang-leg", 180);
        set_skill("unarmed", 180);
        set_skill("parry", 180);
        set_skill("stick", 180);
        set_skill("zui-gun", 180);
        map_skill("unarmed", "jingang-leg");
        map_skill("stick", "zui-gun");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "zui-gun");
        map_skill("force", "yijinjing");
        map_skill("spells", "chanzong");

	set("max_kee", 1300);
	set("max_sen", 1300);
	setup();
        carry_object("/d/shaolin/obj/qimeigun")->wield();
        carry_object("/d/shaolin/obj/hui-cloth")->wear();


}
void attempt_apprentice(object ob)
{
	object me; 
	mapping ob_fam, my_fam;
	string name, new_name;

	me = this_object();
	my_fam  = me->query("family");
	name = ob->query("name");

        if( (string)ob->query("gender") != "����" )
	{
		command ("say �����ӷ�Ůʩ��ѽ��ƶɮ�ɲ��ҿ������Ц����");
		return;
        }

          if(((int)ob->query_skill("yijinjing",1) < 100))
        {
	command("say " + RANK_D->query_respect(ob) + "�����׽��Ϊ����������Խ����ʦ��");
                return;
        }

          if( (int)ob->query_skill("chanzong",1) < 100)
        {
        command("say " + RANK_D->query_respect(ob) + "����������Ϊ����������Խ����ʦ��");
                return;
        }

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
	{
		command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
		return;
	}

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
	{
		command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
		return;
	}

	command("say �����ӷ����գ����գ�");
        command("recruit " + ob->query("id"));
        ob->set("title", HIC"��ɽ�����»�������"NOR);
}