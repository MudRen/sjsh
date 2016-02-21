#include <ansi.h>
inherit NPC;

void create()
{
    set_name("��", ({"xian"}));
    set("title", "����");
    set("long", "�������");
    set("gender", "����");
    set("age", 35);
    set("str", 40);
    set("per", 40);
    set("attitude", "peaceful");
    set("combat_exp", 10000000);
    set("daoxing", 10000000);
    set("eff_kee", 10000);
    set("eff_sen", 10000);
    set("max_kee", 10000);
    set("max_sen", 10000);
    set("sen", 10000);
    set("kee", 10000);
    set("max_force", 10000);
    set("max_mana", 10000);
    set("mana", 10000);
    set("force", 20000);
    set("force_factor",  500);
    set("mana_factor", 500);
    set_skill("dao", 321 );
    set_skill("spells", 321);
    set_skill("force", 301);
    set_skill("moonshentong", 301);
    set_skill("whip", 301);
    set_skill("staff", 301);
    set_skill("blade", 301);
    set_skill("spear", 301);
    set_skill("hammer", 301);
    set_skill("buddhism", 301);
    set_skill("taiyi", 301);
    set_skill("lotusforce", 301);
    set_skill("wuxiangforce", 301);
           set_skill("moonforce", 301);
    set_skill("stick", 301);
//    set_skill("qianjun-bang", 301);
    set_skill("dodge", 301);
//    set_skill("jindouyun", 301);
    set_skill("unarmed", 301);
//    set_skill("puti-zhi", 301);
    set_skill("parry", 301);
    set_skill("sword", 251);
//    set_skill("liangyi-sword", 251);
      map_skill("force", "wuxiangforce");
      map_skill("spells", "dao");
//      map_skill("stick", "qianjun-bang");
//      map_skill("parry", "qianjun-bang");
//      map_skill("dodge", "jindouyun");
//      map_skill("unarmed", "puti-zhi");

  setup();
    carry_object("/u/shukai/weapon/cc")->wear();
    carry_object("/u/shukai/weapon/cloth")->wear();
    carry_object("/u/shukai/weapon/jia")->wear();
    carry_object("/u/shukai/weapon/pifeng")->wear();
    carry_object("/u/shukai/weapon/shoes")->wear();
    carry_object("/u/shukai/weapon/sword")->wield();
}

int accept_fight(object me)
{
        write("������Ҳ���\n");
        return 0;
}

int recognize_apprentice(object ob, object who)
{
                    object me=this_player();

      if (!(int)ob->query_temp("mark/��"))
             return notify_fail( HIR "������������ɱ���㣡\n" NOR);
      if ((ob->query("combat_exp") < 2000000)
         ||(string)who->query("family/family_name") != "����ɽ���Ƕ�"
         ||(string)who->query("family/family_name") != "�Ϻ�����ɽ"
         ||(string)who->query("family/family_name") != "�¹�"
         ||(string)who->query("family/family_name") != "��ׯ��")
             return notify_fail( HIR "������������ɱ���㣡\n" NOR);
        ob->add_temp("mark/��", -1);
             return 1;
}
