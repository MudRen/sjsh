//shenyi.c ��٢����

#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"��٢����"NOR, ({"master huatuo", "master"}));
       set("long", "�������˵����ɡ�\n");
       set("title", HIC"��������"NOR);
       set("per", 40);
       set("gender", "����");
       set("age", 1000);
        set("attitude", "peaceful");

        set("combat_exp", 20000000);
        set("daoxing", 500000);
        set("shen_type", 1);
        set("max_kee", 2000);
        set("max_gin", 1000);
        set("max_sen", 2000);
	set("max_force", 8888);
	set("force", 8888);
        set("max_mana", 8888);
	set("mana", 8888);
	set("force_factor", 200);
        set_skill("medical", 800);

        set("inquiry", ([
	"name"     : "�Ϸ���һ�鲼�£���\n",
	"here"     : "���˼����ã�ר�����²����β��ĵط���\n",
	//"��ҩ"     : (: ask_me :),
	]));
	setup();
        carry_object("/d/obj/cloth/linen")->wear();
}

int recognize_apprentice(object ob)
{ob=this_player();
if ((int)ob->query("level") < 5 ) {
        command("say ��ĵȼ�����5����" + RANK_D->query_respect(ob) + "������Ŭ����\n");
	return 1;
	}
	return 1;
}

�
