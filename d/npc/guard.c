// dizi.c

inherit NPC;

void create()
{
	int skill;

	set_name("����", ({ "jian ke","jianke","ke" }) );
       set("title", "ʮ����");
	set("gender", "����" );
	set("age", 18+random(10));
	set("long", "־־��һ�ֵ��̳����Ľ���,������Ϊ��һ�����˽��Ϳɱȡ�\n");
	set("combat_exp",1000000);
       set("daoxing",1000000);
       create_family("��������", 3, "����");
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("renshu", 100);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("doom-sword", 100); 
        set_skill("fengyu-piaoxiang", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("guixi-force", 100);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("stick", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("dodge", "fengyu-piaoxiang");
        set("max_kee", 1300);
        set("max_gin", 1300);
        set("max_sen", 1300);
        set("force", 3000);
        set("max_force", 1500);
        set("force_factor", 100);
        set("mana", 3000);
        set("max_mana", 1500);
        set("mana_factor", 100);
        setup();
	  carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
