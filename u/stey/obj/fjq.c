// ������
#include <ansi.h>
inherit ITEM;
#define DEBUG 0
mapping sldhwho;

void create ()
{
    set_name("������", ({ "fajiang qi"}) );
    set ("long", @LONG
����һ������ʦר�÷�������
ָ���ʽ��
        jiangli ��ҵ�ID �ھ���ı�־��
        ����:jiangli angel no1   (��ʾ���ھ�angel����)
             jiangli angel       (��ʾ����ͨ��ҷ�������)
        jiangall ��������������Ա��
LONG);
    set("unit","��");
    set("type", "misc");
    setup();
}
void init ()
{
   add_action("do_jiangli","jiangli");
   add_action("do_jiangall","jiangall");
}
void announcing (string str)
{
  if (DEBUG)
  {
    object angel = find_player ("angel");
    if (wizardp(angel))
      tell_object (angel,"  ע�ⷢ����=>"+str);
  }
  else
  {
    object wei = load_object ("/d/kaifeng/npc/wei");
    wei->command_function("sldh "+str);
  }
}
void announce (string str)
{
  string s = str;
  int i, j;
  while ((i = strlen(s)) > 0)
  {
    j = strsrch (s, "\n");
    if (j < 0)
    {
      announcing (s);
      return;
    }  
    announcing (s[0..j]);
    s = s[j+1..i];
  }
}
int do_jiangli(string arg)
{
  object who=this_player();
  object ob=this_object();
  object sldhwho;
  object gold,guo;
  string id,no1s="";
 int i=0,dx=0,no1=0;
    if(!wizardp(who)) {
         tell_object(who,"��û��Ȩ��ʹ��������\n");
         tell_room(environment(who),ob->name()+"�ڿն�ȥ��\n");
         destruct(ob);
          return 1;
        }
    if(!arg) 
         return notify_fail("��Ҫ��˭������\n");
    if(!sscanf(arg,"%s %s",id,no1s)) 
      if(!sscanf(arg,"%s",id))
         return notify_fail("����Ĳ��������е����⣬��(look fajiang qi)�鿴��\n");
    if(no1s=="no1") no1=1;
    sldhwho=find_player(id);
    if(!sldhwho)
         return notify_fail("û�ҵ���˵������ˣ�\n");
    if(!environment(sldhwho))
         return notify_fail("û�ҵ���˵������ˣ�\n");
  if(ob->query("sldh/"+id))
   {
    tell_object(who,sldhwho->name()+"�Ѿ��ù������ˣ��ɲ��ܷ��ڶ��Ρ�\n");
    return 1;
   }
  else {
     dx=sldhwho->query("combat_exp");
    if(dx<10000) {
        tell_object(who,sldhwho->name()+"����ѧ���ͣ����ܸ�������\n");
        return 1;}
    if(dx>10000&&dx<=100000) i=0;
    if(dx>100000&&dx<=500000) i=2;
    if(dx>500000&&dx<=1000000) i=4;
    if(dx>1000000&&dx<=1500000) i=6;
    if(dx>1500000) i=8;
       ob->set("sldh/"+sldhwho->query("id"),1);
    tell_object(who,"���"+sldhwho->query("name")+"��ý�����\n");
    tell_object(sldhwho,HIG"�����ڻ�ý������£�\n"NOR);
    tell_object(who,"  "+chinese_number(1500*i)+"��Ǳ�ܣ�\n");
    tell_object(sldhwho,"  "+chinese_number(1500*i)+"��Ǳ�ܣ�\n");
    sldhwho->add("potential",1500*i);
    if(no1) {
        tell_object(who,"  С���һ���ٸ�"+chinese_number(2000*i)+"��Ǳ�ܣ�\n");
        tell_object(sldhwho,"  С���һ���ٸ�"+chinese_number(2000*i)+"��Ǳ�ܣ�\n");
        sldhwho->add("potential",2000*i);
      }
           tell_object(who,no1==1?"С���һ"+sldhwho->query("name")+"��ý�����\n":"");
           announce(""+sldhwho->name()+"("+sldhwho->query("id")+")"+"��ý�����");
     }
    return 1;
}
int do_jiangall()
{
  int j;
  object who=this_player();
  object ob=this_object();
  object sldhwho;
  object *list;
    if(!wizardp(who)) {
         tell_object(who,"��û��Ȩ��ʹ��������\n");
         tell_room(environment(who),ob->name()+"�ڿն�ȥ��\n");
         destruct(ob);
          return 1;
  }
  list = users();
 j = sizeof(list);
  while (j--)
  {
    sldhwho = list[j];
  who->command_function("jiangli " + sldhwho->query("id") );
    }
  return 1;
}
