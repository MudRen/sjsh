// һ������ calvin,2001.5

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIC"�ɽ�"NOR, ({"gan jiang", "ga", "jiang","yi", "tianshen"}));
        set("title", HIW"��Ұ˫��"NOR);
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","�����һ�������ػ�����,���ֳ���ԯ��,����òɷ������!\n");

        set("attitude", "aggressive");
        set("class", "yaomo");
        set("combat_exp", 1000000);
        set("daoxing", 3000000);

        create_family("��ѩɽ", 1, "��ʦ");
//        set("rank_info/respect", "����");
        set_skill("unarmed", 150);
        set_skill("cuixin-zhang", 150);
        set_skill("dodge", 150);
        set_skill("xiaoyaoyou", 150);
        set_skill("parry", 150);
        set_skill("sword", 150);
        set_skill("bainiao-jian", 150);
        set_skill("blade", 150);
        set_skill("bingpo-blade", 150);
        set_skill("throwing", 150);
        set_skill("force", 150);   
        set_skill("ningxie-force", 150);
        set_skill("literate", 150);
        set_skill("spells", 300);
        set_skill("dengxian-dafa", 300);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 3500);
        set("max_sen", 3500);
        set("force", 3500);
        set("max_force", 1800);
        set("mana", 4000);
        set("max_mana", 2000);  
        set("force_factor", 120);
        set("mana_factor", 100);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi":),
                (: cast_spell, "tuntian" :),
//          (: cast_spell, "jieti" :),
                (: perform_action, "sword", "chaofeng":),
            (: perform_action, "sword", "feijian":),
       }) );

            setup();
    carry_object("/d/obj/armor/jinjia")->wear();
      carry_object("d/calvin/armor/sword")->wield();
}

void init()
{
object who=this_player();
add_action("do_error", "mark");
add_action("do_error", "perform");
add_action("do_error", "fly");
add_action("do_error", "fight");
}

int do_error(string arg)
{
object who = this_player();
message_vision("��Ҫ����Ŷ,С�ı�����������ӣ�\n",who);
return 1;
}
