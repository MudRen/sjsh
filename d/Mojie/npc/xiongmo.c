#include <ansi.h>
inherit NPC;
void create()
{
        set_name("��ħ", ({"xiong mo", "mo"}));
        set("gender", "����" );
        set("age", 33);
        set("title", "ħ�����齫");
        set("combat_exp", 500000);
	set("daoxing", 500000);

        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("ħ��", 3, "����");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("spells", 120);  
        set_skill("molianspells", 120);
        set_skill("literate", 120);
        set_skill("sword", 120);  
        set_skill("xueling-jian", 120);
        set_skill("shifo-zhi", 120);  
        set_skill("moshenbu", 120);
        set_skill("dodge", 120);  
        set_skill("force", 120);   
        set_skill("heilianforce", 120);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 50);
        set("mana", 1500);
        set("max_mana", 1500);
        set("mana_factor", 50);

        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();

}
