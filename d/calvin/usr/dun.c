// ���NPC.nothing by Calvin of 2001.6

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({"dun's"}));
        set("title", HIR"�˲�����֮����"NOR);
        set("gender", "����" );
        set("age", 30);
        set("per", 37);
        set("str", 240);
    set("long","���ִ����ֲ������ǿ��������ڿ����˵����˷𵲲���С����--�ܲ�ͨ��\n");

//        set("attitude", "aggressive");

       set("shen_type", 1);
       set("combat_exp", 7308249);
       set("daoxing", 8000000);
       set("max_kee", 3118);
       set("max_gin", 210);
       set("max_sen", 2030);
       set("force", 5500);
       set("max_force", 5500);
       set("force_factor", 210);
       set("max_mana", 7500);
       set("mana", 15000);
       set("mana_factor", 210);

       set_skill("dodge", 400);
       set_skill("force", 286);
       set_skill("fork", 207);
       set_skill("literate", 155);
       set_skill("makeup", 159);
       set_skill("parry", 399);
       set_skill("spells", 208);
       set_skill("unarmed", 400);
       set_skill("dragonfight", 399);
       set_skill("dragonforce", 400);
       set_skill("dragonstep", 400);
       set_skill("fengbo-cha", 399);
       set_skill("huntian-hammer", 399);
       set_skill("seashentong", 212);
        map_skill("dodge", "dragonstep");
        map_skill("force", "dragonforce");
        map_skill("fork", "fengbo-cha");
        map_skill("parry", "fengbo-cha");
        map_skill("spells", "seashentong");
        map_skill("unarmed", "dragonfight");

       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "hufa" :),
                (: perform_action, "unarmed", "sheshen" :),
                (: perform_action, "unarmed", "leidong" :),
                }) );

        set_temp("apply/armor",50);
        set_temp("apply/damage",25);
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/city/npc/obj/pifeng")->wear();
        carry_object("/d/city/npc/obj/kui")->wear();
        carry_object("/d/wizz/calvin/longzhu/zhu3");
        carry_object("/d/city/npc/obj/shoes")->wear();
}
//void init()
//{
//        object ob;
//        ::init();
//        set("chat_chance", 10);
//        set("inquiry", (
//           "name" : "�Ҿ��Ƕ��������Ľ���,��ô���Ҷ���֪������\n",
//            "here" : "����������ϲ�����ĵط�,��Ϊ����羰����\n", 
//            "����" : "������������,��ʲô����?\n", 
//         ]) );

//        set("chat_msg", ({
//            "����˵��:�켫֮�������˼��������ĵط�,����һƬ���ֵ�ʥ��!\n",       
//            "����˵��:Ҫ��ȡ���澭�ɲ��Ǽ����׵��°�!\n",       
//            "����˵��:�ҽ�����һ���콾����,�������˿������!\n",       
//            "����˵��:�ҵ������λ������ѩ,��Ͼ糺��С�������ӡ�\n",       
//                (: random_move :)
//        }) );
//}

