//yg-emei by piao

#include <ansi.h>

inherit __DIR__"yaoguai.c";


void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIM"��������"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
            me->set_skill("sword", j);
        
              me->set_skill("jinding-zhang", j);
        me->set_skill("huifeng-sword", j);
        me->set_skill("zhutian-bu", j);
        me->set_skill("emeiforce", j);
        me->set_skill("mahayana", j);

         me->map_skill("unarmed", "jinding-zhang");
        me->map_skill("dodge", "zhutian-bu");
              me->map_skill("sword", "huifeng-sword");
        me->map_skill("parry", "huifeng-sword");
              me->map_skill("force", "emeiforce");
        me->map_skill("spells", "mahayana");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"sword", "huan" :),
        (: cast_spell, "haotian" :),
        (: exert_function, "heal" :),
        }) );

        weapon=new("/d/obj/weapon/sword/changjian");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
