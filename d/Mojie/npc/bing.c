// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
        set_name("����", ({"yaobing","bing"}));
        set("gender", "����" );
        set("class", "mo" );
        create_family("ħ��", 4, "����");
        set("age", 30);
        set("long", "ħ���ʿ����\n");
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
        setup();
}

