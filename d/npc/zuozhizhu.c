//cheng yaojin, updated 5/7/97, pickle

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int ask_baishi();

void create()
{
  set_name(HIC"������֮��"NOR, ({ "master xiangle", "xiangle", "zuozhizhu", "master"}));
  set("title", HIY"���ר��"NOR);
  set("gender", "����");
  set("age", 25);
  set("str", 60);
  set("per", 20);
  set("cor", 40);
  set("cps", 35);
  set("long","
Ļĩʱ�౨�ӵ�Ԥ����Ա���ڶӳ�������������ά����������
�󣬱㿪ʼ���Դ��Ϊ�����������ġ��·�������ġ�����
�Լ���ն�󡱵ĳƺţ������е����ŷ�ɥ����
");
  set("combat_exp", 2500000);
  set("daoxing", 2000000);

  set_skill("unarmed", 240);
  set_skill("kongshoudao", 240);
  set_skill("force", 180);
  set_skill("guixi-force", 180);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("spells", 140);
  set_skill("renshu", 140);
  set_skill("sword", 140);
  set_skill("fengyu-piaoxiang", 180);
  map_skill("force", "guixi-force");
  map_skill("spells", "renshu");  
  map_skill("unarmed", "kongshoudao");
  map_skill("dodge", "fengyu-piaoxiang");
  set("max_sen", 2000);
  set("max_kee", 2000);
  set("force", 5000); 
  set("max_force", 2500);
  set("force_factor", 150);
  set("max_mana", 3000);
  set("mana", 1500);
  set("mana_factor", 100);
  set("inquiry", ([
	"��ʦ"     : (: ask_baishi :),
]) );

  create_family("��������", 2, "����");
  set("chat_chance", 2);
  set("chat_msg", ({ (: random_move :) }));

  setup();
  carry_object("/d/obj/cloth/zhanpao")->wear();
}


int ask_baishi()
{  
  object ob=this_player();
   if (ob->query("family/master_id")=="master xiangle" )
  {
	command("say ���Ѿ����ҵ����ˣ����ʸ�ʲô��");
	return 1;
   }
    else
     {
   command("say ������ܶ�������У��Ҿ�����Ϊͽ�����Ը�����ԣ�(try)��");
      this_player()->add_temp("swordman/ask_zuozhizhu",1);
   return 1;
      }
}

void init()
{
    object ob;
    ::init();
        add_action("do_agree", "try");
}

int do_agree()
{
    mapping guild;
    int skee,dkee;
    object me,target;
	
	me=this_player();
	target=this_object();
	skee=me->query("kee");
     if (!me->query_temp("swordman/ask_zuozhizhu"))
       return 0;
       me->delete_temp("swordman/ask_zuozhizhu");
    if(time() - me->query("swordman/try_zuozhizhu")<72000)
   {
          command("say ���Ǹմ��꣬�������ٴ�");
          return 1;
   }
  if (me->query_temp("swordman/zuozhizhu")==1 )
  {
	command("say ������û��Ȥ�����");
	return 1;
   }
    command("say �������е��ӣ�");
    me->set("swordman/try_zuozhizhu",time());
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
     || !present(me, environment()))
    {
	command("kick");
       command("say �㻹�ǻ�ȥ����ϰ��ϰ�ĺá�");
	return 1;
    }
    command("say �����ٽ����п�����");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say �ܱܹ���һ�����㲻��");
	return 1;
    }
    command("say ���������ܵĹ���ͦ����ģ�");
    COMBAT_D->do_attack(target, me);
    dkee=me->query("kee");
    if((dkee<skee) 
    || !present(me, environment()))
    {
	command("say ��ϧ��Ͳ��������һ���ˡ�");
	return 1;
    }
    me->add_temp("swordman/zuozhizhu", 1);
    command("say ��Ȼ�����֡�");
    command("say �ܾ�û������ʹ��Ĵ�һ���ˣ��ҾͰѿ��ֵ����ڸ���ɡ�");
     command("haha");
     command("say �ú�Ŭ����\n");
     command("recruit " + me->query("id") );
    return 1;
}

int accept_fight(object me)
{
  command("say �����Һܾ�û�����ˡ�");
  return 1;
}

void attempt_apprentice(object me)
{
  if (me->query_temp("swordman/zuozhizhu")!=1)
  {
   command("say �ҵĿ��ֵ��ɲ���㴫�����ˡ�");
   return 0;
  }
  command("haha");
  command("say �ú�Ŭ����\n");
  command("recruit " + me->query("id") );
    me->delete_temp("swordman/zuozhizhu");
  return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
  ob->set("class", "swordman");
}
�
