
// tomcat

inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
        
        int j;
        j= 200+random(150); 
        create_family("������", 2, "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("sword", j+random(15));
        me->set_skill("huifeng-sword", j+random(15));
        me->set_skill("zhutian-bu", j+random(15));
        me->set_skill("mahayana", j+random(15));
        me->set_skill("emeiforce", j+random(15));
        me->set_skill("jinding-zhang", j+random(15));

        me->map_skill("force", "emeiforce");
        me->map_skill("sword", "huifeng-sword");
        me->map_skill("parry", "huifeng-sword");
        me->map_skill("spells", "mahayana");
        me->map_skill("dodge", "zhutian-bu");
        me->map_skill("unarmed", "jinding-zhang");

        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
           (: perform_action,"sword", "mie" :),
            }) );    
        weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        command("wield all");
}
