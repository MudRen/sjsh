// �ɽ� by Calvin

#include <ansi.h>
inherit NPC;
string get_ice(object me);
void do_drop(object ob);

void create()
{
        set_name(HIC"�ɽ�"NOR, ({"gan jiang", "gan","jiang", "tianshen"}));
        set("title", HIW"��Ұ˫��"NOR);
        set("gender", "����" );
        set("age", 3000);
        set("per", 30);
set("long", @LONG
��λ�ɽ����Ǵ�˵�е��񽣵�ԭ��
LONG );

        set("class", "yaomo");
        set("combat_exp", 1000000);
        set("daoxing", 1000000);
        set("attitude", "peaceful");
        create_family("��ѩɽ", 1, "��ʦ");
        set_skill("unarmed", 350);
        set_skill("cuixin-zhang", 350);
        set_skill("dodge", 350);
        set_skill("xiaoyaoyou", 350);
        set_skill("parry", 350);
       set_skill("throwing", 350);
        set_skill("sword", 350);
       set_skill("bainiao-jian", 350);
        set_skill("force", 350);   
        set_skill("ningxie-force", 350);
        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("dengxian-dafa", 350);
        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 5000);
        set("max_sen", 5000);
        set("force", 2400);
        set("max_force", 2400);
        set("mana", 2400);
        set("max_mana", 2400);  
        set("force_factor", 100);
        set("mana_factor", 100);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
            (: perform_action, "sword", "chaofeng" :),
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
                (: exert_function, "recover" :),
             }) );
            setup();
      carry_object("/d/zj/armor/jing1")->wear();
      carry_object("/d/zj/weapon/gangjiang")->wield();
}

void attempt_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="��ѩɽ" ){
                if( (int)ob->query("family/generation") < 1  ){
                        command("say ������������Ц���Ҹð�" + RANK_D->query_respect(ob) + "��Ϊʦ����ࡣ\n");
                }
                else if( (int)ob->query("family/generation") ==1  ){
                        command("say �����" + RANK_D->query_rude(ob) + "������ǲ���ˣ�\n");
                }
                else if( (int)ob->query("family/generation") ==2  ){
                        command("blush ");
                        command("say �����" + RANK_D->query_rude(ob) + "������û�취,�ð�...\n");
                        command("recruit " + ob->query("id") );
                }
                else {
                        if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 1000000 ){
                                command(":) ");
                                command("say �ã�" + RANK_D->query_respect(ob) + "��Ȼ�������¾͵ø����������ɲ���͵����\n");
                                command("recruit " + ob->query("id") );
                        }
                        else {
                                command("say ��ô������˻�������?��Զ��ȥ��\n");
                        }
                }
        }

        else{
                command("hmm");
                command("say ��λ" + RANK_D->query_respect(ob) + "���㻹����������ʦ�����������ɡ�\n");
        }
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}

int accept_object(object me, object ob)
{
object sword;
sword=new("/d/zj/weapon/rysj.c");
if((string)ob->query("id")=="moxie sword" )
{
message_vision(HIR"���Ȼ�ܰ�Īа���õ�������,��ô�ҾͰ�����Ѹɽ��������ϲ�,����$N��Ϊ��Ľ֮���!\n"+HIC"˵�Ÿɽ�ͷ��ð����һ������,ûһ����ɽ����ó���һ��������Ե������񽣸���$N!\n\n",me);
sword->move(me);
return 1;
}
else
{
command("say ���ҵ����ҵ���������̫�����ˡ�");
 return 1;
}
}
