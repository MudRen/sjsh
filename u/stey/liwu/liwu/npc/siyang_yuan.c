

#include <ansi.h>

inherit NPC;



void create()
{
	set_name("��������Ա", ({ "siyang yuan", "yuan" }) );
	set("title", HIY"������ϰ�"NOR);
	set("gender", "����" );

	set("age", 50);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
         
	set("long",
		"���������������ϰ壬����������û���뵽���֣������Լ����ֵ��ϰ��ֵ���ơ�\n" );

	set("combat_exp", 50000);
	set("attitude", "friendly");
	

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
        set("jiali",50);

        set_skill("unarmed",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("force",70);
 
        set_temp("apply/attack",50);
        set_temp("apply/defense",50);




	setup();
    carry_object("/d/liwu/obj/weiqun")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say �����������İɣ�\n");
}

