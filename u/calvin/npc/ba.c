// �������� calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��������", ({"ba tianshen", "ba", "bachong", "tianshen"}));
        set("title", "�칬����");
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","����ǰ��������ػ�����,�����ϴ��а˲�����,����òɷ������!\n");

        set("attitude", "aggressive");
        set("class","dragon");
       set("shen_type", 1);
       set("combat_exp", 4000000);
       set("daoxing", 40000000);
       set("max_kee", 5000);
       set("max_gin", 400);
       set("max_sen", 5000);
       set("force", 5600);
       set("max_force", 5600);
       set("force_factor", 280);
       set("max_mana", 5600);
       set("mana", 5600);
       set("mana_factor", 260);

       set_skill("huntian-hammer", 320);
        set_skill("hammer", 320);
        set_skill("literate", 320);
       set_skill("unarmed", 320);
       set_skill("dodge", 320);
       set_skill("force", 320);
       set_skill("parry", 320);
       set_skill("fork", 320);
       set_skill("spells", 340);
        set_skill("seashentong", 340);
        set_skill("dragonfight", 320);
        set_skill("dragonforce", 320);
        set_skill("fengbo-cha", 320);
        set_skill("dragonstep", 320);
        map_skill("hammer", "huntian-hammer");
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("dodge", "dragonstep");
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "unarmed", "sheshen" :),
                }) );
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/calvin/armor/wan")->wear();
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "fight");
add_action("do_error", "fly");
add_action("do_error", "perform");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}
