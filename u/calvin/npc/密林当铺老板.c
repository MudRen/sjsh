inherit NPC;

void create()
{
        set_name("�߳���", ({"gao changsheng", "gao", "boss"}));
        set("title", "�����ƹ�");
        set("gender", "����");
        set("age", 47);
        set("kee", 800); 
        set("max_kee", 800);
        set("sen", 800);
        set("max_sen", 800);    
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("rank_info/respect", "�ƹ��");
        set("env/wimpy", 50);
        set("chat_chance", 10);
        set_skill("parry", 120);
        set_skill("unarmed", 120);
        set_skill("dodge", 120);

        setup();
        carry_object("/u/calvin/armor/��������")->wear();
        carry_object("/d/obj/����/�����ָ")->wear();

        add_money("gold", 1);
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/city/npc/xunluobing");
                ob->move(environment());
        }

        message_vision("\n��Ȼ������������Ѳ�߹ٱ�����$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
}
int regenerate()
{
        set("called", 0);
        return 1;
}
