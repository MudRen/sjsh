#include <ansi.h>
inherit ITEM;
#define DEBUG 0
mapping sldher;

void create ()
{
    set_name("ˮ½��ᷢ����", ({ "fajiang qi","qi"}) );
    set ("long", @LONG

����һ������ʦʹ�õ�ˮ½��ᷢ��������ˮ½�����ɺ󣬸���
��������ʦ����ʹ�������ƷΪ�μ�ˮ½��ἰ�񽱹ھ�������

ָ���ʽ��
        sure ��ҵ�ID �ھ���ı�־��
        ����:sure id first (��ʾ���ھ�id����)
             sure id      (��ʾ����ͨ��ҷ�������)

���÷�����׼Ϊ2000���¶���׼��

LONG);
    set("unit","��");
    set("type", "misc");
    setup();
}

void init ()
{
   add_action("do_sure","sure");
}

void announcing (string str)
{
  if (DEBUG)
  {
    object smile = find_player ("smile");

    if (wizardp(smile))
      tell_object (smile," @** "+str);
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

int do_sure(string arg)
{
  object who=this_player();
  object ob=this_object();
  object sldher;
 object gold,guo;
  string id,firsts="";
 int i=0,dx=0,first=0;
   
    if(!wizardp(who)) {
         tell_object(who,"��û��Ȩ�޻��������壬û��Ȩ��ʹ��������\n");
         tell_room(environment(who),ob->name()+"�����ˡ�\n");
         destruct(ob);
          return 1;
        }

    if(!arg) 
         return notify_fail("��Ҫ����˭�ý���\n");
    if(!sscanf(arg,"%s %s",id,firsts)) 
      if(!sscanf(arg,"%s",id))
         return notify_fail("����Ĳ��������е����⡣\n");
    if(firsts=="first") first=1;
    sldher=find_player(id);
    if(!sldher)
         return notify_fail("��λ��һ�û������������ء�\n");
    if(!environment(sldher))
         return notify_fail("��λ��һ�û������������ء�\n");
   
  if(ob->query(id))
   {
    tell_object(who,sldher->name()+"�Ѿ��ù������ˣ��ɲ��ܷ��ڶ��Ρ�\n");
    return 1;
   }
  else {
     dx=sldher->query("combat_exp");
    if(dx<1000) {
        tell_object(who,sldher->name()+"�ĵ��в���һ�꣬û���ʸ��ý�����\n");
        return 1;}
    if(dx>0&&dx<=10000) i=0;
    if(dx>10000&&dx<=50000) i=1;
    if(dx>50000&&dx<=150000) i=2;
    if(dx>150000&&dx<=300000) i=3;
    if(dx>300000&&dx<=500000) i=5;
    if(dx>500000&&dx<=1000000) i=10;
    if(dx>1000000&&dx<=2000000) i=15;
    if(dx>2000000&&dx<=3000000) i=25;
    if(dx>3000000&&dx<=5000000) i=40;
    if(dx>5000000) i=50;
       ob->set(sldher->query("id"),1);
       tell_object(sldher,HIG"�����ڻ�ñ���ˮ½��ά�����£�\n"NOR);
    tell_object(sldher,  "      "+chinese_number(1000*i)+"��Ǳ�ܣ�\n");
    sldher->add("potential",500*i);
    sldher->add("sldh/qn",500*i);
    sldher->add("sldh/enter",1);
    if(first) {
       sldher->add("sldh/first",1);
    if(dx<=300000) {
     tell_object(sldher,"      �������ƽ�\n");
        gold=new("/u/pkl/300gold");
        gold->move(sldher);
       }
    if(dx>300000&&dx<=1000000) {
       tell_object(sldher,"      һ����Ǳ�ܵ���\n");
        guo=new("/d/obj/drug/qnd");
        guo->move(sldher);
       }
    if(dx>1000000&&dx<=3000000) {
       tell_object(sldher,"      ������Ǳ�ܵ���\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       }
    if(dx>3000000&&dx<=5000000) {
       tell_object(sldher,"      ����Ǳ�ܵ���\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       }
    if(dx>5000000) {
       tell_object(sldher,"      �ĸ�Ǳ�ܵ���\n");
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
       guo=new("/d/obj/drug/qnd");
       guo->move(sldher);
      }
      }
           tell_object(who,first==1?"�ھ�":"��ͨ���"+sldher->query("name")+"  ��ý�����\n");
           announce("����ˮ½���"+sldher->name()+"("+sldher->query("id")+")"+"  ��ý�����");
       }
    return 1;
       }


