
// tomcat


inherit __DIR__"fei.c";



void set_skills()
{
        object me=this_object();
        object weapon;
       
        int j;
        j= 200+random(150);  
        create_family("������", 3, "����");
        set("gender", "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("stick", j+random(15));
        me->set_skill("zui-gun", j+random(15));
        me->set_skill("sword",j+random(15));
        me->set_skill("shaolin-sword",j+random(15));
        me->set_skill("shaolin-shenfa", j+random(15));
        me->set_skill("chanzong", j+random(15));
        me->set_skill("banruo-zhang", j+random(15));
        me->set_skill("yijinjing", j+random(15));

        me->map_skill("force", "yijinjing");
        me->map_skill("sword", "shaolin-sword");
        me->map_skill("stick","zui-gun");
        me->map_skill("parry", "zui-gun");
        me->map_skill("spells", "chanzong");
        me->map_skill("dodge", "shaolin-shenfa");
        me->map_skill("unarmed", "banruo-zhang");

	set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
        (: cast_spell, "roar" :),
        (: cast_spell, "suixin" :),
        }) );

        if (random(2))
             weapon=new("/d/obj/weapon/stick/xiangmo"); 
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        
        command("wield all");
}
