// hell_guard.c

#include <ansi.h>

inherit NPC;

void create()
{
    	object ob1, ob2;
	
        set_name("�콵Ů��", ({"nushen"}));
        set("long", "����һλ���������Ů����̬��ȡ�\n");
        set("attitude", "friendly");
        set("gender", "Ů��");

        set("max_gin", 800);
        set("per", 30);
        set("max_kee", 800);
        set("max_sen", 800);

        set("max_atman", 180);
        set("atman", 180);
        set("max_mana", 180);
        set("mana", 180);
	set("force", 500);
	set("max_force", 500);
	set("force_factor", 5);
        set("str", 40);
        set("cor", 30);
        set("cps", 25);

        set("combat_exp", 180000);
	set("daoxing", 180000);


        set_skill("whip", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);

        setup();

        ob1=carry_object("/d/ourhome/obj/ironarmor");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
        ob2=carry_object("/d/obj/weapon/whip/tielian");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",
                HIM + name() +
"˵�����������ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
                + name() +"������Խ��Խ��������һ������Ưɢ�ˣ�\n" NOR,
environment(),
                this_object() );
        destruct(this_object());
}

void invocation(object who)
{
        int i;
        object *enemy;

        message("vision",
                HIM
"һ������֮�������ϴ����������������֣�һ����ȶ��˵�Ů�����˳�����\n\n"
                + name() + "˵�����������ٻ�������������\n" NOR,
                environment(), this_object() );
        enemy = who->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        kill_ob(enemy[i]);
                        if( userp(enemy[i]) )
enemy[i]->fight_ob(this_object());
                        else enemy[i]->kill_ob(this_object());
                }
        }
        set_leader(who);
}

