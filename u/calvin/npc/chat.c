// chat_npc.c

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name("������ԵѲʹ", ({"chat girl","chat","girl","princess"}));

        set("long","һ��������Ե�Ŀɰ����ӡ�\n");
       set("gender", "Ů��");
       set("age", 20);
       set("per", 40);
       set("max_kee", 100);
       set("max_sen", 100);
       set("force", 100);
       set("max_force", 100);
       set("force_factor", 0);
       set("max_mana", 100);
       set("mana", 100);
       set("mana_factor",0);
       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge",300);

//        carry_object("/d/obj/cloth/pinkskirt")->wear();
}

//void attempt_apprentice(object ob)
//{
//        command("jump");
//        command("es ������Ե֮����վ 61.150.127.254 6666 ��ӭ��λ��\n");
//        command("xyj ������Ե֮����վ��ҳ http://newxlqy.yeah.net ��ӭ��λ��\n");
//        command("recruit " + ob->query("id") );
//        return;
//}
