// yg-kunlun   by piao

#include <ansi.h>
inherit __DIR__"yaoguai.c";

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        set("title",HIG"�����Ϲ�"NOR);
	set("gender", "����");
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("mace", j);
        me->set_skill("dashen-bian", j);
        me->set_skill("sword",j);
        me->set_skill("huntian-jian",j);
        me->set_skill("wugou-jian",j);
        me->set_skill("lingyunbu", j);
        me->set_skill("yuxu-spells", j);
        me->set_skill("kaitian-zhang", j);
        me->set_skill("xuanzong-force", j);

        me->map_skill("force", "xuanzong-force");
        me->map_skill("sword", "huntian-jian");
        me->map_skill("mace",  "dashen-bian");
        me->map_skill("parry", "wugou-jian");
        me->map_skill("spells", "yuxu-spells");
        me->map_skill("dodge", "lingyunbu");
        me->map_skill("unarmed", "jinding-zhang");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"mace", "quzhu" :),
        (: cast_spell, "linght" :),
        (: perform_action,"sword", "lin" :),
        }) );

        if (random(2))
           weapon=new("/d/obj/weapon/mace/ironmace");
        else
           weapon=new("/d/obj/weapon/sword/qingfeng");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
