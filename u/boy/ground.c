// by boy
#include <ansi.h>
inherit ROOM;
#include "/d/kaifeng/ground.h"
void create()
{
   set ("short","��̨");
  set ("long",@LONG
           ��  ��  ��  ��         ��  ��  ��  ͨ
LONG);
  set("no_quit",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("exits",([ ]));
  setup();
}
void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "surrender") return 1;
      if (verb == "ji") return 1;     return 0;
}
void alternative_die (object me)
{
    string msg;
  object ob = me->query_temp("last_damage_from");
    if (me->query("kee")<0) me->set("kee",5);
    if (me->query("eff_kee")<0) me->set("eff_kee",5);
  if (! userp(me))
{
      message_vision ("\n$N�ҽ�һ��,���������ʧ����Ӱ���١�\n",me);
    destruct(me);
    return;
}
if (ob->query_temp("objectob")!=me->query("id")&&me->query_temp("objectob")!=ob->query("id"))
    return;
    if (! ob)
           return;
  me->remove_killer(ob);
  ob->remove_killer(me);
msg=HIM"��˵"+HIW+ob->query("name")+HIM"����̨��Ӯ��"+HIW+me->query("name")+NOR;
         CHANNEL_D->do_channel(this_object(),"rumor",msg);
  message_vision(HIG"$n��$N���ڵأ�����һ�ţ���$N��������̨��\n"NOR,me,ob);
  message_vision(HIG"$n�ڹ��ڵĻ������У��߸����˵��³���Ϣ�ˡ�\n"NOR,me,ob);
  tell_room( __DIR__"under","\n>\n\n");
  me->move(__DIR__"under");
  ob->move(__DIR__"under");
   me->set("kee",(int)me->query_temp("statusbef/kee"));
   me->set("eff_kee",(int)me->query_temp("statusbef/eff_kee"));
   me->set("sen",(int)me->query_temp("statusbef/sen"));
   me->set("eff_sen",(int)me->query_temp("statusbef/eff_sen"));
   me->set("force",(int)me->query_temp("statusbef/force"));
   me->set("mana",(int)me->query_temp("statusbef/mana"));
   ob->set("kee",(int)ob->query_temp("statusbef/kee"));
   ob->set("eff_kee",(int)ob->query_temp("statusbef/eff_kee"));
   ob->set("eff_sen",(int)ob->query_temp("statusbef/eff_sen"));
   ob->set("sen",(int)ob->query_temp("statusbef/sen"));
   ob->set("force",(int)ob->query_temp("statusbef/force"));
   ob->set("mana",(int)ob->query_temp("statusbef/mana"));
  me->set("no_move",0);
me->start_busy(0);
  ob->set("no_move",0);
ob->start_busy(0);
    ob->delete_temp("objectob");
    me->delete_temp("objectob");
}
void broadcast(string str)
{
  string prefix = HIY"����̨��"NOR;
  string s1 = str, s2 = "";
  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");
  if (s1[strlen(s1)-1]=='\n')
{
    s1 = s1[0..strlen(s1)-2];
    s2 = "\n";
}
  if (strlen(s1) == 0)
    return;
  s1 = replace_string(s1,"\n","\n"+prefix)+"";
  reset_eval_cost();
  tell_room( __DIR__"under","\n"+prefix+s1 );
}
