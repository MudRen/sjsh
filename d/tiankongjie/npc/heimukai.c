// kai
inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
        set_name("��Ļ��", ({"heimu kai", "kai"}));
        set("gender", "����" );
        set("age", 18);
        set("title", "�˲���-ҹ����");
        set("long", "�˲���-ҹ�桪��ҹ�������ƹ��� ����е��ˡ�\n");
        set("combat_exp", 700000);
        

        set("attitude", "peaceful");
        set("int", 25);
        set("class", "xian");
        create_family("��ս�", 2,"սʿ");
        
        set("eff_dx", 30000);

       set("nkgain", 200);

        set_skill("unarmed", 120);
        set_skill("dodge", 110);
        set_skill("parry", 120);
        set_skill("spells", 120);  
        set_skill("heimofa", 120);
        set_skill("literate", 80);
        set_skill("blade", 110);
        set_skill("tianlang-blade", 100);
        set_skill("piaoyun-zhang", 100);  
        set_skill("shanbishu", 100);
        set_skill("dodge", 110);  
        set_skill("force", 120);   
         set_skill("shouya-force", 110);

        map_skill("spells", "heimofa");
        map_skill("unarmed", "xiaoyun-zhang");
        map_skill("force", "shouya-force");
        map_skill("blade", "tianlang-blade");
        map_skill("parry", "tianlang-blade");
        map_skill("dodge", "shanbishu");
        map_skill("unarmed", "piaoyun-zhang");


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
      carry_object("d/tiankongjie/obj/lang")->wear();
//        carry_object("/d/tiankongjie/obj/qingfeng")->wield();
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


