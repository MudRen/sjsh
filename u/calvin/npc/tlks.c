// ������˹ by Calvin

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string suanming(object me);
void create()
{
        set_name(HIW"������˹"NOR, ({"telan kesi", "tlks", "telan", "kesi"}));
        set("title", HIG"���鴫��"NOR);
        set("gender", "����" );
        set("age", 10);
        set("per", 30);
        set("str", 30);
set("long","�����˱������������˲���Ķ��ӡ�\n");

        set("class", "yaomo");
        set("combat_exp", 100000000);
        set("daoxing", 100000000);

        set("rank_info/respect", "����");
        set_skill("unarmed", 1000);
        set_skill("cuixin-zhang", 1000);
        set_skill("dodge", 1000);
        set_skill("xiaoyaoyou", 1000);
        set_skill("parry", 1000);
        set_skill("sword", 1000);
        set_skill("bainiao-jian", 1000);
        set_skill("blade", 1000);
        set_skill("bingpo-blade", 1000);
        set_skill("throwing", 1000);
        set_skill("force", 1000);   
        set_skill("ningxie-force", 1000);
        set_skill("literate", 1000);
        set_skill("spells", 1000);
        set_skill("dengxian-dafa", 300);

        map_skill("spells", "dengxian-dafa");
        map_skill("force", "ningxie-force");
        map_skill("unarmed", "cuixin-zhang");
        map_skill("sword", "bainiao-jian");
        map_skill("blade", "bingpo-blade");
        map_skill("dodge", "xiaoyaoyou");

        set("max_kee", 10000);
        set("max_sen", 10000);
        set("force", 6000);
        set("max_force", 6000);
        set("mana", 6000);
        set("max_mana", 6000);  
        set("force_factor", 1000);
        set("mana_factor", 1000);

        set_temp("apply/damage", 50);
        set_temp("spply/armor", 50);
        set_temp("apply/dodge", 50);
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: cast_spell, "juanbi":),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng":),
            (: perform_action, "sword", "feijian":),
       }) );

            setup();
        carry_object("/d/longzhu/obj/4");
        carry_object("/d/longzhu/weapon/duanjian")->wield();
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="4" || inv[i]->query("id")=="lan longzhu")
                {
                   inv[i]->move(me);

                   message_vision("$N����һö����ɫ�����ӣ�$n��æһ��ץ�����\n",this_object(),me);
            message("channel:rumor",HIG+"��"HIW"���鴫˵"HIG"��"HIC"�����"HIW"��"+me->query("name")+"�ڳ������������õ���"HIB"������"HIW"��\n"+NOR,users());
         }
        }
  }
 ::die();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 10);
        set("inquiry", ([
           "name" : "���ǲ���Ķ���,��ô? ���۸�����?��\n",
            "here" : "����������������������㡣\n", 
            "����" : "��˵�е�����ֲ����߸���ͬ�ĵط���\n", 
         ]) );

        set("chat_msg", ({
            "������˹˵������ô����û�������氡?\n",       
                "������˹�������´������㼸�ۡ�\n",
                "���˿���,���Ӽ�Ϊ��ŭ��\n",
                "���˿����ʵ�:������֪��������?\n",
                (: random_move :)
        }) );
}


int accept_object(object me, object ob)
{
        object longzhu;

        if(userp(ob)) return 0;

        if( (string)ob->query("name")=="������" )
        {
                command("u&me " + me->query("id"));
                command("say ��л" + RANK_D->query_respect(me) + "��\n���ҾͰ��ҵ�������㻻�˰ɡ�\n");
                carry_object("/d/longzhu/obj/longzhu");
                command("give longzhu to " + me->query("id"));
                return 1;
        }
        else
        {
            command("say ���ҵ����ҵ�����������̫лл���ˡ�");
            return 1;
        }
}
