inherit NPC;

#include <ansi.h>

int goto_club();
int give_mark();

void create()
{
	set_name(HIC"������"NOR,({ "chipai ren" , "man" ,"boss" }) );
        set("gender", "����" );
        set("title", HIW"�����ֲ�"NOR);
        set("age", 20);
	set("long", HIW"��������ĳ����ˣ��Ŷ�ʮ��ͷ���Ͱ�������ֲ����������ɫ��\n"NOR+HIM"  ��ask boss about ��̳�� ����ȥ����ɵ���̳��\n"NOR+HIC"  ��ask boss about ���ơ� ����Ҫ������ɵ����\n"NOR);
	set("attitude", "friendly");
        set("inquiry", ([
        "name": "�Ǻǡ�������������ϰ壬����Խ���BOSS����ʲô����������\n",
        "here": "�����ǰ��ɾ��ֲ������㲻֪����\n",
        "club": "�����㻹��û�м���ʲô���ɰɣ��Ҹ��ð��ɼ���ɡ�\n",
        "����": "�����㻹��û�м���ʲô���ɰɣ��Ҹ��ð��ɼ���ɡ�\n",
        "��̳": (:goto_club:),
        "����": (:give_mark:),
        ]));
        setup();
}

void init()
{
	object ob, me;
        me=this_object();
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
	}
	add_action("do_stop", "steal");
	add_action("do_stop", "fight");
	add_action("do_stop", "kill");
	add_action("do_stop", "cast");
	add_action("do_stop", "bian");
	add_action("do_stop", "exert");
	add_action("do_stop", "perform");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) )
        {
        case 0:
        say( name()+"Ц�����˵������λ" +RANK_D->query_respect(ob)+ "������ЪЪ�ţ������Ѱɡ�\n");
        break;
	}
}

int do_stop()
{
        object who = this_player();
        command("kok "+who->query("id"));
        command("say �٣�"+who->query("name")+"�����ǲ����е�ʲô���Ⱑ��Ҫ��Ҫ�Ҵ���ȥ��ҽ����\n");
        return 1;
}

int goto_club()
{
	object who=this_player();
        string club;
        club=who->query("club");
        
        if ( club == 0 )
        {
                command("hehe");
                command("say "+who->query("name")+"������ȥ�Ҹ��Լ�ϲ���İ��ɼ����������˵���̳�ɲ������������˽���İ���\n");
                return 1;
        }
        
        switch ( club )
        {
        	case "�����":
        	command("nod "+who->query("id"));
        	who->move(__DIR__"tianjue/dayuan");
        	break;
                case "���ϸ��¥":
                command("nod "+who->query("id"));
                who->move(__DIR__"qingfeng/qingfenglou");
                break;
                case "����Ů����":
                command("nod "+who->query("id"));
//                who->move(__DIR__"qingfeng/qingfenglou");
                break;

        	
        	case "�����":
        	command("nod "+who->query("id"));
        	who->move(__DIR__"jueqing/dayuan");
        	break;
        	case "���ǹ�":
        	command("nod "+who->query("id"));
        	who->move(__DIR__"wuyou/dayuan");
        	break;

        	default:
        	command("hoho");
                command("say "+who->query("name")+"������ȥ�Ҹ��Լ�ϲ���İ��ɼ����������˵���̳�ɲ������������˽���İ���\n");
                return 1;
        }
	message_vision(who->query("name")+"��"+who->query("club")+"��̳������ȥ��\n");
	return 1;
}

int give_mark()
{
        object who, tianjuepai, jueqingpai,yihuapai,qingfengpai,wuyoupai,chixinpai;
	string club;
        who=this_player();
        club=who->query("club");
        tianjuepai=new("/d/obj/club/tianjue_mark");
        jueqingpai=new("/d/obj/club/jueqing_mark");
        yihuapai=new("/d/obj/club/yihua_mark");
        wuyoupai=new("/d/obj/club/wuyou_mark");
        qingfengpai=new("/d/obj/club/qingfeng_mark");
        chixinpai=new("/d/obj/club/chixin_mark");
        if ( club == 0 )
        {
                command("hehe");
                command("say "+who->query("name")+"��������ñ��˰��ɵ�����Ŷ��\n");
                return 1;
        }
        
        switch ( club )
        {
        	case "�����":
        	command("nod "+who->query("id"));
        	tianjuepai->set("obj_owner",who->query("id"));
        	tianjuepai->move(who);
        	break;
        	
        	case "�����":
        	command("nod "+who->query("id"));
        	jueqingpai->set("obj_owner",who->query("id"));
        	jueqingpai->move(who);
        	break;
        	
                case "���ϸ��¥":
                command("nod "+who->query("id"));
                qingfengpai->set("obj_owner",who->query("id"));
                qingfengpai->move(who);
                break;
                case "����Ů����":
                command("nod "+who->query("id"));
                chixinpai->set("obj_owner",who->query("id"));
                chixinpai->move(who);
                break;
        	case "�ƻ���":
        	command("nod "+who->query("id"));
        	yihuapai->set("obj_owner",who->query("id"));
        	yihuapai->move(who);
        	break;
        	case "���ǹ�":
        	command("nod "+who->query("id"));
        	wuyoupai->set("obj_owner",who->query("id"));
        	wuyoupai->move(who);
        	break;

        	default:
        	command("hoho");
                command("say "+who->query("name")+"��������ñ��˰��ɵ�����Ŷ��\n");
                return 1;
        }
	message_vision(who->query("name")+"�õ�һ��������\n");
	return 1;
}
