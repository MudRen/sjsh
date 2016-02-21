// �������� calvin,2001.5

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name(HIC"����"NOR, ({"kai yun", "san", "kai","yun", "tianshen"}));
        set("title", HIW"��������"NOR);
        set("gender", "����" );
        set("age", 45);
        set("per", 30);
        set("str", 30);
set("long","��������������ػ�����,��������������,����òɷ������!\n");

        set("attitude", "aggressive");

        set("combat_exp", 3000000);
        set("daoxing", 3500000);
        set("eff_dx", -500000);
        set("nkgain", 500);

        set("class","yaomo");
        set("max_kee", 1600);
        set("max_sen", 1600);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 300);
        set("max_mana", 3000);
        set("mana", 3000);
        set("mana_factor", 280);

        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("parry", 200);
        set_skill("spear", 200);
        set_skill("spells", 300);
        set_skill("huoyun-qiang", 200);
        set_skill("moshenbu", 200);
        set_skill("moyun-shou", 200);
        set_skill("huomoforce", 200);
        set_skill("pingtian-dafa", 300);

        map_skill("force", "huomoforce");
        map_skill("spells", "pingtian-dafa");
        map_skill("unarmed", "moyun-shou");
        map_skill("dodge", "moshenbu");
        map_skill("parry", "huoyun-qiang");
        map_skill("spear", "huoyun-qiang");

        set("kusong/Teach_Hong", 1);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: cast_spell, "sanmei" :),
            (: perform_action, "spear.ji" :),
            (: perform_action, "spear.huohun" :),
                (: exert_function, "heal" :),
                (: exert_function, "fire" :),
            (: perform_action, "spear.lihuo" :),
        }));
  set_temp("apply/armor", 50);
  set_temp("apply/dodge", 50);

            setup();
      carry_object("/d/calvin/armor/shenpao")->wear();
      carry_object("d/obj/weapon/spear/jinqiang")->wield();
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

