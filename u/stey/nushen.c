#include <ansi.h>

int pk();
int nopk();

inherit NPC;

void create()
{
  set_name(HIW"����Ů��"NOR, ({ "ziyou nushen", "nushen"}));
  set("title", HIC"����վ"NOR);   
  set("long", HIW"\nһλ������ֵ�Ů�ӣ�������Ť������֫��\n�־����ɻ�ѣ��й������ɵ��£�������������\n"NOR+HIC"\n ask nushen about pk \n ask nushen about no pk \n\n"NOR);
  set("gender", "Ů��");
  set("age", 16);
  set("attitude", "heroism");
  set("per", 32);
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 6000);
  set("max_force", 12000);
  set("force_factor", 300);
  set("max_mana", 7000);
  set("mana", 16000);
  set("mana_factor", 350);
  set("combat_exp", 2400000);
  set("daoxing", 6800000);  
  set("chat_msg", ({
        "Ů�����������㣺pk��һ��������ľ������㿼�������һ�ζ�����ġ�\n",
        "Ů�����������㣺ѡ����pk,��û�취���ڵģ������κμ�������\n",             
        }));
  set("inquiry", ([
  "name" : "�Ҿ��Ǳ���վ������Ů�������ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "here" : "�����ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "no pk" : (:nopk:),
  ]));
  setup();
}

int pk()
{
string str;
object who = this_player();
object ob = this_object();

void init()
{
	::init();  
  add_action("do_yao","yao");
}
if (this_player()->query("ziyou")=="got")
{
message_vision("����Ů�����$N˵������������Ѿ������ˣ��㻹���ģ���\n",who);
return 1;
}
else
{
message_vision("����Ů�����$N˵�����㿼��������𣿾����˾�˵pkpk��\n",who);	
  int do_pkpk(string arg)
   {
 	string type;
	object ob;
	object who=this_player();
	object me=this_object();
	str=who->name();
message("channel:chat",HIW"��������Ե������Ů��"+str+"�Ѿ�ѡ����PK������·�������֪�ա�\n"NOR,users());
message("channel:rumor",HIW"��ҥ�ԡ�����Ů��"+str+"�Ѿ�ѡ����PK������·�������֪�ա�\n"NOR,users());
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����PK������·���Ժ����Ϊ֮������\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
     }
return 1;
}        
         
int nopk()
{        
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyou")=="got")
{        
message_vision("����Ů�����$N˵������������Ѿ������ˣ��㻹���ģ���\n",who);
return 1;
}        
else     
{        
str=who->name();
message("channel:chat",HIW"��������Ե������Ů��"+str+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�\n"NOR,users());
message("channel:rumor",HIW"��ҥ�ԡ�����Ů��"+str+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�\n"NOR,users());
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����NOPK������·���Ժ�������˵�æ����\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}        
}        
         
      
