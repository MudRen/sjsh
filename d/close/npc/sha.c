//ɳ��
//by Calvin and Leox ��ͬ����
//��Ȩ����,δ�����!���÷�¼

inherit NPC;
#include <ansi.h>

void create()
{
          set_name(HIC"ɳ��"NOR, ({"sha wujing","sha","wujing","heshang"}));
        set("title", HIY"�����޺�"NOR);
          set("long","�����Ǿ����󽫣�����һ�ʧ�ִ��Ʋ���յ�����ᵽ�½硣\n");
        set("class", "tianpeng");
        create_family("����Ԫ˧��", 2, "����");
          set("gender", "����");
          set("age", 50);
          set("per",30);        
          set("combat_exp", 1800000);
          set("daoxing",1800000);
          set("per", 30);
          set("str", 30);
          set("max_kee", 2000);
          set("kee",2000);
          set("force_factor",100);
          set("max_sen", 2000);
          set("sen",2000);
          set("force", 5000);
          set("max_force", 2500);
          set("max_mana", 2500);
          set("mana", 5000);
          set_skill("unarmed", 220);
          set_skill("dodge", 220);
          set_skill("force", 220);
          set_skill("parry", 220);
          set_skill("staff", 220);
          set_skill("spells", 220);
//          map_skill("spells", "buddhism");

         setup();
        carry_object("/d/qujing/liusha/obj/staff")->wield();
}

void attempt_apprentice(object ob)
{

        if( (string)ob->query("family/family_name")=="����Ԫ˧��" ){
                if( (int)ob->query("family/generation") < 2  ){
                        command("say ��,�㶺������Ϻ��а�!�Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ���ǡ�\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("say �����" + RANK_D->query_rude(ob) + "������ǲ��ɽ���ˣ�\n");
                }
                else if( (int)ob->query("family/generation") ==4  ){
                        command("blush ");
                        command("say �����" + RANK_D->query_rude(ob) + "����������Ը��,��ʱ������ͷ��...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 800000 ){
                                command(":) ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ�������¾͵ø����������ɲ���͵����\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say �㻹�����������������Űɡ�\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���㻹�������������������ɡ�\n");
        }

        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "tianpeng");
}
