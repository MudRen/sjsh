#include <ansi.h>
inherit NPC;

void create()
{
	int skill;

	set_name(YEL"��ˮ"NOR, ({ "mangjian yushui","mangjian","yushui" }) );
       set("title", WHT"ä��"NOR);
	set("gender", "����" );
	set("age", 40);
	set("long", "��־־�ۻ��ܵ���ˮ�����Ϊ�˴�־־�۶�������ʮ���У���ʵ��
������û�д�־־�۵����ġ�\n");
       set("per",20);
	set("combat_exp",1800000);
       set("daoxing",1800000);
       create_family("��������", 2, "����");
        set_skill("unarmed", 180);
        set_skill("dodge", 180);
        set_skill("parry", 180);
        set_skill("spells", 180);  
        set_skill("renshu", 180);
        set_skill("literate", 180);
        set_skill("sword", 180);  
        set_skill("doom-sword", 180); 
        set_skill("kongshoudao", 200); 
        set_skill("fengyu-piaoxiang", 180);
        set_skill("dodge", 180);  
        set_skill("force", 180);   
        set_skill("guixi-force", 180);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
          map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("unarmed", "kongshoudao");
        map_skill("dodge", "fengyu-piaoxiang");
        set("max_kee", 2500);
        set("max_gin", 2500);
        set("max_sen", 2500);
        set("force", 4800);
        set("max_force", 2400);
        set("force_factor", 200);
        set("mana", 4800);
        set("max_mana", 2400);
        set("mana_factor", 200);
        setup();
	  carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();

}

