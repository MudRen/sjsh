#include <ansi.h>
inherit NPC;

void create()
{
	int skill;

	set_name(WHT"��������"NOR, ({ "juxing youmei","youmei","juxing" }) );
       set("title", "");
	set("gender", "Ů��" );
	set("age", 22);
	set("long", "������־־�����İ���Ů�ˡ�\n");
       set("per",40);
	set("combat_exp",1000000);
       set("daoxing",1000000);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("renshu", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("doom-sword", 100); 
        set_skill("kongshoudao", 100); 
        set_skill("fengyu-piaoxiang", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("guixi-force", 100);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("stick", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("unarmed", "kongshoudao");
        map_skill("dodge", "fengyu-piaoxiang");
        set("max_kee", 1500);
        set("max_gin", 1500);
        set("max_sen", 1500);
        set("force", 2000);
        set("max_force", 1500);
        set("force_factor", 80);
        set("mana", 2000);
        set("max_mana", 1500);
        set("mana_factor", 80);
        setup();
        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}
