
// tomcat

inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
        
        int j;
        j= 200+random(150); 
        create_family("��������", 2, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("sword", j+random(15));
        me->set_skill("baiyun-sword", j+random(15));
        me->set_skill("piaoxiang", j+random(15));
        me->set_skill("tianjijue", j+random(15));
        me->set_skill("wuji-force", j+random(15));
        me->set_skill("lingxiyizhi", j+random(15));

        me->map_skill("force", "wuji-force");
        me->map_skill("sword", "baiyun-sword");
        me->map_skill("parry", "baiyun-sword");
        me->map_skill("spells", "tianjijue");
        me->map_skill("dodge", "piaoxiang");
        me->map_skill("unarmed", "lingxiyizhi");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
           (: perform_action,"sword", "east" :),
            }) );    
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        command("wield all");
}
