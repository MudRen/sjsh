inherit NPC;
inherit F_MASTER;
int ask_wu();
#include <ansi.h>
void create()
{
       set_name(HIY"������˾"NOR, ({"master zongsi", "zongsi","master","chongtian"}));
       set("long",
"Ļĩ��ǿ����������׫�����ǿ���ͣ���ŵ������꣬�����죬
����ǳ���������ȫ���츳�Ӷ������еĽ���\n");
       set("title", HIC""NOR);
       set("gender", "����");
       set("age", 35);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 40);
	set("int", 40);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("force", 6000);
       set("max_force", 4000);
       set("force_factor", 200);
       set("max_mana", 4000);
       set("mana", 6000);
       set("mana_factor", 200);
       set("combat_exp", 3000000);
       set("daoxing", 3000000);
        set("inquiry", ([
                 "��ʽ" : (: ask_wu :),
                 "wu" : (: ask_wu :),
         ]) );

       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 300);
       set_skill("spells", 300);
   set_skill("renshu", 300);
   set_skill("guixi-force", 300);
   set_skill("lixin-sword", 300);
   set_skill("fengyu-piaoxiang", 300);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "lixin-sword");
   map_skill("parry", "lixin-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("��������", 1, "����");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"�㲻�ʺ����ҵ�����ѧϰ��\n");
   return;
   }

         if ( (int)ob->query("combat_exp") <1000000){
           command("shake");
 command("say " + RANK_D->query_respect(ob) +
"�����ȴ�û���������\n");
 return;}
        if ( (int)ob->query("int") <25){
	  command("shake");
	command("say �����¿���λ" +
RANK_D->query_respect(ob) + "���츳�����ʺ���������ѧϰ��������������߾Ͱɡ�\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;}

        if ( (int)ob->query("per") <25){
	  command("shake");
	command("say �����¿���λ" +
RANK_D->query_respect(ob) + "���츳�����ʺ���������ѧϰ��������������߾Ͱɡ�\n");
  ob->set_temp("denied_by_zogncilang",1);
	return;
   }
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ��������׫���������������ȥ��\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "���;���");
	   ob->set("class", "swordman");
   return;
   }
int ask_wu()
{

    object ob=this_player();
    if(ob->query("family/master_name") != HIY"������˾"NOR)
    {
    command("say �㲻�����µ��ӣ�ˡ���²��ܽ���ͻ����ʽ�����ܸ����㡣");
    return 1;
    }
    if(ob->query("combat_exp") < 1500000 ) 
    {
    command("say �����Ϊ�������޷���ᵽ��ͻ����ʽ�����ܡ�");
    return 1;
    }
    if(ob->query("swordman/wu_perform"))
    { 
    command("say �㲻���ʹ�����? ");
    return 1;
    }
    if(ob->query("family/master_name") == HIY"������˾"NOR)
    {
    command("say ������ʤ���У��������ͻ����ʽ�����ܣ�");
    ob->set("swordman/wu_perform",1);
    return 1;
    }
}
