// ������ by Calvin

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
       set_name(HIB"������"NOR, ({"jiang ziya", "jiang", "ziya","tianshen"}));
       set("long", "�÷�������,�����ר�Ÿ���������ɡ�\n");
       set("title", HIW"�÷���"NOR);
       set("gender", "����");
       set("age", 3000);
      set("attitude", "peaceful");
       set("rank_info/self", "С��");
        set("rank_info/respect", "�÷���������ư�����");
        set("class", "bonze");
        set("str",24);
        set("per",30);
set("max_kee", 5000);
set("max_gin", 5000);
set("max_sen", 5000);
        set("force", 6000);
        set("max_force", 6000);
        set("force_factor", 1000);
        set("max_mana", 6000);
        set("mana", 6000);
        set("mana_factor", 1000);
set("combat_exp", 10000000);
set("daoxing", 10000000);

        set_skill("literate", 350);
        set_skill("spells", 350);
        set_skill("buddhism", 350);
        set_skill("unarmed", 350);
        set_skill("jienan-zhi", 350);
        set_skill("dodge", 350);
        set_skill("lotusmove", 350);
        set_skill("parry", 350);
        set_skill("force", 350);
        set_skill("lotusforce", 350);
        set_skill("staff", 350);
        set_skill("lunhui-zhang", 350);

        map_skill("spells", "buddhism");
        map_skill("unarmed", "jienan-zhi");
        map_skill("dodge", "lotusmove");
        map_skill("force", "lotusforce");
        map_skill("parry", "lunhui-zhang");
        map_skill("staff", "lunhui-zhang");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "bighammer" :),
//              (: perform_staff, "pudu" :),
        }) );
        set("inquiry",([
      "����": "���޵�δ��,�������Եóɰ� ... ..." ]));

        create_family("�Ϻ�����ɽ", 1, "����");
        setup();
        carry_object("/d/zj/armor/fapao")->wear();
        carry_object("/d/zj/weapon/fengshen")->wield();
        carry_object("/d/zj/weapon/zhua")->wield();
}

void attempt_apprentice(object ob)
{
        if (!((string)ob->query("bonze/class") =="bonze" )) {
                command("say �ҷ�����ͨ���" + RANK_D->query_respect(ob) + "�����������������š�\n");
                write("�����ӽ���������δ��ȳ�����Ϊ���졣\n");
                return;
        }
        if (((int)ob->query_skill("buddhism", 1) < 250 )) {
                command("say " + RANK_D->query_respect(ob) + "���ڷ��Ͽ��ޣ������ѳ�������\n");
                return;
        }
        command("xixi" + ob->query("id") );
        command("say �ã�������ҷ��ŵĺõ��ӡ�ֻҪ���Ŭ�����������������\n");
        command("recruit " + ob->query("id") );
        return; 
}
