
#include <ansi.h>
inherit ROOM;
void create()
{
  set ("short",HIW "�� ̨" NOR);
  set ("long",@LONG
  
           ��  ��  ��  ��         ��  ��  ��  ͨ

LONG);
  set("no_quit",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("exits",([ ]));
  set("exits",(["west": __DIR__"parlour",]));
  setup();
}
  
void alternative_die (object me)
{
  object ob = me->query_temp("last_damage_from");
  if (me->query("kee")<0) me->set("kee",10);
  if (me->query("eff_kee")<0) me->set("kee",10);
  {string str;
  str=me->name()+"��"+ob->name()+"��"NOR+HIW"�� ̨"NOR+HIM"ɱ���ˡ�";
  message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());}
  me->remove_killer(ob);
  ob->remove_killer(me);
  message_vision(HIG"$n��$N���ڵأ�����һ�ţ���$N��������̨��\n"NOR,me,ob);
  message_vision(HIG"$n�ڹ��ڵĻ������У��߸����˵��³���Ϣ�ˡ�\n"NOR,me,ob);
  tell_room( __DIR__"parlour","\n>\n");
  me->move(__DIR__"parlour");
  ob->move(__DIR__"parlour");
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("force", (int)me->query("max_force"));
  me->set("mana", (int)me->query("max_mana"));
  me->add("combat_exp",-10000);
  me->add("daoxing",-10000);
  ob->set("gin", (int)ob->query("max_gin"));
  ob->set("eff_gin", (int)ob->query("max_gin"));
  ob->set("kee", (int)ob->query("max_kee"));
  ob->set("eff_kee", (int)ob->query("max_kee"));
  ob->set("sen", (int)ob->query("max_sen"));
  ob->set("eff_sen", (int)ob->query("max_sen"));
  ob->set("force", (int)ob->query("max_force"));
  ob->set("mana", (int)ob->query("max_mana"));
  ob->add("combat_exp",5000);
  ob->add("daoxing",5000);
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
  tell_room( __DIR__"parlour","\n"+prefix+s1 );
}
