// teller.c
//cglaem...12/16/96.

inherit NPC;


void create()
{
            set_name("С�ƹ�", ({"zhang gui","boss"}));
        set("gender", "����" );
         set("age", 80);
           set("age", 30);
          set("long", "����������������ҽ�����Ĵ���������Ĺ�Ч��\n");
            set("long", "�����һ������������Ĺ�Ч����˵Ҫ2���ƽ��أ�\n");
        set("daoxing", 80000);

        set("attitude", "peaceful");
        set_skill("unarmed", 10);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("literate", 50);
        set_skill("spells", 50);
        set("per", 15);
        set("max_kee", 350);
        set("max_gin", 300);
        set("max_sen", 300);
	set("max_mana", 200);
	set("mana", 200);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
        object ob;

        ::init();
}


int accept_object(object me, object ob)
{
          object cola;

                if( (string)ob->query("name")=="�𻨾ƴ�" )
        {
        command("say ��λ" + RANK_D->query_respect(me) + "��������(cola)��Ц�ɣ����(drink)�ɣ�\n");
                  carry_object("/u/yudian/cola");
                 command("give cola to " + me->query("id"));
       		return 1;
        }
}
