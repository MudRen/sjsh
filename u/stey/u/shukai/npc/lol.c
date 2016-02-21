//��������

#include <ansi.h>
inherit NPC;

// from drooler file, some global variables

/*string *rnd_say = ({
	"��ѩɽ�ɵ��Ӹ��������ޱȣ������޵У�",
	"���¡����¡�����",
	"ɱ��������£�������������������",
	"���Ƕ�Ҫ�ú���������Ҫ������������һƬ���ģ�",
	"��Һã�",
}); */

varargs void drool(string msg, string who);

/************************************************************/
void create()
{
    set_name("����", ({"lol"}));
	set("gender", "����" );
	set("age", 23);
    set("per", 25);

    set("long", "û������");
    set("class", "fighter");
    set("combat_exp", 40000000);
  set("daoxing", 40000000);

	set("attitude", "peaceful");
       create_family("��������", 9999, "����");
    set_skill("unarmed", 600);
set_skill("dragonfight", 600);
      set_skill("dodge", 600);
      set_skill("xiaoyaoyou", 600);
      set_skill("hammer", 600);
      set_skill("huntian-hammer", 600);
      set_skill("force", 600);
      set_skill("dragonforce", 600);
      set_skill("spells", 600);
      set_skill("seashentong", 600);
      set_skill("literate", 1);
    map_skill("spells", "seashentong");
    map_skill("force", "dragonforce");
    map_skill("dodge", "xiaoyaoyou");
    map_skill("unarmed", "dragonfight");
    map_skill("hammer", "huntian-hammer");
    map_skill("parry", "huntian-hammer");

    set("max_kee", 4000);
    set("max_sen", 6000);
    set("force", 16000);
    set("max_force", 8000);
    set("mana", 24000);
    set("max_mana", 12000);
    set("force_factor", 450);
    set("mana_factor", 601);

	// the following are from the drooler
    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
	(: cast_spell, "breathe" :),

	(: cast_spell, "freez" :),
	(: cast_spell, "hufa" :),
 (: perform_action, "unarmed", "sheshen" :),
 (: perform_action, "unarmed", "leidong" :),
//        (: drool :),
	}) );
	setup();
	if( clonep() ) CHANNEL_D->register_relay_channel("chat");

}

/************************************************************/

// things involving the menpai: apprentice, ......

void attempt_apprentice(object ob)
{

    if( (string)ob->query("family/family_name")=="MMM" ){
        if( (int)ob->query("family/generation") < 9999  ){
			command("say ���ң����ҡ��Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
		}
        else if( (int)ob->query("family/generation") ==9999  ){
			command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ү���ˣ�\n");
		}
		else {
			command(":D");
			command("say �����" + RANK_D->query_rude(ob) + "��͸�������Ϊʦ�����Ǹ���ʦ��ʲô������...\n");
			command("recruit " + ob->query("id") );
                        ob->set("title", "��������");
                    ob->set("class", "dragon");
	}
	}

	else{
        command("noway ");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
                    ob->set("class", "dragon");
}

/************************************************************/

// the following copies some functions of the drooler
// from /obj/example/drooler to allow the yingwu to
// repeat what a human says, as a ����'s nature is.

int add_phrase(string who, string msg)
{
	msg = replace_string(msg, "?", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "!", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "��", "");
	msg = replace_string(msg, "Ү", "");
	msg = replace_string(msg, "��", "");

	if( msg!="" ) {
		add("memory/" + who, ({ msg }));
		return 1;
	} else return 0;
}

string make_reply()
{
}

void relay_channel(object ob, string channel, string msg)
{
	string who, phrase;

	if( !userp(ob) || (channel != "chat") ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_say(object ob, string msg)
{
	string who, phrase;

	if( !userp(ob) ) return;
	who = ob->query("name");

	// Don't process our own speech.
	if( ob==this_object() ) return;

	if( add_phrase(who, msg) &&	random(10) > 4 )
		drool(msg, ob->query("name"));
}

void relay_emote(object ob, string verb)
{
	if( !userp(ob) ) return;

	switch(verb) {
	case "kick":
		if( random(10)<5 ) {
			command("say �����ַ�����...\n");
		}
		break;
	case "pat":
		if( random(10)<5 ) {
			command("say �����ģ�������үү�Ұ����צ�Ӷ�������\n");
		}
		break;
	default:
		if( random(10)<5 )
			command(verb + " " + ob->query("id"));
		else
			drool();
	}
}

varargs void drool(string msg, string who)
{
	mapping mem;
	string *ob;

	mem = query("memory");
	if( !mapp(mem) ) return;

	if( !msg || !who) {
		ob = keys(mem);
		who = ob[random(sizeof(ob))];
		msg = mem[who][random(sizeof(mem[who]))];
	}

	if( (strsrch(msg, "Ϊʲô") >= 0) ) {
		if( sscanf(msg, "%*s�ʲô%s", msg)==2 ) msg = "Ϊʲô" + msg;
		switch(random(8)) {
		case 0: command("say " + who + "��������������"); break;
		case 1: command("say ����" + msg + "����"); break;
		case 2: command("say ������"); drool(); break;
		case 3: command("say ����������"); break;
		case 4: command("say " + who + "��֪���������Ĵ𰸶�����ô��Ҫ��"); break;
		case 5: command("say " + msg + "��"); break;
		case 6: command("say " + who + "���ܲ���˵���һ�㣿"); break;
		case 7: command("say " + who + "���Ҳ������ʵ����⡣"); break;
		}
	}
	else if( (strsrch(msg, "��") >= 0)
	||	(strsrch(msg, "drooler") >= 0)
	||	(strsrch(msg, "Drooler") >= 0)) {
		if( sscanf(msg, "%*s�%s", msg) == 2 ) msg = "��" + msg;
		msg = replace_string(msg, "��", "��");
		switch(random(10)) {
		case 0:	command("say " + who + "������˵" + msg + "��");	break;
		case 1:	command("say ��ȷ��" + msg + "��");	break;
		case 2:	command("say " + msg + "������ʲô��ϵ��");	break;
		case 3:	command("say �š���" + who + "˵�ú�"); break;
		case 4:	command("say " + who + "��Ϊʲô��" + msg + "��ô����Ȥ��"); break;
		case 5:	command("say Ϊʲô����Ϊ" + msg + "��"); break;
		case 6:	command("say ��������ɡ�"); drool(); break;
		case 7:	command("say �Ź֣�"); break;
		case 8:	command("say ��һ���ɣ�"); break;
		case 9:	command("say ��������ܡ���"); break;
		}
	}
	else if( (strsrch(msg, "��") >= 0)) {
		if( sscanf(msg, "%*s�%s", msg) == 2 ) msg = "��" + msg;
		msg = replace_string(msg, "��", "��");
		msg = replace_string(msg, "?", "");
		switch(random(8)) {
		case 0:	command("say ����˵" + msg + "��"); break;
		case 1:	command("say ��ģ�" + msg + "��");	break;
		case 2:	command("say ���" + msg + "�����ܰ���ʲôæ��");	break;
		case 3:	command("hmm");	break;
		case 4:	command("say ����Ϊ" + msg + "��"); break;
		case 5:	command("say ����ͬ��"); break;
		case 6:	command("say ��˵�ġ�" + msg + "���Ҳ��ܹ�ͬ��"); break;
		case 7:	command("say �йء�" + msg + "���Ļ��⵽��Ϊֹ����"); break;
		}
	} else {
		switch(random(20)) {
			case 0: command("say Ϊʲô˵" + msg + "��"); break;
			case 1: command("say ��" + msg + "����ʲô��˼��"); break;
			case 2: command("say " + msg + "��"); break;
			case 3: command("hehe"); break;
			case 4: command("sister"); break;
			case 5: command("?"); break;
			case 6: command("say ����"); break;
			case 7: command("hmm"); break;
//            case 8: command("say " + rnd_say[random(sizeof(rnd_say))]); break;
			case 9: command("say ����ô֪��" + msg + "��"); break;
			case 10: command("say �ո�" + who + "����˵�ˣ�" + msg); break;
			case 11: command("say �ҵ�Ȼ֪����" + msg); break;
			case 12: command("say Ȼ���أ�"); break;
			case 13: command("say �����"); break;
			case 14: command("say �Ҳ���ô��Ϊ��"); break;
			default:
				break;
		}
	}
}

void reset()
{
	delete("memory");
}
�
