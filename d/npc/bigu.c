#include <ansi.h>
inherit NPC;
inherit F_MASTER;
int ask_tianxiang();
void create()
{
       set_name(WHT"�ȹ���ʮ��"NOR, ({"master bigu", "bigu","master"}));
       set("long",
"������ǿ�Ľ��ͣ����ڲ�Ը����������ķ�����һ������������
�������Ӱ�����\n");
       set("title", WHT"��ʿ"NOR);
       set("gender", "����");
       set("age", 45);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 8000);
       set("max_sen", 8000);
       set("force", 8000);
       set("max_force", 5000);
       set("force_factor", 100);
       set("max_mana", 5000);
       set("mana", 8000);
       set("mana_factor", 100);
       set("combat_exp", 5000000);
       set("daoxing", 4000000);
           set("inquiry", ([
	"��������"     : (: ask_tianxiang :),
             ]) );
       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 400);
       set_skill("force", 340);
       set_skill("parry", 400);
       set_skill("sword", 400);
       set_skill("spells", 340);
       set_skill("kongshoudao", 300);
   set_skill("renshu", 340);
   set_skill("guixi-force", 340);
   set_skill("feitian-sword", 400);
   set_skill("fengyu-piaoxiang", 400);
   map_skill("spells", "renshu");
   map_skill("unarmed", "kongshoudao");
   map_skill("force", "guixi-force");
   map_skill("sword", "feitian-sword");
   map_skill("parry", "feitian-sword");
   map_skill("dodge", "fengyu-piaoxiang");

create_family("��������", 1, "����");
setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
	carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}

void attempt_apprentice(object me)
{ 
    if (me->query("family/master_id") != "master jianxin")
  {
	command("shake");
	command("say �ҵķ��������������������ˣ����»�����ذɡ�");
	return;
  }
 if ( me->query("int") <25){
	command("shake");
	command("say ���µ����ʲ����ʺ���������ѧϰ������������ذɡ�\n");
	return;
   }
if ( me->query("kar") <25){
	command("shake");
	command("say ���µ����ʲ����ʺ���������ѧϰ������������ذɡ�\n");
	return;
   }
  if (me->query("swordman/qiecuo_bigu")==1 )
  {
	command("say �����������ʦ�Ļ��ᣬ��ϧ��û�ܰ���ס��");
	return;
  }

  if (me->query("swordman/win_bigu")!=1 )
  {
	command("say �ҿ��Ը���һ�λ��ᣬ�������д�(qiecuo)һ����
������������ܻ�����һ�£��Ҿ�����Ϊͽ��");
            me->set_temp("swordman/qiecuo_bigu",1);
	return;
  }

  command("nod");
  command("bigman bigu");
  command("say �������ҵ�һ�����Լ̳��ҷ����������Ĵ����ˡ�\n");
  command("recruit " + me->query("id") );
  return;
}

int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
       ob->set("title", WHT"��������������"NOR);
    ob->set("class", "swordman");
}

void init()
{
  object ob;
  ::init();
  add_action("do_qiecuo", "qiecuo");
  add_action("do_queding", "queding");
}

int do_qiecuo()
{
    mapping guild;
    int skee,dkee;
    object me,target;
       me=this_player();
       target=this_object();
       skee=target->query("kee");
    if (!me->query_temp("swordman/qiecuo_bigu"))
       return 0;
       me->delete_temp("swordman/qiecuo_bigu");
     if (me->query("swordman/win_bigu")==1 )
      {
        command("say ���Ѿ��д���ˣ�û��Ҫ���ˡ�");
        return 1;
       }
         if(me->query("swordman/qiecuo_bigu")!=1)
        {
        say("\n�ȹ���ʮ�ɵ�����һ�У�������\n");     
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n�ȹ���ʮ�ɵ����ڶ��У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));
     say("\n�ȹ���ʮ�ɵ��������У�������\n");
     COMBAT_D->do_attack(me,target,me->query_temp("weapon"));

	 dkee=target->query("kee");
          if(!(dkee<skee)) 
	 {say("\n�ȹ���ʮ�ɵ��������ѹ����ܿ�ϧ����û�ܰ���ס��λ��ᣡ\n");
	 me->set("swordman/qiecuo_bigu",1);
              }
	 else
	 { say("\n�ȹ���ʮ��˵����������ʲ����Ҿ�����Ϊͽ��\n");
	  me->set("swordman/win_bigu",1);}
            return 1;
	 }

        say("�ȹ���ʮ��˵�������Ѿ��������д�Ļ��ᣬ�ܿ�ϧ��û�ܰ���ס��\n");
        return 1;
}

int ask_tianxiang()
{  
  object ob=this_player();
   if (ob->query("family/master_id")!="master bigu" )
  {
	command("say �㲻���ҵ��ӣ��޷�ѧ��[��������]��");
	return 1;
   }
   if (ob->query("swordman/tianxiang_perform")==1 )
  {
	command("say �㲻���Ѿ�ѧ����[��������]��");
	return 1;
   }

    else
     {
        command("say Ҫ��ѧ��[��������]���������ס[��ͷ����]��һ����
��ȷ��Ҫѧ��queding����");
      this_player()->add_temp("swordman/ask_tianxiang",1);
        return 1;
      }
}


int do_queding()
{
    mapping guild;
    object me,target,ob;
    int extra;
    me=this_player();
    target=this_object();
    extra = target->query_skill("feitian-sword",1);
    if (!me->query_temp("swordman/ask_tianxiang"))
    return 0;
    me->delete_temp("swordman/ask_tianxiang");
    command("say С���ˣ�");
        if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "sword")
     {
	destruct(ob);
	ob=new("/d/obj/weapon/sword/qingfeng");
	ob->move(target);
	command("wield sword");
    }
	target->add_temp("apply/attack",extra);
	target->add_temp("apply/damage",extra);
	message_vision(  WHT"\n\n$N"+WHT"�ӳ������������еľ�����ص�һʽ�������ţ�ͷ��������������"NOR"\n\n" NOR,target,me);
       message_vision(YEL  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me,query_temp("weapon"));
        message_vision( HIC  "\nˮ������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIW  "\nľ������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIG  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIM  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIR  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(HIB  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
       message_vision(MAG  "\n��������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
        message_vision(RED  "\n��ͷ������" NOR,me,target);
    COMBAT_D->do_attack(target, me, query_temp("weapon"));
           if (me->query("eff_kee")<0 || !living(target))  
         {	command("sigh");
	  return 1;
         }
    command("haha");
    command("say �������ұȹ���ʮ�ɵ��̳�����ͽ�ܡ�");
    message_vision(RED  "\n��������[��ͷ����]����һ����˲�䣬��ͻȻ������[��������]��\n\n" NOR,me);
    me->set("swordman/tianxiang_perform",1);
    return 1;
}