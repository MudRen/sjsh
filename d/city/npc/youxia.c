//youxiaer.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string apply_youxia(object me);
string answer_leaving(object me);
int do_yes(string arg);
void do_something();
void do_drink();



void create()
{
        set_name("������", ({ "youxia er","er","xia", "man"}) );
        set("title", HIW"��������"NOR);
        set("gender", "����");
        set("class","youxia");
        set("age", 25);
	  set("per", 20+random(10));
        set("long","ʱ������֮�����أ���������ͷҲ�ɿ�����װ�彣���ꡣ\n\
����Ϊ�����еĽܳ�����书����Ī�⣬ϲ���������壬��ǿ������\n\
���������������ߣ�������ͨ���ռ�����Ϊʦ��\n");
        set("combat_exp", 3500000);
        set("attitude", "heroism");
        set("str", 30);
        set("str", 50);    
        set("max_kee", 1500);
        set("max_gin", 1400);
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 15);
        create_family("��������", 2, "��");
        set_skill("piaoxiang", 180);
        set_skill("sword", 180);
        set_skill("force", 180);
        set_skill("spells", 180);
        set_skill("lingxiyizhi", 180);
        set_skill("tianjijue", 180);
              set_skill("wuji-force", 180);
        set_skill("spells", 180);
        set_skill("literate", 150);
	 set_skill("baiyun-sword", 180);
           set_skill("unarmed", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);
            map_skill("force", "wuji-force");
            map_skill("unarmed", "lingxiyizhi");
            map_skill("spells", "tianjijue");
            map_skill("dodge", "piaoxiang");
	map_skill("sword", "baiyun-sword");
        map_skill("parry", "baiyun-sword");

	set("inquiry", ([
		"name" : "��ֻ������������һλ���Ͷ��ѣ�ϲ���Ĵ��ε����˳ơ����������������ҵ���������������...\n",
		"here" : "����...�����α�����������ʤ����ֻΪ�����˴������\n",
		"����" : (: apply_youxia :),
		"����" : (: apply_youxia :),
		"����" : (: apply_youxia :),
		"����" : (: apply_youxia :),
		"leave" : (: answer_leaving :),
		"�뿪" : (: answer_leaving :),
	]) );
setup();

	add_money("gold", 5);
        carry_object("/d/youxia/obj/xiakesword")->wield();
        carry_object("/d/youxia/obj/bai")->wear();
              
}




void init()
{
        object ob;

        ::init();
      set("chat_chance", 10);
     add_action("do_yes", "yes");
        set("chat_msg", ({
            "������������Ц��Ц��\n",
(: do_drink :),
            "�������������´������㼸�ۣ��������ǲ�м��\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"����������...�����α�����������ʤ����
ֻΪ�����˴������\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"��������Ҫ���Ҵ�������,�ҵĹ�����Զ����\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"�������ֻ������������һλ���Ͷ��ѣ�ϲ���Ĵ��ε���\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"��Թ������Ҫ��Ϊ��ֻ���ǿ��������յĸ��ӵ��ˣ��������һ����ģ�\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"ߺ�ȵ�����Ϊһ������,Ϊ�˴���һ��Ҫ�������壡\n",
(: do_drink :),

            (: random_move :),
            (: random_move :),
            (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
"������������Ц��Ц��\n",
(: do_drink :),
            "�������������´������㼸�ۣ��������ǲ�м��\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"����������...�����α�����������ʤ����
ֻΪ�����˴������\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"��������Ҫ���Ҵ�������,�ҵĹ�����Զ����\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"�������ֻ������������һλ���Ͷ��ѣ�ϲ���Ĵ��ε���\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"��Թ������Ҫ��Ϊ��ֻ���ǿ��������յĸ��ӵ��ˣ��������һ����ģ�\n",
(: do_drink :),

            "�������������е�"HIW"����������"NOR"ߺ�ȵ�����Ϊһ������,Ϊ�˴���һ��Ҫ�������壡\n",
(: do_drink :),

            (: random_move :),
            (: random_move :),
            (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),
                     (: random_move :),       
        }) );
}

void do_drink()
{
    object *list, ob;
    int i, can_drink;
    if ((int)this_object()->query("water") >= 380) return;
    list = all_inventory(this_object());
    i = sizeof(list);
    can_drink = 0;
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    }
    if (can_drink) {
        command("drink "+(string)ob->query("id"));
        if ((int)ob->query("liquid/remaining") == 0)
            command("drop "+(string)ob->query("id"));
    }
    else {
        command("sigh");
        command("say ��˵�����Ĺ𻨾�Զ������������Ū����������������");
    }
    return;
}


int accept_object(object who, object ob)
{	object m;
        m=new("/d/youxia/obj/qin.c");
    if ((string)ob->query("liquid/type")=="alcohol")
    {
        if ((int)ob->query("liquid/remaining") == 0)
        {
            command("shake");
            command("say ��磬����Ⱦ�ѽ!�վƴ��ҿɲ�Ҫ������");
            return notify_fail("�������������������õģ���Ҫ��ƿ�ӡ�\n");
        }
        else
                if ( (string)ob->name()=="ţƤ�ƴ�" )
                {
                        command ("frown");
                        command ("say ��ƻ����������Լ��Ȱɡ�");
                        return
notify_fail("����������������������ľơ�\n");
                }
                else
                {
                        command("smile");
                        command("say ��л!");
			if ((int)who->query_temp("mark/������") < 1){
			who->set_temp("mark/������", 1 ); 
			}
                        if(present("qin", this_object())) {
			return 0;
			}
                        who->add_temp("mark/������", 1 );
                        call_out("destroy", 1, ob);
                if ((int)who->query_temp("mark/������") >= 5+random(5))
                        {
command ( "whisper " + who->query("id") + 
" �ҿ���Ҳ��λ��������֮�ˣ�Ҳ��������Ե�����"HIW"������"HIG"���͸���ɡ�"NOR"\n");
				m->move(who);
                                who->set_temp("mark/������", 0 );
				return 1;
                        }
                        return 1;
                }
        }
    }



int accept_fight(object me)

{
             me=this_player();
        message_vision("����������$NЦ��Ц��������������һλ����,���ɸ��´ͽ̣�С�������ˣ�\n", me);
        return 1;
}



         


void do_something()

{
	command(sprintf("bet %d silver", 1+random(5)));
	if(sizeof(filter_array(all_inventory(environment(this_object())), (:userp:))))
	call_out ("do_something", 120);
       
       add_action("do_yes", "yes");	
}

string apply_youxia(object me)
{
        me=this_player();
                if( (int)me->query("age") >= 100 )
			return "���²����ˣ�" + RANK_D->query_respect(me) + "���ǻؼ�Ъ�Űɡ�\n";

		message_vision("����������$Nһ�۾�ϲ������������������,$N��������������һ�������ɲ�������ѽ!\n", me);	
		me->set_temp("youxia_applied", 1);
		return "" + RANK_D->query_respect(me) + "���������˾�����һ����������(yes)\n";
}


string answer_leaving(object me)
{
	me=this_player();
		if( (string)me->query("class") == "youxia" )
			return "��Ȼ�ݵ������¾���һ���������壬��ǿ����Ϊ����Ҫ�뿪����׼!\n";
		else return "" + RANK_D->query_respect(me) + "���������������ˣ��γ����ԡ�\n";
	}



int do_yes(string arg)
{
	object me;

	me=this_player();
	
	if(me->query_temp("youxia_applied")) 
	{
		message_vision("$N������Ҷ�������ˣ���Ը��һ������,׼����Ϊ������ҵ���ܶ�!\n\n", me);
		message_vision("������������$N��ͷ�����úøɣ���Ϊһ������,Ϊ�˴���һ��Ҫ�������壡\n", me);
		me->delete_temp("youxia_applied");
		me->set("class", "youxia");
		return 1;
	}

	return 0;
}


void attempt_apprentice(object ob)
{   ob=this_player();
   if( (string)ob->query("title")=="��ͨ����") {
   if ((int)ob->query("daoxing") < 1000 ) {
     command("say ������Ȼ���������ɣ���û�м���������ܳ�ǿ������" + RANK_D->query_respect(ob) + "���Ǽ�����������Ұɡ�\n");
   return;
   }
   if ((int)ob->query_int() < 25) {
   command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�������������ͽ��,Ҳ��������Ϊ��\n");
   command("sigh");
   return;
   }
   if( (int)ob->query_skill("unarmed", 1) < 10 ) {
   command("say ��λ" + RANK_D->query_respect(ob) + "���˻���֮����ỹ��������ǲ�Ҫ��ǿѧ�ҹ���\n");
   command("sigh");
   return;
   }
        command("say ��Ȼ" + RANK_D->query_respect(ob) +
"���ļ����κ����ɣ�������������Ϊ���ӣ��պ�һ��Ҫ��ǿ������\n");
        command("recruit " + ob->query("id") );
        message("system", HIY"��ͨ����"+this_player()->name()+"���ļ����κ�����,��Ϊһ��������\n"NOR,users());
	return;
   }
        command("shake");
        command("say " + RANK_D->query_respect(ob) + "��Ȼ�Ѿ���������,Ӧȥն����ħ,��ǿ����֮�½������Ǿ����ˣ�\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "youxia");
                ob->set("title", HIW"�� ��"NOR);
}

