// lost.c

inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("����", ({"li jia", "li"}));
        set("gender", "����" );
        set("age", 18);
        set("title", "�˲���-��¥����");
        set("long", "�˲���-��¥�ޡ�����¥�������ƹܻ��� ����е��ˡ�\n");
        set("combat_exp", 700000);

        set("attitude", "peaceful");
        set("int", 25);
        set("class", "xian");
        create_family("��ս�", 2,"սʿ");
        
        set("eff_dx", 30000);

       set("nkgain", 200);

        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("spells", 100);  
        set_skill("baimofa", 100);
        set_skill("literate", 100);
        set_skill("throwing", 100);  
        set_skill("feiyu", 100);
        set_skill("piaoyun-zhang", 100);  
        set_skill("shanbishu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("mtl-force", 100);

        map_skill("spells", "baimofa");
        map_skill("unarmed", "piaoyun-zhang");
        map_skill("force", "mtl-force");
        map_skill("throwing", "feiyu");
        map_skill("dodge", "shanbishu");


        set("per", 30);
        set("max_kee", 3000);
        set("max_gin", 3000);
        set("max_sen", 3000);
        set("force", 6000);
        set("max_force", 3000);
        set("force_factor", 100);
        set("mana", 6000);
        set("max_mana", 3000);
        set("mana_factor", 100);

        setup();
        carry_object("d/tiankongjie/obj/fenghuang")->wear();
        carry_object("/d/tiankongjie/obj/weapon/feiyu")->wield();
}
void attempt_apprentice(object ob, object me)
{
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"���Ŭ�������ձض��гɡ�\n");
        command("recruit " + ob->query("id") );
        ob->set("title",HIW"�˲�����ͽ"NOR);
        ob->save();
        return;
}               

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                   ob->set("class", "tiankongjie");
}


