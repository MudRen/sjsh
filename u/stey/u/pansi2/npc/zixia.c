
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_tian();
string ask_mieyao();
string ask_cancel();
string avenge();
void create()
{
       set_name(HIM"��ϼ����"NOR, ({"zixia xianzi", "zixia", "xianzi","master"}));
       set("long", "��������˿���Ŀ�ɽ��ʦ,��˵���Ƿ����һ�õ�о��������޵���
��,����˼���½�ռ�˻���ɽһ������,��ɽ����,������ͽ��\n");
       set("title", HIB"��˿����"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "С����");
       set("cor", 30);
       set("per", 30);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 5000);
       set("max_force", 3000);
       set("force_factor", 125);
       set("max_mana", 5000);
       set("mana", 5000);
       set("mana_factor", 250);
       set("combat_exp", 3000000);
	   set("daoxing", 4000000);
       set_skill("literate", 200);
       set_skill("unarmed", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("spells", 200);
       set_skill("whip", 200);
   set_skill("pansi-dafa", 200);
   set_skill("lanhua-shou", 200);
   set_skill("jiuyin-xinjing", 200);
   set_skill("chixin-jian", 200);
   set_skill("yueying-wubu", 200);
   set_skill("yinsuo-jinling", 200);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
/*        set("chat_msg_combat", ({
                (: cast_spell, "mihun" :),
                (: cast_spell, "arrow" :)
        }) );*/
   set("inquiry", ([
          "����" : (: avenge :),
//          "���հ׷�" : (: ask_tian :),
//                           "����": (: ask_mieyao :),
//           "cancel": (: ask_cancel :),
]));
create_family("��˿��", 1, "��");
setup();

        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/pansi/obj/yinsuo.c")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}

void init()
{
add_action("do_kneel","kneel");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="��˿��")
        return ("�㲻�Ǳ��ɵ��ӣ��������Һθɣ�");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("����δ����Ѷ");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("��������������һ��");
    command("say �������ȥΪ�㱧��");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"ֻ����ϼ���������һָ��\n");
    tell_room(where,"�Ĵ��������ڣ���ȥ��"+killer->query("name")+"ץ����\n");
    tell_room(environment(killer),"�������һֻ���ֽ�"+killer->query("name")+"ץ���ˡ�\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"���ӿ�������������\n");
    command("say ���ϣ�����ɱ������˿������");
    this_object()->kill_ob(killer);
    return("��������");
} 
void attempt_apprentice(object ob)
{
   if ( !((string)ob->query("gender")=="Ů��")){
      command("shake");
          command("say ������˿��ֻ��Ůͽ����λ" + RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
      return;
   }

   if ( (string)ob->query("family/family_name")=="��˿��") {
   if (((int)ob->query("combat_exp") < 1000000 )) {
   command("say " + RANK_D->query_respect(ob) +
"�ĵ��в��������Щ��ѧ�ط�������������\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) +
"���Ŭ������������˿��������\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "����ɽ��˿���ɻ���");
	   ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"������ȥѧЩ��������ɡ�\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}
/*
string ask_mieyao()
{
    object who=this_player();

    if((string)who->query("family/family_name")=="��˿��") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("��������,�ι�����?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="��˿��")
     return notify_fail(this_object()->query("name")+"˵�����ֲ��������µ��ӣ����Ҹ�ʲô��\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say ��Ȼ��ˣ������˰ɣ�������û��������񣬵���Щ�ͷ���\n");
	who->add("faith",-5);
        message_vision("$N���ҳ϶��½��ˣ�\n",who);
     }
}

string ask_tian()
{
    object who=this_player();
    if((string)who->query("family/family_name")!="�¹�")
        return ("�㲻�Ǳ��ɵ��ӣ���ô�����������ѩ?");
    if(who->query("faith")<1000)
        return ("���ڱ���������������������Ŭ�����С�");
    who->set_temp("moon_tian",1);
        return ("�����perform tian,Ҳ���Գ���perform mantian��");
}

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}

*/ 