//����npc
//inherit F_VENDOR_SALE;

#include <ansi.h>
int give_wx();
//int give_wx2();
int answer_me();
inherit NPC;

void create()
{
       set_name(HIW"����"NOR, ({"wu shen", "wushen"}));
       set("long", "�칬���𷲼��½��������ӵ�кܶ����ص���ѧ������������������ɱ����ά����\n");
           set("gender", "����");
       set("title", HIC"�ݺ�����"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
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
        string family;
       family=who->query("family/family_name");
        if (!userp(who))
         {
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
        if (this_player()->query("luckyy") > 0 ){
        message_vision("$N����$n����һ����\n",this_object(),this_player());
               command("say ���ɴ�ά��ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        if (who->query("combat_exp") < 40000 ) {
                       command("hammer "+who->query("id") );
                command("say �����ѧ��ô�ã��������죿");
                return 1;
         }
        if ( family == 0 )
       {
                command("heng");
                command("say "+who->query("name")+"����ʲô���ɵģ�����������Ķ�����\n");
            return 1;
       }
        switch(family) {
               case "��ׯ��":
who->add("potential",10000);
who->set("luckyy",1);
who->add("daoxing",30000);
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ������ɱ�������ׯ�۵�һ��qn10000,���У����꽱����\n",);
break;
                case "��������":  
who->add("potential",7000);
who->set("luckyy",1);
who->add("daoxing",25000);
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ������ɱ����ᶫ�������ڶ���qn7000,���У����꽱����\n",);
break;
                case "������": 
who->add("potential",4000);
who->set("luckyy",1);
who->add("daoxing",20000);
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ������ɱ����Ὣ����������qn4000,���У����꽱����\n",);
break;
        default:
                command("sigh");
 command("say "+who->query("name")+"��δ�յ������ɱ�ʤ��֪ͨ�����鿴��\n");
               return 1;
       }
                     command("addoil");
               return 1;
}
/*        if (!userp(who)){
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
               �����ڴ��������500gold��\n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����50�򣬸��轱����\n");
        return 1;
}
int give_wx2()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 1500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (who->query("combat_exp") > 1900000 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô����������Ҫ��̰�ģ���");
                command("kick "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",80000);
        who->add("balance",5000000);
        who->add("daoxing",100000);
        who->set("jjjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
               ��ĵ���������һ����!\n 
               �����ڴ��������500gold��\n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"��ѧ����150�򣬸��轱����\n");
        return 1;
}
void init()
{
     call_out("greeting", 1, this_player());
      ::init();
   add_action("do_vendor_list", "list");
}
void die()
{
 return;
}
}  */
