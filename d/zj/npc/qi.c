// ��һ by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIB"��һ"NOR, ({"long yi", "long", "yi","tianshen"}));
       set("long", "�����������һ���к�ǿ��ķ�����\n");
       set("title", HIW"��������"NOR);
       set("gender", "����");
       set("age", 3000);
       set("int", 25+random(5));
       set("attitude", "peaceful");
       set("combat_exp", 1000000);
       set("daoxing", 1000000);

       set("rank_info/respect", "��һ����");
       set("class","dragon");
       set("per", 30);
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 100);

       set_skill("literate", 350);
       set_skill("unarmed", 350);
       set_skill("dodge", 350);
       set_skill("force", 350);
       set_skill("parry", 350);
       set_skill("fork", 350);
       set_skill("spells", 350);
       set_skill("seashentong", 350);
       set_skill("dragonfight", 350);
       set_skill("dragonforce", 350);
       set_skill("fengbo-cha", 350);
       set_skill("dragonstep", 350);

       map_skill("spells", "seashentong");
       map_skill("unarmed", "dragonfight");
       map_skill("force", "dragonforce");
       map_skill("fork", "fengbo-cha");
       map_skill("parry", "fengbo-cha");
       map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "fork", "fengbo" :),
                }) );
            create_family("��������", 1, "ˮ��");
        setup();

        carry_object("/d/zj/armor/pifeng")->wear();
      carry_object("/d/zj/weapon/fork")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="��������") {
        if ((int)ob->query("daoxing") < 5000000 ) {
        command("say ��ĵ��в��Ǻܸ߰���" + RANK_D->query_respect(ob) + "������Ŭ������������Ϊ����\n");
        return;
        }
/*
        if( (int)ob->query("pending/kick_out")) {
        command("say ��λ" + RANK_D->query_respect(ob) + "�����޳���С�ɲ�ԭ������Ϊͽ�ˣ�\n");
        command("sigh");
        return;
        }
*/
        if ((int)ob->query_int() < 40) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
        return;
        }
        command("shake");
        command("say С�ɲ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "dragon");
}

