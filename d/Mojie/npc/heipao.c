#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"heipao"}));
        set("gender", "����" );
        set("age", 33);
        set("title", "���������һ���");
        set("combat_exp", 1500000);
	set("daoxing", 1500000);
              set("long","��ħ�����������һ�����Ϊ���׺ݲб�����Ѫ����������
��һɽ�����������շ����ü����ã�������ز����ٵ�
�����֡�\n");
        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("ħ��", 2, "����");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("sword", 280);  
        set_skill("xueling-jian", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);

        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/sword")->wield();
}
void attempt_apprentice(object ob, object me)
{
        if( (int)ob->query_skill("molianforce", 1) < 120 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����ħ���ڹ���ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");              
        return;
        }
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"����ħ���Ժ���Ŭ��������Ϊɱ����������Ĺ��ס�\n");
        command("recruit " + ob->query("id") );
            ob->set("title", HIC"ħ���һ������µ���"NOR);
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}

�
