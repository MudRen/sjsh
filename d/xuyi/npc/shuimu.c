
inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("ˮĸ����", ({ "shuimu niangniang", "shuimu","niangniang" }) );
       set("loc_name", "ˮĸ����");
        set("gender", "Ů��" );
        set("age", 26);
        set("int", 30);
        set("con", 30);
        set("per", 35);
        set("class", "hero");
        set("attitude", "friendly");
        set("rank_info/respect", "����");
        set("apprentice_available", 50);
          create_family("�Ϻ���٢ɽ", 2, "����");
        set("long",
                "������ˮ��Ϊ����Ϊ���˼䡣��С��̫�Ӳ��Ĵ���\n"
                "�շ�����ʥ��ʦ����������ǧ�������֮���ף�����Ϊ\n"
                "���ӡ�\n"
                );
        set("force_factor", 100);
        set("chat_chance", 5);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 1000);
        set("force", 2000);
        set("max_mana", 1500);
        set("mana", 3000);
        set("combat_exp", 1000000);

        set_skill("unarmed", 100);
        set_skill("sword", 140);
        set_skill("force", 100);
        set_skill("literate", 60);
        set_skill("dodge", 100);
        set_skill("tianwei-shi", 100);
        set_skill("qixi-sword", 180);
        set_skill("parry", 100);
        set_skill("buddhism", 100);
        set_skill("lotusforce", 100);
        set_skill("lianhuan-tui", 100);
        set_skill("spells", 110);

        map_skill("sword", "qixi-sword");
        map_skill("dodge", "tianwei-shi");
          map_skill("spells", "buddhism");
        map_skill("force", "lotusforce");
        map_skill("unarmed", "lianhuan-tui");
        map_skill("parry", "qixi-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword","quewu" :),
                (: cast_spell, "freeze" :),
                (: exert_function, "hanxing shuimu" :),
        }) );

        setup();
        carry_object("/d/obj/cloth/skirt")->wear();
        carry_object("/d/obj/weapon/sword/wsword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 1);
}
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������");
                else
                        call_out("do_recruit", 1, ob);
        } else {
                command("say ������һ��ֻ��һ��ͽ�ܡ�");
        }
}
void do_recruit(object ob)
{
        if( (string)ob->query("gender") != "Ů��" )
          {
      command("say ��ֻ��Ů���ӣ��㻹��ȥ��С��̫�Ӱɣ�");
         return;
         }
   if (((int)ob->query("combat_exp") < 20000 )) {
   command("say ��λ" + RANK_D->query_respect(ob) + "���в��㣬������Ŭ�����ǡ�\n");
   return;
   }
        else {

                command("smile");
                command("say ���պ��Ҫ����ҵ��书Ӵ��");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "hero");
        add("apprentice_availavble", -1);
}
int accept_object(object me,object ob)
{
        object m;
        if (ob->query("id")=="mo li") {
                command("pat" + this_player()->query("id") );
                m=new("/d/obj/book/halberd");
                m->move(this_player());
                message_vision("ˮĸ���ｻ��$Nһ���飬����ʦ�����ҵĶ��������͸���ɡ�\n", this_player());
                call_out("destroy", 1, ob);
        return 1;
        }
        else return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}

void announce_gift()
{
        object *alluser,obj,gift;
        int s;
        object me = this_object();

        alluser=users();        

        CHANNEL_D->do_channel(this_object(),"party","��Ϧ�ѽڣ����ɵ��ӿɵ����");
        s=sizeof(alluser);
        for (int i=0;i<s;i++) {
            obj=alluser[i];
            if (obj!=me && obj->query("family/family_name")=="�Ϻ�����ɽ")
            {
            gift=new(__DIR__"moli");
            gift->move(obj);
            message("vision",me->query("name")+"����һ"+gift->query("unit")+gift->name()+"��\n",obj);
            }
        }

        destruct(me);
        return;
}

