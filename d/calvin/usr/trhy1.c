// ���NPC.trhy by Calvin of 2001.5

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("ϴ��˯����", ({"trhy's"}));
        set("title", HIR"�˲�����֮����"NOR);
        set("gender", "����" );
        set("age", 40);
        set("per", 38);
        set("str", 330);
set("long","���Ǹ��¶���������\n");

//        set("attitude", "aggressive");
//      set("class","dragon");
       set("shen_type", 1);
       set("combat_exp", 7123194);
       set("daoxing", 8350000);
       set("max_kee",2817);
       set("max_gin", 306);
       set("max_sen", 2810);
       set("force", 12000);
      set("max_force", 5600);
       set("force_factor", 306);
       set("max_mana", 7500);
       set("mana", 18000);
       set("mana_factor", 260);

       set_skill("dodge", 365);
       set_skill("force", 355);
       set_skill("literate", 246);
       set_skill("parry", 376);
       set_skill("spells", 365);
       set_skill("staff", 387);
       set_skill("unarmed", 249);
       set_skill("buddhism", 365);
       set_skill("dragonfight", 258);
       set_skill("lotusforce", 382);
       set_skill("lotusmove", 384);
       set_skill("lunhui-zhang", 349);

        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("spells", "buddhism");
        map_skill("staff", "lunhui-zhang");
        map_skill("unarmed", "dragonfight");

       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: cast_spell, "jinguzhou" :),
                (: cast_spell, "lianhua" :),
              (: perform_action, "staff", "pudu" :),
              (: perform_action, "staff", "qifei" :),
              (: perform_action, "staff", "diyu" :),
                }) );
        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/obj/cloth/pobuyi")->wear();
        carry_object("/d/obj/weapon/staff/nine-ring")->wield();
}
