inherit NPC;
#include <ansi.h>
int give_newbie();
int give_family();
int give_51liwu();
int answer_me();

void create()
{
         set_name("Сʯͷ", ({"xiao shitou","stone"}));
   set ("long", @LONG
һ��ʯͷ��
LONG);
           set("gender", "����");
        set("age", 20);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "newbie"    :(:give_newbie:),
            "gift"    :(:give_newbie:),
            "����"    :(:give_newbie:),
            "family"    :(:give_family:),
            "��������"  :(:give_51liwu:),
            "��һ����"  : (:give_51liwu:),
            "��������"  :(:give_family:),
]));
        setup();

        carry_object("/d/lingtai/obj/faguan")->wear();
}

int answer_me()
{
        command("say ���С�\n");
        return 1;
}

/*
int give_51liwu()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ����");
                command("qi");
                return 1;
        }
         if (who->query("combat_exp") < 0 ){
command("hammer "+who->query("id") );
                command("say ����");
                return 1;
         }

         if (this_player()->query("liwuu") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ������\n");
        return 1;
        }

        who->add("balance",20000000); 
        who->add("daoxing",90000000);
        who->add("force",12000);
        who->add("mana",12000);
        who->add("potential",0);
        who->set("liwuu",1);
        if (this_player()->query("age") > 24 ){
        who->add("mud_age",-500000);    
         message_vision("$N����$n˵������ϲ���ֱ��С����!\n",this_object(),this_player());
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" Ϊ�����ǵ�ǰ;PK�ɡ�\n");
        command("say ��������"+who->query("name")+"����!\n",);
        command("say ���������backup!\n");
        return 1;
}
*/

int give_newbie()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ����");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") > 10000000 ){
                command("hammer "+who->query("id") );
                command("say ������");
return 1;
         }
/*
 if (who->query(
"combat_exp") < 0){
 command("sigh "+who->query("id") );
command("say ̫��");
                return 1;
              }
*/

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ������\n");
        return 1;
        }

        who->add("combat_exp",9000000);
        who->add("daoxing",9000000);
        who->add("force",12000);
        who->add("mana",12000);
        who->add("maximum_force",12000);
        who->add("max_mana",12000);
        who->add("max_force",12000);
       who->add("maximum_mana",12000);
        who->add("potential",0);
        who->set("lucky",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
��ĵ��������˶�ʮ��!\n
        ���Ǳ��������20000��\n
        ��������400�������ͷ�����\n");
        command("say ��������"+who->query("name")+"���ˣ�\n");
        return 1;
}
int give_family()
{
        object who=this_player();
        string family;
        family=who->query("family/family_name");
        if (!userp(who))
        {
                command("heng");
                command("say ����");
                command("qi");
                return 1;
        }
if (this_player()->query("lucky") > 1 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say �����ˣ�\n");
        return 1;
        }
        if (who->query("combat_exp") > 40000000 ) {
                        command("hammer "+who->query("id") );
                command("say �Ͳ���");
   return 1;
         }
 if (who->query("combat_exp") < 10000 ){
 command("sigh "+who->query("id") );
command("say ȥ��");
                return 1;
              }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ�ֻ���������ɿ��ԡ�\n");
                return 1;
        }
        switch(family) {
         case "��ѩɽ":

who->set_skill("literate",500);
who->set_skill("dodge",500);
who->set_skill("force",500);
who->set_skill("spells",500);
who->set_skill("parry",500);
who->set_skill("ningxie-force",500);
who->set_skill("dengxian-dafa",500);
who->set_skill("throwing",500);
who->set_skill("unarmed",500);
who->set_skill("xiaoyaoyou",500);
who->set_skill("blade",500);
who->set_skill("bingpo-blade",500);
who->set_skill("cuixin-zhang",500);
who->set_skill("sword",500);
who->set_skill("bainiao-jian",500);
break;
                case "������": 
who->set_skill("literate",500);
who->set_skill("baguazhou",500);
who->set_skill("force",500);
who->set_skill("dodge",500);
who->set_skill("spells",500);
who->set_skill("parry",500);
who->set_skill("unarmed",500);
who->set_skill("archery",500);
who->set_skill("bawang-qiang",500);
who->set_skill("changquan",500);
who->set_skill("lengquan-force",500);
who->set_skill("mace",500);
who->set_skill("spear",500);
who->set_skill("wusi-mace",500);
who->set_skill("xuanyuan-archery",500);
who->set_skill("yanxing-steps",500);
who->set_skill("jinglei-mace",500);
break;
default:
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ֻ���������ɡ�\n");
                return 1;
}       
        who->set("lucky",2);
        command("nod "+who->query("id") );
        command("say "+family+"����"+who->query("name")+"����������\n");
        return 1;
}
void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
*/

void greeting(object who) {
if( who->query("combat_exp") < 1000)
        tell_object(who,"������š�\n");
        tell_object(who,"�������⡣\n");
}
/*
int give_dan1()
 {
        object who=this_player();
        object dan;
        dan=new("/u/stey/obj/dan1.c");
        if (this_player()->query("dann") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ʲô?\n");
        return 1;
        }

        dan->move(who);
        message_vision("$N����ɡ�\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
