inherit NPC;
#include <ansi.h>
void create()
{
              set_name("���ɶ�", ({"lin xianer", "lin","xianer"}));
             set("long",
             "���ֵ�һ�����ˡ�\n");
             set("title", HIR"��ұ����"NOR);
            set("gender", "Ů��");
             set("age", 20);
             set("attitude", "friendly");
             set("per", 40);
             set("int", 30);
             set("chat_chance",5);
             set("chat_msg", ({
            HIM"���ɶ����쳤̾:���磬��������Ӣ�ۣ�\n"NOR,
            }));
            setup();
             carry_object("/d/moon/obj/luoyi")->wear();
}
inherit NPC
void create()
{
              set_name(���ɶ�, ({lin xianer, lin,xianer}))
             set(long,
             "���ֵ�һ�����ˡ�\n")
             set(title, HIR��ұ����NOR)
            set(gender, Ů��)
             set(age, 20)
             set(attitude, friendly)
             set(per, 40)
             set(int, 30)
             set(chat_chance,5)
             set(chat_msg, ({
            HIM���ɶ����쳤̾:���磬��������Ӣ�ۣ�\nNOR,
            }))
            setup()
             carry_object(/d/moon/obj/luoyi)->wear()
}

