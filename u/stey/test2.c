//����npc

inherit NPC;
#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"�񱦱�"NOR, ({"baobao"}));
   set ("long", @LONG
���������︺�����ҷ���ѧ�����Ŀɰ����񱦱�����ask baobao about ������
LONG);
           set("gender", "����");
        set("title",HIY"���ÿɰ���"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
            "100��"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("balance",5000000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ��ĵ�����������ʮ��!\n 
               ���Ǳ��������50000��\n
               ��������400�������ͷ�����\n");
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ�����ѧ50��Ľ�����\n");
        return 1;
}
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
int give_wx2()
{
        object who=this_player();
         if (this_player()->query("zzzz") > 0 ){
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
                return 1;
         }
        who->add("combat_exp",500000);
        who->add("daoxing",500000);
        who->set("maximum_force",2000);
        who->set("maximum_mana",2000);
        who->set("zzzz",1);
        who->set("mud_age",300000);
        command("ok");
}
