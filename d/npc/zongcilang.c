
inherit NPC;
inherit F_MASTER;
int ask_wuxiang();
#include <ansi.h>

void create()
{
	set_name(HIC"�����ڴ���"NOR, ({ "master zongcilang", "master", "zongcilang" }) );
       set("title", WHT"�콣"NOR);
	set("gender", "����" );
	set("age", 18);
	set("long", "���š��콣���ƺŵ�ʮ������ǿ���͡����ҵ�ͯ������ʹ��ֻ�ܱ�
��ϲŭ������ϲ��һ�档û�и��鲨�����ڴ����ܽ�ɱ�˽����ľ���
���ӵ����¡�\n");
       set("class", "swordman");
       set("attitude", "friendly");
       set("spi", 40);
       set("str", 40);
       set("con", 40);
       set("kar", 40);
       set("per", 40);
	set("int", 40);
       set("max_kee", 3000);
       set("max_gin", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 240);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 240);
       set("combat_exp", 2600000);
        set("daoxing", 2600000);
        set("inquiry", ([
                 "����ն" : (: ask_wuxiang :),
                 "wuxiang" : (: ask_wuxiang :),
         ]) );
        create_family("��������", 2, "����");
        set_skill("unarmed", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("spells", 200);  
        set_skill("renshu", 200);
        set_skill("literate", 200);
        set_skill("sword", 240);  
        set_skill("doom-sword", 240); 
        set_skill("fengyu-piaoxiang", 200);
        set_skill("dodge", 200);  
        set_skill("force", 200);   
        set_skill("guixi-force", 200);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("dodge", "fengyu-piaoxiang");

           set("chat_chance",5);
           set("chat_msg", ({
        WHT"�ڴ���΢Ц��˵��������ǿʳ��ʼ����������粻�������\n"NOR,
        WHT"�ڴ���΢Ц��˵����־־�۴���Ҫ��ת���ң��������־־�۴���Ҫ�ˡ�\n"NOR,
        WHT"�ڴ���΢Ц��˵����ɱ�˵�ʱ���������Ļ���Ѫ���˿��������ʱ�������һ�����ܺ�����\n"NOR,
        }));

              setup();
	 carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}



void attempt_apprentice(object ob)
{
        if ( (int)ob->query("int") <25){
	  command("shake");
	command("say �����¿���λ" +
RANK_D->query_respect(ob) + "���츳�����ʺ���������ѧϰ��������������߾Ͱɡ�\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;}

        if ( (int)ob->query("kar") <25){
	  command("shake");
	command("say �����¿���λ" +
RANK_D->query_respect(ob) + "���츳�����ʺ���������ѧϰ��������������߾Ͱɡ�\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;
}

        command("pat "+ob->query("id"));
        command("say ϣ�����ܹ���־־�۴������մ�����Ĵ�ҵ��\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	            ob->set("title", WHT"ʮ���н���"NOR);
              ob->set("class", "swordman");
}

int ask_wuxiang()
{

    object ob=this_player();
    if(ob->query("family/master_name") != HIC"�����ڴ���"NOR)
    {
    command("say �㲻�����µ��ӣ�ˡ���²��ܽ�����ն�����ܸ����㡣");
    return 1;
    }
    if(ob->query("combat_exp") < 1000000 ) 
    {
    command("say �����Ϊ�������޷���ᵽ����ն�����ܡ�");
    return 1;
    }
    if(ob->query("swordman/wuxiang_perform"))
    { 
    command("say �㲻���ʹ�����? ");
    return 1;
    }
    if(ob->query("family/master_name") == HIC"�����ڴ���"NOR)
    {
    command("say ����ն�����ܾ���û�����ܣ�^^");
    ob->set("swordman/wuxiang_perform",1);
    return 1;
    }
}

