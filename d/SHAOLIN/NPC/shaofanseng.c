// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
set_name("�շ�ɮ", ({
		"shaofan seng",
		"shaofan",
		"seng",
	}));
        set("gender", "����" );
        create_family("������", 10, "����");
        set("title", HIG"������"NOR);
        set("age", 23);
	set("class", "bonze");
	set("attitude", "peaceful");
set("long",
		"����λ���ֵ�����ɮ�ˣ��������Ϊ�����շ����˵�Ե�ʣ�����˷����İɡ�\n"
	);
        set("combat_exp", 30);
        setup();
}

