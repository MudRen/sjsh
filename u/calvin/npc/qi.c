// �������� calvin,2001.5

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("��������", ({"qi tianshen", "qi", "qichong", "tianshen"}));
        set("title", "�칬����");
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","��������������ػ�����,�������߾�����,�ֳ�һ�ѽ�,����òɷ������!\n");

        set("attitude", "aggressive");
       set("class","xian");
       set("max_kee", 5500);
       set("max_gin", 800);
       set("max_sen", 5500);
       set("force", 5500);
       set("max_force", 5500);
       set("force_factor", 255);
       set("max_mana", 5500);
       set("mana", 5500);
       set("mana_factor", 255);
       set("combat_exp", 3500000);
           set("daoxing", 38000000);
       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 300);
       set_skill("spells", 310);
       set_skill("whip", 300);
   set_skill("pansi-dafa", 310);
   set_skill("lanhua-shou", 300);
   set_skill("jiuyin-xinjing", 300);
   set_skill("chixin-jian", 300);
   set_skill("qin", 300);
   set_skill("yueying-wubu", 300);
   set_skill("yinsuo-jinling", 300);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "wuzhishan" :),
                (: cast_spell, "ziqi" :)
        }) );
setup();
        carry_object("/d/calvin/armor/pifeng")->wear();
        carry_object("/d/pansi/obj/ziqing.c")->wield();
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "perform");
add_action("do_error", "fight");
add_action("do_error", "fly");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}
