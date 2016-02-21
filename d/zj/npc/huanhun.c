// ����ɷ�� by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIB"����ɷ��"NOR, ({"huanhun shashen","huanhun", "shashen", "shen"}));
       set("long", "�������׵�һλ���ɡ�\n");
       set("title", HIC"��������֮"NOR);
       set("class", "youling");
       set("gender", "����");
       set("age", 3000);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
       set("max_kee", 200000);
       set("max_gin", 1000);
       set("max_sen", 200000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 30);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);
       set("rank_info/respect", "��ɷ��");

        set_skill("jinghun-zhang", 350);
        set_skill("tonsillit", 350);
        set_skill("gouhunshu", 350);
        set_skill("unarmed", 350);
        set_skill("whip", 350);
        set_skill("sword", 350);
        set_skill("hellfire-whip",350);
        set_skill("zhuihun-sword", 350);
        set_skill("dodge", 350);
        set_skill("ghost-steps", 350);
        set_skill("parry", 350);
        set_skill("spells", 350);
        set_skill("force", 350);

        map_skill("sword", "zhuihun-sword");
        map_skill("parry", "zhuihun-sword");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("whip", "hellfire-whip");
        map_skill("spells", "gouhunshu");

        set("nk_gain", 500);

        set_temp("apply/armor", 50);
        set_temp("apply/dodge", 50);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :)
        }) );

set("inquiry", ([
"name": "�ߣ����Ϸ򶼲��ϵã������ǻ��̫���ˣ�\n",
"here": "�����������֮������,�ɲ��Ƿ�������֮�أ�\n",
]) );

create_family("���޵ظ�", 1, "��ʦ");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob, object me)
{
        if ( (string)ob->query("family/family_name")=="���޵ظ�") {
        if (((int)ob->query("combat_exp") < 1000000 )) {
        command("say " + RANK_D->query_rude(ob) + ",��Զ��ȥ��,�������ң�\n");
        return;
        }
        command("grin");
        message_vision("����ɷ���$N�ٺٵ�Ц�˼�����\n", ob);
        message_vision("����ɷ������$N�ļ��˵�����Ժ���������ù��������г�ͷ�����ӣ�\n", ob);
        command("recruit " + ob->query("id") );
        return;
        }
        message_vision("����ɷ���$N�ȵ���������������ë�������ܵ�����������Ұ�����Һ��ȥ��\n", ob);
        message_vision("�ܽ�����������С���$N���˳�ȥ��\n", ob);
        ob->move("/d/milin/qy/sc");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youling");
}

