// worker.c

inherit NPC;
#include <ansi.h>
string ask_go();

void create()
{
        set_name("����ʥʹ", ({"sheng shi","shi"}));
        set("gender", "����" );
        create_family("ħ��", 3, "����");
        set("title","ħ�����");
        set("age", 30);
        set("long", "ħ���������ʥʹ��\n");
        set("combat_exp", 300000);
        set("daoxing", 300000);
        set("max_mana", 1000);
        set("max_force", 1000);
        set_skill("dodge",100);
        set_skill("moshenbu",100);
        set_skill("shifo-zhi",100);
        set_skill("unarmed",100);
        map_skill("dodge","moshenbu");              
        map_skill("unarmed","shifo-zhi");              
        set("attitude", "peaceful");
        set("inquiry", ([
                "ħ��" : (: ask_go :),
                "mojie" : (: ask_go :),
        ]) );
        setup();
}

string ask_go()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        write("����ʥʹ����˵������ʥʹ�������ȥ��\n");
        write("����ʥʹ�������˼���������·���һ��޴�ĺ�������������ȥ.......\n");
        if(!( room = find_object("/d/mojie/chang")) )
            room = load_object("/d/mojie/chang");
        if(objectp(room))
            who->move(room);
        return "\n����ʥʹ�������˼���������·���һ��޴�ĺ�����һ����������ȥ.......\n\n";
}
