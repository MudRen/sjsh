// dizi.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name(HIY"��������"NOR, ({ "master miyan", "miyan", "master" }) );
        set("gender", "����" );
       set("title", HIC"��ȵ��������"NOR);
        set("age", 14);
        set("long", "��ȵ����Ĵ���ӣ���Ȼ��ֻ��ʮ���꣬���ǽ����ϵ���Ϊ
�ѳ�����һ��Ľ��͡�\n");
set("daoxing",500000);
        set("combat_exp",500000);
       set("attitude", "peaceful");
        set("int", 30);
        set("class", "swordman");
       create_family("��������", 3, "����");
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("spells", 80);  
        set_skill("renshu", 80);
        set_skill("literate", 80);
        set_skill("sword", 80);  
        set_skill("huoxin-sword", 80); 
        set_skill("fengyu-piaoxiang", 80);
        set_skill("dodge", 80);  
        set_skill("force", 80);   
        set_skill("guixi-force", 80);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "huoxin-sword");
        map_skill("parry", "huoxin-sword");
        map_skill("dodge", "fengyu-piaoxiang");
        set("per", 30);
        set("max_kee", 800);
        set("max_gin", 800);
        set("max_sen", 800);
        set("force", 2400);
        set("max_force", 1200);
        set("force_factor", 40);
        set("mana", 2400);
        set("max_mana", 1200);
        set("mana_factor", 40);

           set("chat_chance",2);
           set("chat_msg", ({
        HIG"���忴�����еĽ�˵��������һ����Ҫ��Ϊ��������ǿ�Ľ��͡�\n"NOR,
        HIG"������˵������˵��Ȼ�����������������һ���ܴ�����ܡ�\n"NOR,
        HIG"����˵����ʲôʱ���Ŀϴ��ڷ������������Ҿͺ��ˡ�\n"NOR,
        }));

        setup();
        carry_object("/d/obj/cloth/zhanpao")->wear();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
}
void attempt_apprentice(object ob, object me)
{ 
if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +
"�㲻�ʺ����ҵ�����ѧϰ��\n");
   return;
   }
        command("say �ܺã�" + RANK_D->query_respect(ob) +
"������һ��Ŭ������ø�ǿ��\n");
        command("recruit " + ob->query("id") );
           ob->set("title", "��ȵ�������");
        return;
}                               

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "swordman");
}

