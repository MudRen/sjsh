inherit NPC;
inherit F_MASTER;
int ask_yanling();
int ask_miyan();
#include <ansi.h>

void create()
{
	set_name(WHT"־־����ʵ"NOR, ({ "master zhizhixiong", "master", "zhizhixiong","zhenshi" }) );
       set("title", "");
	set("gender", "����" );
	set("age", 30);
	set("long", "���̳��˽���ǧ��ն�ĵ�λ��ȴ��Ұ��̫�����ά������׷ɱ������
��ͬ־�����ӳ������־־�ۣ����Ŷ�ά��������ǿ�Һ����Լ���Ȩ��
�ļ��ȿ�����֯��ʮ���У��Խ���һ��ǿ��ͳ�εĹ��ȶ������Ʒ�ά��
�����Ŀֲ����\n");
       set("class", "swordman");
       set("spi", 40);
       set("str", 40);
       set("con", 40);
       set("kar", 40);
       set("per", 25);
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 5000);
       set("max_sen", 5000);
       set("force", 8000);
       set("max_force", 5000);
       set("force_factor", 300);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 300);
       set("combat_exp", 5000000);
           set("daoxing", 5000000);
        create_family("��������", 1, "����");
        set("inquiry", ([
                 "����" : (: ask_yanling :),
                 "�ܽ�������" : (: ask_yanling :),
                 "��ǿ����":(:ask_miyan :),
         ]) );

        set_skill("unarmed", 320);
        set_skill("dodge", 320);
        set_skill("parry", 320);
        set_skill("spells", 320);  
        set_skill("renshu", 320);
        set_skill("literate", 320);
        set_skill("sword", 360);  
        set_skill("doom-sword", 360); 
        set_skill("fengyu-piaoxiang", 320);
        set_skill("dodge", 320);  
        set_skill("force", 320);   
        set_skill("guixi-force", 320);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "doom-sword");
        map_skill("parry", "doom-sword");
        map_skill("dodge", "fengyu-piaoxiang");

        setup();
	 carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
//        if ( (int)ob->query("kill/pkgain") <100000){
//	  command("shake");
//	command("say û��ʶ��ɱ¾�������ˣ����ʺ�ѧϰ�ҵ�ɱ�˽�����\n");
//	return;}

        if ( (int)ob->query("MKS") <3000){
	  command("shake");
	command("say û��ʶ��ɱ¾�������ˣ����ʺ�ѧϰ�ҵ�ɱ�˽�����\n");
	return;}

        if ( (int)ob->query("combat_exp") <1500000){
	command("shake");
	command("say �����Ϊ���������ʺ�ѧϰ�ҵ�ɱ�˽�����\n");
	return;}

        command("sneer ");
        command("say �һ�����ʶ����������ģ����\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
	       ob->set("title", WHT"ʮ���н���"NOR);
              ob->set("class", "swordman");
              ob->set("swordman/zhizhixiong",1);
}

int ask_yanling()
{

    object ob=this_player();
    if(ob->query("family/master_id") != "master zhizhixiong")
    {
    command("say �ܽ������鲻����ѧ�û���书��");
    return 1;
    }
    if(ob->query("swordman/yanling_perform"))
    { 
    command("say �㲻���ʹ�����? ");
    return 1;
    }
    if(ob->query("family/master_id") == "master zhizhixiong")
    {
    command("say �Ը���Ħ������������������������ȼ���������������������ܣ�");
    ob->set("swordman/yanling_perform",1);
    return 1;
    }
}

int ask_miyan()
{
       object ob=this_player();
       if(ob->query("family/master_id") != "master zhizhixiong")
       {
	command("say û��ʶ��ɱ¾�������ˣ���ô�ܹ���Ϊ��ǿ�Ľ��͡�\n");
       return 1;
       }

           else
           {command("nod");
            command("say ��ǰ�и��������������Ҳ�ʹ�ͬ�������⡣�Ҹ�����
�������һ�еĸ��飬�������������׸��������п��ܳ�Ϊ��ǿ�Ľ��͡�\n");
           command("say �ұ����ȥ��������");
           ob->move("/d/swordman/anshi");
           return 1;
           }
}
