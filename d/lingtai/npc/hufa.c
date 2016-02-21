// hufa.c

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIW"��������"NOR, ({"hufa zunzhe", "zunzhe"}));
       set("long", "����ɽ�������ߣ����ɴ�С����������֪����\n");
       set("title", HIC"����ɽ���Ƕ�"NOR);
       set("gender", "����");
       set("age", 1000);
       set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "����");
       set("looking", "Ӣ�������������ٷ磬�������Ρ�");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 500);
       set("force_factor", 10);
       set("max_mana", 500);
       set("mana", 1000);
       set("mana_factor", 10);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("dao", 200);
        set_skill("literate", 100);
        set_skill("sword", 100);  
        set_skill("wuying", 200);
        set_skill("fumobashi", 200);  
        set_skill("mizongbu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("wuxiangforce", 200);

        map_skill("spells", "dao");
        map_skill("unarmed", "fumobashi");
        map_skill("force", "wuxiangforce");
        map_skill("sword", "wuying");
        map_skill("parry", "wuying");
        map_skill("dodge", "mizongbu");

	set("inquiry", ([
	"����" : (: expell_me :),
	"leave" : (: expell_me :),
	]) );
	
	create_family("����ɽ���Ƕ�", 1, "����");
	
	setup();
	carry_object("/d/obj/armor/jinjia")->wear();
}
/*
string expell_me(object me)
{       
        me=this_player();
        if((string)me->query("family/family_name")=="����ɽ���Ƕ�") {
                message_vision("�������ߺ��Ӷ���������ǳ�������\n", me);
                me->set_temp("betray", 1);
                message_vision("�������߶�$N�����ţ�С��������˵�������Ļ�(true)��\n", me);
                return ("�������ˣ��������ˣ�\n");
}
        return ("��ʲô�ʣ��Լ���ȥ��\n");
}
void init()
{     add_action("do_true", "true");
}

int do_true(string arg)
{

        if(this_player()->query("family/family_name") != "����ɽ���Ƕ�" )
                return 0;
        if(this_player()->query_temp("betray")) {
                message_vision("$N��������ӽ������Ļ���\n\n", this_player());
                message_vision("��������̾�˿�����������ˣ������ɽ�ɣ�\n", this_player());
                this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
		if( this_player()->query_skill("dao") )
		    this_player()->delete_skill("dao");
		if( this_player()->query_skill("wuxiangforce") )
	            this_player()->delete_skill("wuxiangforce");
                this_player()->add("betray/count", 1);
                this_player()->add("betray/taoist", 1);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "��ͨ����");
                this_player()->set("faith",0);
                this_player()->set_temp("betray", 0);
                this_player()->save();
                message_vision("������������ֽ�$Nһ�ƣ�$N����һ�������򶫶�ȥ ... \n", this_player());
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"������������¼����죬���¸�������\n", ({this_player()}));
                this_player()->unconcious();            
                return 1;
                }
        return 0;
}
*/
void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="����ɽ���Ƕ�") {
	if ((int)ob->query("daoxing") < 1000000 ) {
  	command("say ���ǽ�ħ����֮�����صľ��ǵ��У�" + RANK_D->query_respect(ob) + "������Ŭ��������������\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say ��λ" + RANK_D->query_respect(ob) + "�������ѿ����ۣ���������������������ˣ��Ҳ�ԭ������Ϊͽ�ˣ�\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 40) {
	command("say ��λ" + RANK_D->query_respect(ob) + "����̫�ͣ�����������Ҳ������Ϊ��\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 200 ) {
	command("say ��λ" + RANK_D->query_respect(ob) + "���ҷ�������ỹ�������������Ҳ����Ϊ���ѣ��������գ�\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
        ob->set("class", "taoist");
}

�
