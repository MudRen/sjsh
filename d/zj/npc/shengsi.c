// �������� by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIM"��������"NOR, ({"shengsi eshen", "eshen", "shen"}));
       set("long",
"������֮һ���ػ���,���Ÿ���Ī��Ĺ�����\n");
       set("title", HIC"��������֮"NOR);
       set("gender", "Ů��");
       set("age", 30);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 40);
	set("int", 30);
       set("max_kee", 10000);
       set("max_gin", 10000);
       set("max_sen", 10000);
       set("force", 5000);
       set("max_force", 5000);
       set("force_factor", 300);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 300);
       set("combat_exp", 10000000);
  set("daoxing", 8000000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 350);
       set_skill("unarmed",350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("sword", 350);
       set_skill("spells", 350);
        set_skill("moonshentong", 350);
        set_skill("baihua-zhang", 350);
        set_skill("moonforce", 350);
        set_skill("snowsword", 350);
        set_skill("moondance", 350);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("�¹�", 1, "��ɽ��ʦ");
setup();

//        carry_object("/d/milin/obj/ssd");
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say �����¹�ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;}
        if ( (int)ob->query("per") <30){
	  command("shake");
	command("say ���ҿ���λ" +
RANK_D->query_respect(ob) + "�����ʲ����������裬��������߾Ͱɡ�\n");
  ob->set_temp("denied_by_chang_e",1);
	return;
}

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ�����������¹�������\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}


�
