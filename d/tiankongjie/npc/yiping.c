// lost


inherit NPC;
#include <ansi.h>
inherit F_MASTER;
string ask_chuxian();
string ask_cancel();
void create()
{
        set_name("�ո�һƽ", ({"rigao yiping", "yiping"}));
        set("gender", "����" );
        set("age", 18);
        set("title", "�˲���-������");
        set("long", "�˲���-�����ޡ������������ƹ�ʨ�� ����е��ˡ�\n");
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
        set_skill("sword", 100);  
        set_skill("xiaoyao-sword", 100);
        set_skill("piaoyun-zhang", 100);  
        set_skill("shanbishu", 100);
        set_skill("dodge", 100);  
        set_skill("force", 100);   
        set_skill("mtl-force", 120);

        map_skill("spells", "baimofa");
        map_skill("unarmed", "piaoyun-zhang");
        map_skill("force", "mtl-force");
        map_skill("sword", "xiaoyao-sword");
        map_skill("parry", "xiaoyao-sword");
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

    set("inquiry", ([
     "����" : (:ask_chuxian:),
   "cancel": (:ask_cancel:),
   "����": (:ask_cancel:),
    ]));
        setup();
        carry_object("d/tiankongjie/obj/shizi")->wear();
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

string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("û�õĶ�����");
}
else
{
     return ("���������𣿣�");
}
}
string ask_chuxian()
{
   object me=this_player();
   
   if(me->query("family/family_name")!="��ս�")
      return ("�㲻�Ǳ�������!");

   command("pat "+me->query("id"));
   command("say �úú�,��ȥ��أ�");
   return "/d/obj/mieyao"->query_yao(me);
}
