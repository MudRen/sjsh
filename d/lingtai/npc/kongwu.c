// kongwu.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"��̨ʥ��"NOR, ({"master shengju", "shengju", "master"}));
       set("long", "�й���ǧ�괫��������̹ſ����������ƹ������е��似��\n");
       set("title", HIC"����ɽʥ��"NOR);
       set("gender", "����");
       set("age", 100);
       set("str", 50);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
//       set("rank_info/respect", "���");
       set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 150);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 150);
       set("combat_exp", (random(7)+1)*5500000);
       set("daoxing", (random(6)+2)*7500000);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spells", 200);  
        set_skill("dao", 200);
        set_skill("literate", 200);
        set_skill("sword", 200);  
        set_skill("wuying", 200);
        set_skill("fumobashi", 200);  
        set_skill("mizongbu", 200);
        set_skill("dodge", 200);  
        set_skill("force", 200);   
        set_skill("wuxiangforce", 200);

        map_skill("spells", "dao");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        (: cast_spell, "feixian" :),
	}) );

	create_family("����ɽ���Ƕ�", 1, "����");
	
        setup();
        carry_object("/d/lingtai/obj/cloth2")->wear();
        carry_object("/d/lingtai/obj/pifeng")->wear();
        carry_object("/d/lingtai/obj/sword")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
	if ((int)ob->query("daoxing") < 500000 ) {
  	command("say ���ǽ�ħ����֮�����صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�����޳����Ϸ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 140 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���ҵ�����ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
}

�
