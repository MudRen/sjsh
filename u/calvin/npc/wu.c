// �������� calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��������", ({"wu tianshen", "wu", "wuchong", "tianshen"}));
        set("title", "�칬����");
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","��������������ػ�����,��ͷ���������,�ֳ�һ����ͭ����,����òɷ������!\n");

        set("attitude", "aggressive");
        set("class", "bonze");
        set("str",34);
        set("per",100);//means no rong-mao description.
        set("max_kee", 6000);
        set("max_gin", 6000);
        set("max_sen", 6000);
        set("force", 6000);
        set("max_force", 6000);
        set("force_factor", 245);
        set("max_mana", 6000);
        set("mana", 6000);
        set("mana_factor", 240);
        set("combat_exp", 3000000);
        set("daoxing", 12000000);

        set_skill("literate", 250);
        set_skill("spells", 300);
        set_skill("buddhism", 300);
        set_skill("unarmed", 250);
        set_skill("jienan-zhi", 250);
        set_skill("dodge", 250);
        set_skill("lotusmove",250);
        set_skill("parry", 250);
        set_skill("force", 250);
        set_skill("lotusforce", 250);
        set_skill("staff", 250);
        set_skill("lunhui-zhang", 250);
        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 200);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
                (: cast_spell, "jinguzhou" :),
                (: cast_spell, "lianhua" :),
                (: cast_spell, "jingang" :),
                (: perform_action, "staff.pudu" :),
                (: perform_action, "staff.qifei" :),
                (: perform_action, "staff.diyu" :),
        }) );
        setup();
        carry_object("/d/calvin/armor/kui")->wear();
        carry_object("/d/nanhai/obj/nine-ring")->wield();
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
