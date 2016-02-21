inherit NPC;
int ask_miyan();
#include <ansi.h>

void create()
{
	 set_name("��������", ({ "mingshen miyan", "miyan", "mingshen" }) );
	 set("gender", "����" );
        set("title", WHT"����"NOR);
	 set("age", 16);
	 set("long", "Ϊ��׷����ǿ���������뿪��ȵ����������С�����������ɢ��
��һ��������Ϣ��ɱ�����������ķ��������С�����η·���
��ڰ���Ϊһ�塣\n");
          set("daoxing",6000000);
           set("combat_exp",4000000);
        set("attitude", "peaceful");
	 set("int", 30);
	 set("class", "swordman");
        create_family("��������", 3, "����");
        set_skill("unarmed", 400);
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("spells", 400);  
        set_skill("renshu", 400);
        set_skill("literate", 400);
        set_skill("sword", 400);  
        set_skill("huoxin-sword", 400); 
        set_skill("fengyu-piaoxiang", 400);
        set_skill("dodge", 400);  
        set_skill("force", 400);   
        set_skill("guixi-force", 400);
        map_skill("spells", "renshu");
        map_skill("force", "guixi-force");
        map_skill("sword", "huoxin-sword");
        map_skill("parry", "huoxin-sword");
        map_skill("dodge", "fengyu-piaoxiang");
        set("per", 30);
        set("max_kee", 4000);
        set("max_gin", 4000);
        set("max_sen", 4000);
        set("force", 10000);
        set("max_force", 5000);
        set("force_factor", 0);
        set("mana", 10000);
        set("max_mana", 5000);
        set("mana_factor", 200);
              set("swordman/dead_perform",1);
        set("inquiry", ([
                      "��ǿ����":(:ask_miyan :),
                      "ڤ���ٷ�":(:ask_miyan :),
        ]) );
         set("chat_chance_combat", 9000);
         set("chat_msg_combat", ({
                (: perform_action, "sword", "dead" :),
         }) );
         set("chat_chance",2);
         set("chat_msg", ({
        WHT"��������ؿ�����˵�������Ҫ��Ϊ��ǿ���ͣ��ͱ����з���һ�еľ���\n"NOR,
        WHT"������Ц��˵������Ȼ������������ܾ��Ǳ���ӡ�Ľ���[ڤ���ٷ�]��\n"NOR,
        }));
         setup();
	  carry_object("/d/obj/cloth/zhanpao")->wear();
         carry_object("/d/obj/weapon/sword/qinghong")->wield();
}


/*
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if(ob) 
        ob->set("swordman/dead_perform",1);
	  message_vision(WHT  "\n�ڴ�Խ�����ߵ���һɲ�ǣ�$N����������[ڤ���ٷ�]�����ܡ�\n\n" NOR,ob);
        ::die();            
}
*/

void die()
{

        object ob = query_temp("last_damage_from") ;

        if((ob&&ob->query("MKS")>=5000) && (ob&&ob->query("swordman/dead_perform")!= 1) 
              &&(ob&&ob->query_temp("swordman/jiezhao_miyan")))
        {
        ob->set("swordman/dead_perform",1);
	 message_vision(WHT  "\n�ڴ�Խ�����ߵ���һɲ�ǣ�$N����������[ڤ���ٷ�]�����ܡ�\n\n" NOR,ob);

        }
       ::die();
}



int ask_miyan()
{
       object ob=this_player();
       if ( (int)ob->query("MKS") <5000)
       {
	message_vision(WHT  "\n������������Ŀ���$N˵��:�����û��ѧ��ڤ���ٷ����ʸ�\n\n" NOR,this_player());
	return 1;
       }
       else
       {command("sneer");
       command("say ڤ���ٷ������������ǿ���У�Ҫ��ѧ�������Ƚ�ס
����һ��(jiezhao)��˵��\n");
        this_player()->add_temp("swordman/ask_miyan", 1);
        return 1;
        }
}

void init()
{
    ::init();
    add_action("do_jiezhao", "jiezhao");
}

int do_jiezhao(string arg)
{
    object me=this_player(), npc=this_object(), ob;
    if (!me->query_temp("swordman/ask_miyan"))
    return 0;
      if (npc->is_fighting() || npc->is_busy())
                return notify_fail("��������������æ��ûʱ�����㡣\n");
    me->delete_temp("swordman/ask_miyan");
    me->set_temp("swordman/jiezhao_miyan",1);
    if (!(ob=query_temp("weapon"))
     || ob->query_temp("skill_type") != "sword")

    {
	destruct(ob);
	ob=new("/d/obj/weapon/sword/qinghong");
	ob->move(npc);
	command("wield sword");
       kill_ob(me);
          command("perform dead");
       me->kill_ob(npc);
       return 1;
     }
}
