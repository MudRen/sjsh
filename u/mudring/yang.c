// zhanggui.c

inherit NPC;
// inherit F_VENDOR_SALE;
//inherit F_DEALER;
int ask_heal();
int ask_me(string);
int ask_yaofang();
#include <ansi.h>

void create()
{
	set_name("����˳", ({"yang zhongshun", "yang", "boss"}));
        set("title", "ҩ���ƹ�");
        set("gender", "����");
        set("age", 37);
        set("long",
            "���ϰ��ǳ��������洫����ҽ����Ȼ���ᣬȴ�����������⡣\n");
        set("kee", 900); 
        set("max_kee", 900);
        set("sen", 200);
        set("max_sen", 200);
        set("combat_exp", 5000000);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set_skill("literate", 70);
        set_skill("unarmed", 60);
        set_skill("dodge", 60);



        set("vendor_goods", ([
        "yao"   :"/d/obj/drug/jinchuang",
        "dan"   :"/d/obj/drug/hunyuandan",
        ]) );

    set("inquiry", ([
	"ҩ��" : (: ask_yaofang :),
        "����": (: ask_heal :),
        "��ҩ" : (: ask_me, "jc-yao" :),
        "������" : (: ask_me, "yx-wan" :),
        "������" : (: ask_me, "yj-dan" :),
        "����ɢ" : (: ask_me, "qx-san" :),
        "��ҩ"   : (: ask_me, "she-yao" :),
        "�ٲݵ�" : (: ask_me, "bc-dan" :),
        "�Ż���¶��" : (: ask_me, "none" :),
        "�����赨ɢ" : (: ask_me, "none" :),
        "�����˵�" : (: ask_me, "none" :),
        "��ʯ�񶴵�" : (: ask_me, "none" :),
        "����ɢ" : (: ask_me, "none" :),
        "������" : (: ask_me, "none" :),
        "���Ʊ�����" : (: ask_me, "none" :),
        "ͨϬ������" : (: ask_me, "none" :),
        "�����ܵ���" : (: ask_me, "none" :),
        ]) );
	setup();
        carry_object("/d/obj/cloth/choupao")->wear();
        add_money("gold", 1);
}



void init()
{	
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			command(query("name")+"Ц�����˵������λ" + 
RANK_D->query_respect(ob)+ "����Ҫ��ʲôҩ��\n");
			break;
		case 1:
			say( query("name")+"Ц����ع��˹��֣�˵������λ" + 
RANK_D->query_respect(ob)+ "����������\n");
			break;
	}
}

int ask_yaofang()
{
	object me = this_player();
    if (!me->query_temp("zg_mark"))
    {
	command("say ���²��ţ�ҽ��ƽƽ��������ʲôҩ����\n");
	    return 1;
    }
	command("say "+RANK_D->query_respect(me)+"Ҫ��ʲôҩ�ķ��ӣ�����˵�ɡ�\n");
	return 1;
}


int ask_heal()
{
//        �˴���û������ûʱ���ˣ�mudring���æ�ɣ����ϰ඼�ٵ��ˡ�
        object ob;
        ob=this_player();
        if ((int)ob->query("eff_kee") == (int)ob->query("max_kee")
                && (int)ob->query("eff_sen") == (int)ob->query("max_sen"))
        {
                command("?"+ob->query("id"));     
                command("say �����û���ˣ������������ң�\n");
                command("knock"+ob->query("id"));
                return 1;
        }
        else
        {
                message_vision("���ƹ��ó�һ��������������$N���˵Ĳ�λ������Ѩ����$N�о�������ˡ�\n", ob);
                remove_call_out("recover");
                call_out("recover",2,ob);
                return 1;
        }
}
int recover(object ob)
{
        ob->set("eff_kee", (int)ob->query("max_kee"));
        ob->set("eff_sen", (int)ob->query("max_sen"));  
        message_vision("һ����Ĺ����ȥ�ˣ�����������Ѿ�����Ȭ���ˡ�\n",ob);
        command("say �����ն�,��С�ĵĻ����´����û��ô�����ˡ�\n");
        command("pat"+ob->query("id"));
        return 1;
}

int ask_me(string name)
{
	object me = this_player();
	string myid;
	myid = me->query("id");

        if (!me->query_temp("zg_mark"))
        {
        	
command("say "+RANK_D->query_respect(me)+"Ҫ��ʲôҩ����˵��������ҩ�������\n");
			return 1;
		}
		
        if ( name == "none" ) 
		{
			command("doubt "+query("id"));
			command ("say �����������������ҿ�ʵ�ڲ�֪���ˡ�\n");
			return 1;
		}
		
		
		if (name == "jc-yao")
		{
			switch (random(5))
			{
				case 0:
	                command("whisper " + myid + " " + "������Ǯ������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 1:
	                command("whisper " + myid + " " + "�������İ����������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 2:
	                command("whisper " + myid + " " + "����������������һǮ���������һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 3:
	                command("whisper " + myid + " " + "������Ǯ�ӷ�����Ǯ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
				case 4:
	                command("whisper " + myid + " " + "��������������һǮ���ټӷ���һǮ����ˮ�尾�Ϳ��Ƴ�һ����ҩ��");
					break;
			}
		}
		
        if (name == "yx-wan")
        {
	    	command("whisper " + myid + " " + "����һǮ��������һ�����չ�һǮ����ˮ�尾�Ϳ��Ƴɡ�");
		}
        
        if (name == "yj-dan")
        {
	    	command("whisper " + myid + " " + "��Ҷһ�ţ��չ�һǮ����ˮ���ɾͿ��Ƴɡ�");
		}
        	
        if (name == "qx-san")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "�ۻ�һǮ���԰Ͷ�Ϊ��к������ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "�չ���Ǯ���԰Ͷ�Ϊ��к������ˮ���ɾͿ��Ƴɡ�");
					break;
			}
		}
        
        if (name == "she-yao")
        {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "ţ��һǮ���ۻ�һǮ����ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "ţ��һǮ���չ���Ǯ����ˮ���ɾͿ��Ƴɡ�");
					break;
			}
		}
 
        if (name == "bc-dan")
       {
			switch (random(2))
			{
				case 0:
	                command("whisper " + myid + " " + "�غ컨һǮ��������Ǯ����ˮ���ɾͿ��Ƴɡ�");
					break;
				case 1:
	                command("whisper " + myid + " " + "�غ컨һǮ����ɽ��һֻ����ˮ�������ͼ��ɡ�");
					break;
			}
		}
 	me->delete_temp("zg_mark");
 	return 1;
 }

int accept_object(object who, object ob)
{
	int i;
	if ( ob->query("money_id") )
    {
    	if ( ob->value() >= 100 )
        {
			
command 
("say �ȳ�"+RANK_D->query_respect(who)+"�ؽ�֮�ݣ��к����ʾ���˵��������֪�޲��ԣ����޲�����\n");
           	who->set_temp("zg_mark",1);
			return 1;
		}

		command(":)");
		return 1;
	}

	return 0;
}		

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }
        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
