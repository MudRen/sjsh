// robber.c

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����ǿ��", ({ "mask robber" }) );
        set("long","����һ������ǿ�������Ӻ����ء�\n");
        set("attitude", "heroism");
        set("str", 20 + random(11));            // ����
        set("per", 20 + random(11));            // ��ò
        set("int", 20 + random(11));            // ����
        set("con", 20 + random(11));            // ����
        set("dex", 20 + random(11));            // ��
        set("kar", 20 + random(11));            // ��Ե
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                BOLD "����ǿ���ȵ���߾����·���ҿ������������ԣ�Ҫ��Ӵ˹���������������\n" NOR,
                CYN "����ǿ���ȵ��������¶���������һ����·��\n" NOR,
                CYN "����ǿ���ȵ������ӿ�����ҪǮ����Ҫ����\n"NOR ,
                BOLD "����ǿ���ȵ���ǮҲҪ����ҲҪ��\n"NOR,
        }) );
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 10);
        set("shen", -10);
        set("no_suck",1);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 30);
        set_temp("apply/dodge", 30);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/npc/obj/gangdao")->wield();
//      add_money("silver", 20);
}

void init()
{
        object me, ob, obj;
        int n;

        me=this_object();
        ob=this_player();

        ::init();

        if (obj=present("biao yin", ob)) {
                if (obj->query("identifier")==query("target"))
                        if (!me->is_killing(ob)) {
                                set_leader(ob);
                                if(query("speaker"))
                                        command("say "+ob->name()+"�����������£�������·������");
                                me->kill_ob(ob);
                                ob->fight_ob(me);
                                set("victim", ob->query("id"));

                                n = ob->query("combat_exp") + random(10000) - 7000;
                                if( n <= 0 ) n = random(3000) + 1;
                                set("combat_exp", n );
                                n = ob->query_skill("force", 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("force", n );
                                n = ob->query_skill("unarmed", 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("unarmed", n );
                                n = ob->query_skill("force", 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("blade", n );
                                n = ob->query_skill("parry", 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("parry", n );
                                n = ob->query_skill("dodge", 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("dodge", n );
                                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("taiji-shengong", n );
                                n = ob->query_skill(ob->query_skill_mapped("force"), 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("taiji-dao", n );
                                n = ob->query_skill(ob->query_skill_mapped("dodge"), 1) + random(10) - 7;
                                if( n <= 0 ) n = random(3) + 1;
                                set_skill("tiyunzong", n );
                                map_skill("dodge", "tiyunzong");
                                map_skill("force", "taiji-shengong");
                                map_skill("blade", "taiji-dao");
                                map_skill("parry", "taiji-dao");
                        }
        }
        remove_call_out("check_out");
        call_out("check_out", 1);
}

void check_out()
{
        int i, present;
        object me, *ob, obj;

        me=this_object();
        ob=all_inventory(environment());
        for(i=0; i<sizeof(ob); i++) {
                if(obj=present("biao yin", ob[i])) {
                        if(obj->query("identifier")==query("target")) {
                                if(!me->is_killing(ob[i]->query("id"))) {
                                        set_leader(ob[i]);
                                        if(query("speaker"))
                                                command("say "+ob[i]->name()+"�����������£�������·����\n");
                                        me->kill_ob(ob[i]);
                                        ob[i]->fight_ob(me);
                                        set("victim", ob[i]->query("id"));
                                }
                                present = 1;
                                break;
                        }
                }
                present = 0;
        }

        if(present) {
                remove_call_out("check_out");
                call_out("check_out", 1);
        }
        else {
                for(i=0; i<sizeof(ob); i++)
                        if(me->is_killing(ob[i]->query("id")))
                                remove_killer(ob[i]);
                remove_call_out("leave");
                call_out("leave", 1);
        }
}

void leave()
{
        object ob;

        if (!environment()) return;

        if(query("speaker"))
                if(objectp(ob=present(query("victim"), environment()))) {
                        message("vision", "\n", environment(), this_object());
                        message("vision", HIY + name() + "����һ����\n" NOR, environment(), this_object());
                        message("vision", HIY + name() + "˵������"+ob->name()+"������ʶ�࣡��ү�ǽ���ͷ���һ����·����\n" NOR, environment(), this_object());
                        message("vision", GRN + name() + "̧��������Ѹ�ٵĳ����ˡ�\n" NOR, environment(), this_object());
                }
                else {
                        message("vision", "\n", environment(), this_object());
                        message("vision", HIB + name() + "���������������������\n" NOR, environment(), this_object());
                        message("vision", HIB + name() + "һ���ɢ��\n" NOR, environment(), this_object());
                }
        destruct(this_object());
}


