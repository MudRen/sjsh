#include <ansi.h>

inherit ITEM;
string *names = ({ "���ֶ�", "�ı���", "���Ĺ�","����","�ϵ»�" });
string *msg_eat=({HIR"$N���ſ��ֶ������˵Ľе�:�Һ�happy,�Һ�happy..\n",
                  HIC"$N�ѱı��ǷŶ������������ž��һ������,�����ޱ��泩.\n",
                  HIM"$Nһ�߳��ſ��Ĺ�,һ�߻������Լ���MUD�гɳ��ľ���,���Ǹп���ǧ..\n",
                  HIY"$N����������������ͼ��ᣬ�ж��Ŀ�ˮֱ��.\n",
                  HIG"$N������ϵ»��������ͼ��飬һ���������������.\n",                  
                        });
                        
int do_eat(string arg);
void create()
{
  int num;
  num=random(sizeof(names));
  set_name(names[num],({"gift"}));
  
  set("unit","��");
  set("value", 0);
  set("long","ף�����µ�һ���﹤��˳����ѧϰ���������彡�����������⣡");
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","���������ռ�ڵ��ϣ���ôҲ�ò�������\n");
    set("no_give","����ˣ��������ﻹ����?\n");
    set("no_drop","��ô����������˶��ϧѽ��\n");
    set("no_sell","�ⶫ����������\n");
   }
  if(this_player()==environment())
  add_action("do_eat", "eat");

}

int do_eat(string arg)
{
  string msg;
  object me=this_player();  
  int get_qn,get_wx,get_dx;
  int my_exp,my_dx,my_kar;

  if (!arg && arg!="gift")
    return notify_fail("��Ҫ��ʲô?\n");  

  if (this_object()->query("owner")!=me->query("id"))
    return notify_fail("��ͻȻ���÷�θ���ԵĶ��������˳���!\n");  
	    
//  msg=msg_eat[random(sizeof(msg_eat))];  
  if (this_object()->query("name")=="���ֶ�")
  msg=msg_eat[0]; 
  if (this_object()->query("name")=="�ı���")
  msg=msg_eat[1];  
  if (this_object()->query("name")=="���Ĺ�")
  msg=msg_eat[2];  
  if (this_object()->query("name")=="����")
  msg=msg_eat[3];  
  if (this_object()->query("name")=="�ϵ»�")
  msg=msg_eat[4];  

  message_vision(msg+"\n"NOR, me );  
  
  my_exp=me->query("combat_exp");
  my_dx=me->query("daoxing");
  my_kar=me->query("kar");

   get_qn=(random(2000)+6000)*my_kar/39;
   get_wx=(random(10000)+20000)*my_kar/39;
    get_dx=(random(1000)+6000)*my_kar/39;
  if ((my_exp+my_dx)<1000000)
  {
	get_qn=get_qn/2;
	get_wx=get_wx/2;
	get_dx=get_dx/2;
  }
  
  if (random(2)*random(2)*random(2)*random(2)*random(2)*random(2))
  {
	get_qn=get_qn*2;
	get_wx=get_wx*1.5;
	get_dx=get_dx*1.2;
  }

if ((my_exp+my_dx)<100000)
  {
         get_qn=2000+random(500);
         get_wx=3000+random(500);
         get_dx=1000+random(500);
  }

  me->add("potential",get_qn);  
  me->add("combat_exp",get_wx);
  me->add("daoxing",get_dx);
  
  tell_object(me,HIW"��Ľ����ǣ�\n" +
  chinese_number(get_wx) + "����ѧ\n"+        
  COMBAT_D->chinese_daoxing(get_dx) + "����\n"+        
  chinese_number(get_qn) + "��Ǳ��\n" NOR);
    
  destruct(this_object());
  return 1;
}

