//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name(HIY"��ʮ����"NOR, ({"chun shisanniang", "chun", "shisanniang","niang"}));
       set("long",
"��˿�������µĴ���ӡ�����һֻ֩�뾫,����˿�����޳�����,���������յ�ȡ��˿�������¹ⱦ�϶�
����ʦ�ð׾����Ƴ�ˮ�𡣺ܶ���֮��,���и��ºŽ����һ����ӡ�\n");
       set("title", HIM"�һ�����"NOR);
       set("gender", "Ů��");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 22);
	set("int", 30);
       set("max_kee", 2900);
//       set("max_gin", 2600);
       set("max_sen", 2800);
       set("force", 4800);
       set("max_force", 2800);
       set("force_factor", 100);
       set("max_mana", 2000);
       set("mana", 3600);
       set("mana_factor", 100);
       set("combat_exp", 1000000);
       set("daoxing", 1200000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("sword", 150);
       set_skill("spells", 150);
       set_skill("whip", 150);
   set_skill("pansi-dafa", 150);
   set_skill("lanhua-shou", 150);
   set_skill("jiuyin-xinjing", 150);
   set_skill("qingxia-jian", 150);
   set_skill("yueying-wubu", 150);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
//   set("chat_chance_combat", 50);
   set("chat_chance",5);
    set("chat_msg", ({
        HIG"��ʮ��������������:�һ���������ݲ�����\n"NOR,
        HIG"��ʮ��������������:����Ϊ������������һ�����ǲ����мɶ��ĵ�,��Ϊ��̫�����ˡ����ҳ�����ʱ��,����ʶһ����,������
��գ���ϲ���ڶ��߳�û���������и��ºŽ������ʥ������ʶ�������꣬��˿�����һ����ú�����\n"HIC,
        HIG"��ʮ��������������:�ҽд���ʮ��,�ҵ�ְҵ�����˽���鷳,���ǰ�������ɱ�ˣ�\n"NOR,
		HIG"��ʮ��������������:�Դ��뿪��˿��֮����ȥ�����ɳĮ���Һ���֪��ɳĮ�����ʲô���߹���������ʵʲôҲû�У�����
ɳĮ����ɳĮ�������ǿ�ʼ����һ����������������У�ֻ�г�ޣ�ֻ��ɱ�˺ͱ�ɱ��\n"NOR,
		HIG"��ʮ��������������:��ʵ��������ֻ������һ̳��ˮ����Խ��֪���Լ��ǲ����Ѿ����ǵ�ʱ���㷴���ǵ�Խ�����\n"NOR,
		HIG"��ʮ��������������:�Ǹ����ߵĵ���һֱ�����ꡣÿ�����꣬�Ҿͻ�����������һֱ�������Լ���������\n"NOR,
        }));

create_family("��˿��", 2, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
	carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
	carry_object("/d/pansi/obj/qin");
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say ������˿��ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "��������߾Ͱɡ�\n");
           return;}
		 if ( !ob->query_temp("denied_by_bai")){
          command("shake");
        command("say ������Ե����λ" +
RANK_D->query_respect(ob) + "������̱���ȥ�ɡ�\n");
        return;
}
		else
         {
	  command(":D");
	  command("say �ã�" + RANK_D->query_respect(ob) + "Ͷ���ҵ����£��������ģ������ģ�\n");
	  command("recruit " + ob->query("id") );
          ob->set("title", "��˿���һ��������µ���");
          ob->set("class", "yaomo");

     }

}



