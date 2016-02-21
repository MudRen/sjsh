#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_go();

void create()
{
        set_name("��Ы", ({"juxie"}));
        set("gender", "Ů��" );
        set("age", 33);
        set("title", "���������󻤷�");
        set("combat_exp", 1500000);
	set("daoxing", 1500000);
        set("long", "�������������󻤷���������ز����ٵ������š�
�����������һ�мƲ߶���������������Ϊ��
���ս�թ����ƶ�ˡ�\n");
        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("ħ��", 2, "����");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("whip", 280);  
        set_skill("liudu-whip", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("whip", "liudu-whip");
        map_skill("parry", "liudu-whip");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);
        set("inquiry", ([
                "back" : (: ask_go :),
        ]) );


        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/ldwhip")->wield();
}

string ask_go()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        write("��Ы����˵������Ҫ��ȥ�𣿱��������ھ������ߣ�\n");
        write("��Ы���˼���������·���һ��޴�ĺ�������������ȥ.......\n");
        if(!( room = find_object("/d/city/center")) )
            room = load_object("/d/city/center");
        if(objectp(room))
            who->move(room);
        return "\n��Ы���˼���������·���һ��޴�ĺ�����һ����������ȥ.......\n\n";
}


void attempt_apprentice(object ob, object me)
{
        if( (int)ob->query_skill("molianforce", 1) < 120 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "����ħ���ڹ���ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");              
        return;
        }
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"����ħ���Ժ���Ŭ��������Ϊɱ����������Ĺ��ס�\n");
        command("recruit " + ob->query("id") );
            ob->set("title", HIG"ħ���󻤷����µ���"NOR);
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}
