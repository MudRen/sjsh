// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
set_name("ɨ��ɮ", ({
		"saodi seng",
		"saodi",
		"seng",
	}));
        set("gender", "����" );
        create_family("������", 16, "����");
        set("age", 13);
        set("title", HIG"������"NOR);
set("long",
		"����һλרְ������¥��ܣ��������������ɮ�ˡ�\n"
	);
        set("combat_exp", 200);
        set("attitude", "friendly");
        set_skill("dodge", 10);
        set("per", 30);
        set("max_kee", 150);
        set("max_gin", 150);
        set("max_sen", 150);
        setup();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting()
	&& !this_player()->query("env/invisibility") ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "ɨ��ɮ�������λ" + RANK_D->query_respect(ob) +
"���⼸��Ҳ��֣��ɸɾ����ģ���֪������ð�������������\n");
}

