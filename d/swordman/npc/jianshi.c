inherit NPC;

void create()
{
        set_name("��孽�ʿ", ({ "jian shi", "shi" }));
        set("gender", "����");
        set("age", random(10) + 30);
        set("str", 25);
	  set("long", "��孹����س��ŵĽ�ʿ���������ݵ�Ѳ������Χ��\n");
        set("combat_exp", 1500000);
             set("daoxing", 1500000);

        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("spells", 180);  
        set_skill("renshu", 180);
        set_skill("literate", 180);
        set_skill("sword", 180);  
        set_skill("lixin-sword", 180); 
        set_skill("fengyu-piaoxiang", 180);
        set_skill("dodge", 180);  
        set_skill("force", 180);   
        set_skill("guixi-force", 180);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("stick", "lixin-sword");
        map_skill("parry", "lixin-sword");
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
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/obj/cloth/zhanpao")->wear();
}


�