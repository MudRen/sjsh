#include <ansi.h>
inherit NPC;

int give_me(object ob);
int create_guo(object ob);

void create()
{
       set_name(HIG"��Ҷ"NOR, ({"lv ye", "ye"}));

set("long","��Ҷ�����顣\n");
       set("gender", "Ů��");
       set("age", 18);
        set("title", HIR"��Ҷ������"NOR);
        set("per", 50);
        set("str", 35);
        set("con", 30);
        set("int", 20);
        set("max_kee", 1500);
        set("max_sen", 1000);
       set("attitude", "heroism");
       set("combat_exp", 700000);
  set("daoxing", 200000);
       set_skill("unarmed",100);
       set_skill("dodge",100);
        set_skill("hammer", 150);
        set_skill("parry", 150);
        set_skill("force", 100);
        set_skill("spells", 100);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 40);
        set("mana", 800);
        set("max_mana", 800);
        set("mana_factor", 40);
        set("inquiry", ([
                "�˲ι�": (: give_me :),
                "guo": (: give_me :),
        ]) );
       setup();
     carry_object("d/obj/cloth/pinkskirt")->wear();
   //        carry_object("/u/repoo/obj/renshen-guo");
}
int give_me(object ob)
{
        object who, me,guo;
        who=this_player();
        me=this_object();
        guo=new("/u/repoo/obj/renshen-guo");

        if( who->query("rsgtemp_given")) {
                        message_vision(HIY"$NͻȻ���𣬶�ݺݵĵ���$n˵��Ҫ���˻�Ҫ?\n"NOR, me, who);
                        command("hammer " + who->query("id"));
                        return 1;
                        }
        if( (int)who->query("age") < 16) {
                        message_vision(WHT"$N����$n��ͷ˵�������ӣ����㳤��Ż�֪���˲ι���ʲô��\n"NOR, me, who);
                return 1;
                        }
       else
    {
       command("nod "+who->query("id"));
                message_vision(CYN"$N�ó�һ���˲ι���$n��\n"NOR,me,who);
                who->set("rsgtemp_given", 1);
 who->set("name",HIR"��Ҷ"NOR+HIY""NOR);
                guo->set("owner",who->query("id"));
                guo->move(who);
                return 1;
                }
}
