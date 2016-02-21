#include <ansi.h>

int pk();
int nopk();
int gift();
int back();
int bainiao_jian();
int fengbo_cha();
int lunhui_zhang();

inherit NPC;

void create()
{
  set_name(HIW"����Ů��"NOR, ({ "ziyou nushen", "nushen"}));
  set("title", HIC"����վ"NOR);   
  set("long", HIW"\nһλ������ֵ�Ů�ӣ�������Ť������֫��\n�־����ɻ�ѣ��й������ɵ��£�������������\n"NOR+HIC"\n ask nushen about pk ѡ��У˵ĵ�·��\n ask nushen about nopk ѡ��ΣϣУ˵ĵ�·��\n ask nushen about gift ��ȡȡ����ɴ����칬���صĽ�����\n ask nushen about back ���������ѡ����һ������ѡ��Ļ��ᡣ\n\n"NOR);
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
  set("inquiry", ([
  "name" : "�Ҿ��Ǳ���վ������Ů�������ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "here" : "�����ѡ��pk�����ߡ�nopk�����������Ժ��������\n",
  "PK"   : (:pk:),
  "pk"   : (:pk:),
  "NOPK" : (:nopk:),
  "nopk" : (:nopk:),
  "NO PK" : (:nopk:),
  "no pk" : (:nopk:),
  "gift" : (:gift:),
  "����" : (:gift:),
  "back" : (:back:),
  "����" : (:back:),
  "���񽣷�" : (:bainiao_jian:),
  "bainiao-jian" : (:bainiao_jian:),
  "�粨ʮ����" : (:fengbo_cha:),
  "fengbo-cha" : (:fengbo_cha:),
  "lunhui-zhang" : (:lunhui_zhang:),
  "�ֻ���" : (:lunhui_zhang:),
  ]));
  setup();
}

int pk()
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
message("channel:chat",HIC"����Ե������Ů��"+str+"�Ѿ�ѡ����PK������·�������֪�ա�\n"NOR,users());
message("channel:rumor",HIM"��ҥ�ԡ�����Ů��"+str+"�Ѿ�ѡ����PK������·�������֪�ա�\n"NOR,users());
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����PK������·���Ժ����Ϊ֮������\n",who);
who->set("ziyouchoose","pk");
who->set("pk","pk");
who->set("ziyou","got");
return 1;
}
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
message("channel:chat",HIC"����Ե������Ů��"+str+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�\n"NOR,users());
message("channel:rumor",HIM"��ҥ�ԡ�����Ů��"+str+"�Ѿ�ѡ����NOPK������·������Ժ�Ҫ��Ϊ�����ˡ�\n"NOR,users());
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�ѡ����NOPK������·���Ժ�������˵�æ����\n",who);
who->set("ziyouchoose","nopk");
who->set("nopk","nopk");
who->set("ziyou","got");
return 1;
}
}

int gift()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyougift")=="got")	
{
message_vision("����Ů�����$N˵�������Ѿ��ù��ˣ����˲�Ҫ̫̰�ĺá���\n",who);
return 1;
}
else
if (this_player()->query("obstacle/number") < 34 )
{
message_vision("����Ů�����$N˵����������ȡ����û����ɣ�����Ŭ������\n",who);
return 1;
}
else
if (this_player()->query("dntg/number") < 10 )
{
message_vision("����Ů�����$N˵����������칬��û����ɣ��ɹ����������ְ�����\n",who);
return 1;
}
else
{
str=who->name();
message("channel:chat",HIC"����Ե������Ů��"+str+"�Ѿ�������ȡ���������칬���ѹأ��ش˽�����\n"NOR,users());
message("channel:rumor",HIM"��ҥ�ԡ�����Ů��"+str+"�Ѿ�������ȡ���������칬���ѹأ��ش˽�����\n"NOR,users());
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�������Ѿ�������ȡ���������칬���ѹأ��ش˽�������\n\n"HIC"$N�õ�20����ѧ��500����С�3000���ƽ����л������Լ�2��Ľ�����\n"NOR,who);
who->add("combat_exp", 200000 );
who->add("daoxing", 500000 );
who->add("potential", 100000 );
who->add("balance", 30000000 );
who->add("str", 2 );
who->add("cor", 2 );
who->add("int", 2 );
who->add("spi", 2 );
who->add("cps", 2 );
who->add("per", 2 );
who->add("con", 2 );
who->add("kar", 2 );
who->set("ziyougift", "got" );
return 1;
}
}

int back()
{
string str;
object who = this_player();
object ob = this_object();
if (this_player()->query("ziyouback")=="got")
{
message_vision("����Ů�����$N˵������������Ѿ�����һ���ˣ����˻��ǲ�Ҫ̫�����޳��ã���\n",who);
return 1;
}
else
{
str=who->name();
message_vision("����Ů���ھ����ѣ���$Nͷ������һ������$N˵�����������Ѿ�����ѡ�����������·����\n",who);
who->delete("ziyouchoose");
who->delete("ziyou");
who->set("ziyouback","got");
return 1;
}
}

//���񽣷�
int bainiao_jian()
{
object who = this_player();
if(who->query_skill("bainiao-jian",1)>200&&who->query_skill("bainiao-jian",1)%10==0)
{
tell_object(who,HIW"�ðɣ�Ϊ��İ��񽣷��Դ�����������һ����������\n"NOR);
tell_object(who,HIW"����Ϊ�����񽣷���ɱ��\n"NOR);
(: call_other, __FILE__, "bainiao_jian_name_skill", who:);
}
return 1;
}

void bainiao_jian_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_bainiao-jian");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+2*who->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   msg= "$N�����Դ�����"HIR"�����񽣷���ɱ����"NOR"�����е�$w�����ƻ���ֱȡ$n��$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_bainiao-jian",m_actions);
}

//�粨ʮ����
int fengbo_cha()
{
object who = this_player();
if(who->query_skill("fengbo-cha",1)>200&&who->query_skill("fengbo-cha",1)%10==0)
{
tell_object(who,HIW"�ðɣ�Ϊ��ķ粨ʮ�����Դ�����������һ����������\n"NOR);
tell_object(who,HIW"����Ϊ���粨ʮ�����ɱ��\n"NOR);
(: call_other, __FILE__, "fengbo_cha_name_skill", who:);
}
return 1;
}

void fengbo_cha_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_fengbo-cha");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+who->query_skill("unarmed",1)/5;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   msg= "$N�����Դ�����"HIR"���粨ʮ�����ɱ����"NOR"�����е�$w�����ƻ���ֱȡ$n��$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_fengbo-cha",m_actions);
}

//�ֻ���
int lunhui_zhang()
{
object who = this_player();
if(who->query_skill("lunhui-zhang",1)>200&&who->query_skill("lunhui-zhang",1)%10==0)
{
tell_object(who,HIW"�ðɣ�Ϊ����ֻ����Դ�����������һ����������\n"NOR);
tell_object(who,HIW"����Ϊ���ֻ��ȱ�ɱ��\n"NOR);
(: call_other, __FILE__, "lunhui_zhang_name_skill", who:);
}
return 1;
}

void lunhui_zhang_name_skill(string arg)
{
   object who = this_player();
   mapping* m_actions;
   mapping m_act=([]);
   int content;
   string msg;

   m_actions=who->query("skill_lunhui-zhang");
   if(!pointerp(m_actions))m_actions=({});

   content=who->query("str")+2*who->query_skill("unarmed",1)/10;
   m_act+=(["damage":content]);
   content=-who->query("spi");
   m_act+=(["dodge" :content]);
   content=-who->query("cps");
   m_act+=(["parry" :content]);
   content=who->query("con")+who->query_skill("force",1)/10;
   m_act+=(["force" :content]);
   m_act+=(["damage_type":"����"]);

   msg= "$N�����Դ�����"HIR"���ֻ��ȱ�ɱ����"NOR"�����е�$w�����ƻ���ֱȡ$n��$l";
   m_act+=(["action":msg]);
   m_actions+=({m_act});
   who->set("skill_lunhui-zhang",m_actions);
}

�
