//lost.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIB"�� �� ��"NOR, ({"yintuo luo", "yintuo", "luo","master"}));
       set("long", "ʮ���޵ۣ��׵�ת����\n");
       set("title", HIR"��   ��"NOR);
       set("gender", "����");
       set("age", 9000);
        set("class", "xian");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "��ү��");
       set("per", 30);
       set("int", 30);
       set("max_kee", 6000);
       set("max_gin", 1000);
       set("max_sen", 6000);
       set("force", 20000);
       set("max_force", 10000);
       set("force_factor", 300);
       set("max_mana", 10000);
       set("mana", 20000);
       set("mana_factor", 200);
       set("combat_exp", 10000000);
        
      set_skill("literate", 210);
       set_skill("unarmed", 210);
       set_skill("dodge", 210);
       set_skill("force", 210);
       set_skill("parry", 210);
       set_skill("spells", 210);
       set_skill("blade", 220);
       set_skill("tianlang-blade", 220);
       set_skill("heimofa", 200);
   set_skill("piaoyun-zhang", 180);
   set_skill("shouya-force", 200);
   set_skill("shanbishu", 200);
   
   map_skill("spells", "heimofa");
   map_skill("unarmed", "piaoyun-zhang");
   map_skill("force", "shouya-force");
   map_skill("blade", "tianlang-blade");
   map_skill("parry", "tianlang-blade");
   map_skill("dodge", "shanbishu");
   set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: cast_spell, "zhonglixin" :),
//              (: cast_spell, "suliao" :),
        }) );

create_family("��ս�", 1, "ʦ��");
setup();

//        carry_object("/d/obj/armor/jinjia.c")->wear();
//        carry_object("/d/qujing/wudidong/obj/xueyin.c")->wield();
}

void attempt_apprentice(object ob)
{       ob=this_player();
        if( (string)ob->query("family/family_name")=="��ս�") {
        if ((int)ob->query("combat_exp") < 300000 ) {
        command("say ���ʵս���鲻�㣬" + RANK_D->query_respect(ob) + "������������Ҫ����ᶪ�ҵ����ˡ�\n");
        return;
        }

        if( (int)ob->query_skill("shouya-force", 1) < 100 ) {
        command("say ��λ" + RANK_D->query_respect(ob) + "������������񣬲��ܸ��������С�\n");
        command("sigh");
        return;
        }
        command("smile");
        command("say �ã�" + RANK_D->query_respect(ob) + "�Ժ�һ��Ҫ�ú�Ŭ��������ս�������");
        command("recruit " + ob->query("id") );
        ob->set("title",HIW"ʮ�� �޵�"NOR);
        ob->save();
        return;
        }
        command("shake");
        command("say ����ʲô�ˣ�" + RANK_D->query_respect(ob) + "����ô������\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                  ob->set("class", "tiankongjie");
}

int accept_fight(object me, object ob)
{       ob=this_player();
        command("say ����" + RANK_D->query_rude(ob) + "���ǿ��߰ɡ�\n");
        return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n�����������ڼ���������\n\n", environment());
        command("sigh");
        message("sound", "\n��������ʧ��һ������֮��\n\n", environment());
        }

        destruct(this_object());
}

