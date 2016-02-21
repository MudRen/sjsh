// xianglong.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIY"�����޺�"NOR, ({"xianglong luohan", "luohan"}));
       set("long", "������޺�һ�������������֮һ��\n");
       set("title", HIC"����ɽ���Ƕ�"NOR);
       set("gender", "����");
       set("age", 50);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "�޺�");
       set("looking", "�������󣬲������Ʈ���𾦷ɻ��棬��Ŀ��ü�ҡ�");
       set("max_kee", 3000);
       set("max_gin", 500);
       set("max_sen", 3000);
       set("force", 3000);
       set("max_force", 1500);
       set("force_factor", 50);
       set("max_mana", 1500);
       set("mana", 2000);
       set("mana_factor", 50);
       set("combat_exp", 1400000);
       set("daoxing", 2100000);

        set_skill("unarmed", 140);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("dao", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 100);
        set_skill("fumobashi", 140);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 140);   
        set_skill("wuxiangforce", 140);

        map_skill("spells", "dao");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

create_family("����ɽ���Ƕ�", 2, "�޺�");
   setup();
   carry_object("/d/obj/weapon/sword/qinghong")->wield();
   carry_object("/d/obj/armor/jinjia")->wear();
}
void attempt_apprentice(object ob, object me)
{
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

�
