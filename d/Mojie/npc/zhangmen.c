// worker.c

inherit NPC;
#include <ansi.h>
int rank_me();
void create()
{
        set_name("���¡�����", ({"zhang men","zhang","man"}));
        set("gender", "����" );
        set("class", "mo" );
        set("title",HIY"ħ������"NOR);
        set("age", 30);
        set("long", "ħ�����Ŵ�ʦ�֡�\n");
        set("combat_exp", 1500000);
	  set("daoxing", 1500000);
        set("attitude", "peaceful");
	  set("int", 25);
	  set("class", "mo");
        set("eff_dx", 30000);
        set("nkgain", 200);
              set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);
        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("sword", 280);  
        set_skill("xueling-jian", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);
        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("sword", "xueling-jian");
        map_skill("parry", "xueling-jian");
        map_skill("dodge", "moshenbu");
        create_family("ħ��", 2, "����");
	 set("inquiry", ([
		"name" : "�ٺ٣��Ҿ���ħ�����Ŵ���ӣ�\n",
		"here" : "����ħ�硣\n",
		"���Ŵ����" :"����Ҫͨ�������ͬ����ܳ�������һְ��\n",		
		"���ŵ���" :"����Ҫͨ�������ͬ����ܳ�������һְ��\n",			
		"�����" :"����Ҫͨ�������ͬ����ܳ�������һְ��\n",			
		"����" :"����Ҫͨ�������ͬ����ܳ�������һְ��\n",		
		"ְλ" : (: rank_me :),	 
	]) );


        setup();
        carry_object("/d/obj/armor/jinjia.c")->wear();
        carry_object("/d/mojie/obj/sword")->wield();
}
int rank_me()
{
	object me=this_player();
	object ob=this_object();
	int exp;
	exp=(int)me->query("combat_exp");
        if( me->query("title") == "ħ���޷�����ħ��"
          ||me->query("title") == "ħ���޷�������")
		return notify_fail("���Ѿ���������ݣ�����Ҫʲôְλ��\n");
	if(me->query("gender") == "����")
	{
	if( me->query("family/family_name") == "ħ��")
	{
                if( exp <= 20000 ){
			me->set("title", "ħ��﷿���");
		} else if(exp <= 50000 ){
			me->set("title", "ħ���ͷ�ͯ��");
		} else if(exp < 100000 ){
			me->set("title", "ħ�绤ɽ����");
		} else if(exp <= 200000 ){
			me->set("title", "ħ��⽣���ƽ�");
		} else if(exp <= 500000 ){
			me->set("title", "ħ�����ɽ��");
		} else if(exp <= 1000000 ){
			me->set("title", "ħ��̫������");
		} else if(exp <= 2000000 ){
			me->set("title", "ħ��������ʦ");
		} else {
			me->set("title", "ħ����ʥ����");
		}

		tell_object(me, HIR""+ob->query("name")+"����˵���������"+me->query("title")+"��\n"NOR);
		tell_room(environment(me),
HIR""+ob->query("name")+"��"+me->query("name")+"˵���������"+me->query("title")+"��\n"NOR, ({me, me}));
                
	}
        }
        else
        {
	if( me->query("family/family_name") == "ħ�����Ƕ�")
	{
                if( exp <= 20000 ){
			me->set("title", "ħ��﷿����");
		} else if(exp <= 50000 ){
			me->set("title", "ħ�����Ůͯ");
		} else if(exp < 100000 ){
			me->set("title", "ħ����Ժ����");
		} else if(exp <= 200000 ){
			me->set("title", "ħ��ҽ��Ժ����");
		} else if(exp <= 500000 ){
			me->set("title", "ħ������ʥ��");
		} else if(exp <= 1000000 ){
			me->set("title", "ħ����¶�ɹ�");
		} else if(exp <= 2000000 ){
			me->set("title", "ħ��ܽ��ʥĸ");
		} else {
			me->set("title", "ħ����ˮ��");
		}

		tell_object(me, HIR""+ob->query("name")+"����˵���������"+me->query("title")+"��\n"NOR);
		tell_room(environment(me),
HIR""+ob->query("name")+"��"+me->query("name")+"˵���������"+me->query("title")+"��\n"NOR, ({me, me}));
	}
        }
	return 1;
}
