#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIR"��������"NOR, ({ "xiannian laoren", "old man", "man"}) );
	set("attitude", "friendly");
	set("class", "xian");
	set("age", 10000);

	setup();
}

void init()
{       
	object ob;
        if(!clonep()) return;

	::init();

        set("chat_chance", 10);
        set("inquiry", ([
                "name" : "������������Ŷ��\n",
                "here" : "��ط��ҿ���ͷ����Ŷ��\n", 
                "����" : "������������\n",
                "gift" : "�һ���Ҫ�����ء�\n",
         ]) );

         call_out("greeting", 1);
}

void greeting()
{
    switch (random(5))
    {
        case 0:
        message("system",HIR+"�����е���������ŨŨ�Ľ�������,Ҫ������....\n"+NOR,users());
        break;
        case 1:
        message("system",HIM+"���һ����غ��ڿ������������Ĺ⻷....\n"+NOR,users());
        break;
        case 2:
        message("system",HIG+"������Եȫ����ʦף�����µ�һ������������!\n"+NOR,users());
        break;
        case 3:
        message("system",HIY+"���ǼҼ���Բ�ĺ������ˣ��������϶��������Ҹ���Ц��...\n"+NOR,users());
        break;
        case 4:
        message("system",HIR+"�����е���������ŨŨ�Ľ�������,Ҫ������....\n"+NOR,users());
        break;
    }
    call_out("greeting",180);
}

