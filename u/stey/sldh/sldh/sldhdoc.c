// /d/kaifeng/obj/sldhdoc.c
//ʹ�ø����������������ñ����ߵ�״̬��Ϣ��
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

#define DEBUG 0
#define BAOMINGSHI "/d/kaifeng/npc/baomingshi"
#define ZHONGLOU   "/d/city/zhonglou"
#define WEI        "/d/kaifeng/npc/wei"
#define SLDHGROUND "/d/kaifeng/ground"

private string listone(int num);
private string list(string arg);

void create()
{
        set_name("ˮ½��ᱨ����", ({ "sldhdoc" }));
        set("long","
����ˮ½��ᱨ�����嵥������ʦʹ��help sldhdoc���鿴
������Ϣ��\n");        
        if (clonep()) {
          set_default_object(__FILE__);

          set("unit","��");
          set("weight",3000);
         }       
        setup();
}

string query_save_file()
{
  return this_object()->query("file_name");
}

int do_help(string arg)
{
 object who=this_player();
 string msg;
 if(!who) return 0;
 if(arg!="sldhdoc") return 0;
  msg="\nˮ½��ᱨ������Ҫ��Ϊ��ʦ�������ˮ½���Ľ��ж�д��\n";
 msg+="������ʦ����ʹ��startreport�ڳ�����¥��������ʹ�����\n";
 msg+="���ã���ʼ������ע�ⲻҪ���ظ��ı���ʹ���������������\n";
 msg+="�����������������update��¥������ʹʹ�÷����뵽����ʹ\n";
 msg+="���help report�鿴��Ȼ����initָ��ˮ½����������\n";
 msg+="lists�鿴�����ߣ���set��unsetһϵ������������ù�����\n";

 msg+="��dofight xxx��xxx1��ˮ½\n";
 msg+="��᳡�ؽ��о������\n";
 msg+="��Ҫ������ܣ�\n";
 msg+="һ����������ʹ�ߣ���֪ˮ½������������Ϊstartreport��\n";
 msg+="������ʼ��������init��ʹ�÷���init [n] n�Ǳ�ʾˮ½��������\n";
 msg+="��������lists��ʹ�÷���lists [n] n��ʾ�����ʹ�ò�����ʾȫ����\n";
 msg+="����������һ������ˮ½���Ľ������Ժ�ʹ��ʱ��ָ������\n";
 msg+="��������ȱʡ�������ϴ�ָ���Ľ�����\n";
 msg+="�ġ��������ù��ܣ�һ���У����������ʹ�ò�������ͬ��\n";
 msg+="����[un]set_xxxxx [n] [id] ��������������£�\n";

 msg+="��������  xxxxxΪ�������ͣ�n��ʾ���idΪ��ұ�ʶ�š�\n";
 msg+="��������������£�\n";
 msg+="����set_price�����������û�Ϊ�ѻ��������\n";
 msg+="����unset_price����ȡ���û��Ļ�״̬��\n";
 msg+="����set_fight�����������û�Ϊ�ѱ�����\n";
 msg+="����unset_fight����ȡ���û��ı���״̬��\n";

 msg+="����set_winner���� �����û�Ϊ����ھ�������\n";
 msg+="����unset_winner�� ȡ���û��Ĺھ��ƺš�\n";
 msg+="�塢��������ҵľ����������dofight xxx xxx1������Ϊ�����\n";
 msg+="������ID����������Զ����òμӹ����������״̬��������ھ���\n";
 msg+="����������ʦ���á�\n";
 msg+="��¼��������ɫ��˵����ʹ��lists�б�������ɫ�����Ϊ�õ�������\n";
 msg+="������ɫ��Ϊ�������ģ���ɫΪ�����ߣ���ɫΪ�ھ�������\n\n";
 msg+="\n ���������꣯���¡�����\n";
 tell_object(who,msg);
 return 1; 
}

void init()
{
 add_action("do_start","startreport");
 add_action("do_init","init");
 add_action("do_lists","lists");
 add_action("do_price","set_price");
 add_action("do_fight","set_fight");
 add_action("do_winner","set_winner");
 add_action("do_unwinner","unset_winner");
 add_action("do_unfight","unset_fight");
 add_action("do_unprice","unset_price"); 
 add_action("do_dofight","dofight");
 add_action("do_help","help");
}

int do_start()
{

 object who=this_player();
 object ob;
 object room;
 if(!who)
  return 0;
 if(!wizardp(who))
  return notify_fail(HIG"\n��û��ʹ����������Ȩ�ޡ�\n"NOR);
 room=load_object(ZHONGLOU);
if(present("sldh baoming shi",room)) 
 return notify_fail(HIG"\n��¥������һ��ˮ½��ᱨ��ʹ�����ȸ�����¥��\n"NOR);
 ob=new(BAOMINGSHI);
 ob->move(ZHONGLOU);
 who->move(ZHONGLOU);
 tell_object(who,HIY"\n�����Ѿ�����ˮ½��ᱨ���������Ժ����������ñ���\n"+
                 "�����������������ʹ���뵽ʱhelp report�ο�������\n"NOR);
 return 1;
}

int do_init(string arg)

{
 object who=this_player();
 int num;
 if(!who) return 0;
 if(!wizardp(who))
  return notify_fail("��û��ʹ����������Ȩ�ޡ�\n");
 
 if(!arg) return notify_fail("���ð��������ֲ����趨ˮ½������������init 1��ʾ��һ��ˮ½��ᡣ\n");
 if(sscanf(arg,"%d",num)!=1)
   return notify_fail("������ֲ�����ָ���ڼ���ˮ½��ᡣ\n");
 set("sldh_num",num);
 return 1;      
}

int do_lists(string arg)
{
 object who=this_player();
 int num;
 if(!who) return 0;
 if(!(num=query("sldh_num")))
  return notify_fail("��������init�趨ˮ½������������init 1��ʾ��һ��ˮ½��ᡣ\n");
 
   set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",query("sldh_num")));
   if(file_size(query("file_name")+".o")==-1)
    return notify_fail("û�����ˮ½��ᣬ���趨��ȷ��ˮ½��������\n");
   restore();
   set("sldh_num",num); 

   set("unit","��");
   set("weight",3000);  
   tell_object(who,list(arg));
  return 1;
}

private string listone(int num)
{
 int i;
 string msg,kindstr,str;
 mapping kindlist,joinerlist,typestr; 
 string *list,type;
 
 kindstr=sprintf("%d",num);
 kindlist=([]);
 kindlist=query("kindlist");
 joinerlist=query("joiner");
 typestr=query("typestring");
 type=query("type");
 str="\n";
 if(mapp(kindlist))
  msg="����"+chinese_number(num)+typestr[type]+"("+HIR+
       chinese_number(kindlist[kindstr]["min_num"])+"����"+

       chinese_number(kindlist[kindstr]["max_num"])+"��"+NOR+")��\n";
 if(mapp(joinerlist)&&mapp(joinerlist[kindstr]))
  {
   list=keys(joinerlist[kindstr]);
   if(!list) msg+="������û����Ҳμӱ�����\n";
   else
   { 
     if(sizeof(list)==0) {
        msg+="������û����Ҳμӱ�����\n";
        return msg;
      } 
     
     for(i=1;i<=sizeof(list);i++) {
       string str1;
       str1=sprintf("%-10s",list[i-1]);
       if((i%7)==0) str1=str1+"\n\n";
       if((i%7)==1) str1="��"+str1;

       if(joinerlist[kindstr][list[i-1]]["winnum"]>0)
         str1=HIY+str1+NOR;  
       else if(joinerlist[kindstr][list[i-1]]["price"]=="Y")
               str1=HIG+str1+NOR;
            else if(joinerlist[kindstr][list[i-1]]["fight"]=="Y")
                  str1=HIW+str1+NOR;
                 else str1=HIC+str1+NOR;
       str+=str1;
      } 
     (i-1)%7!=0?str+="\n\n":str=str;
     msg+=str;
     msg+=HIW+"���ܹ�"+chinese_number(sizeof(list))+"����Ҳμӱ��鱨����"+NOR+"\n";
     if(!query("total_num")) set("total_num",sizeof(list));
     else set("total_num",query("total_num")+sizeof(list));
   }
  }
 else msg+="������û����Ҳμӱ�����\n";
 return msg;
}

private string list(string arg)
{
 int i,num,kinds;
 string msg,str;
 
 num=-1;
 set("total_num",0);
 msg=HIY"��"+chinese_number(query("sldh_num"))+"��ˮ½�����鼰�������б�\n"NOR;
 msg+=HIG"������������������������������������������������������������������������������������"NOR+"\n";

 kinds=query("kinds");
 if(!arg||sscanf(arg,"%d",num)!=1) {
  if(kinds>0)
   for(i=1;i<=kinds;i++) {
    msg+=listone(i);
    if(i!=kinds) 
     msg+=HIG"�š���������������������������������������������������������������������������������"NOR+"\n";    
   }
 } 
 else if(num!=-1){
     msg+=listone(num);         
 }      
 msg+=HIG"������������������������������������������������������������������������������������"NOR+"\n";       
 str=sprintf("%70s","�ܹ���"+chinese_number(query("total_num"))+"����Ҳμӱ���ˮ½��ᱨ��");
 str=HIY+str+NOR+"\n\n";
 msg+=str;
 return msg;
}

int notify_failed(object ob,string str)
{
 if(!ob) return 0;
 tell_object(ob,str);

 return 1; 
}

//������Ӧ��kind���Ƿ���ָ�����û�
int user_in_kinds(string id,int kind)
{
 mapping joiner;
 string kindstr;
 int i,kind1;
 string *list;
 object me=this_object();
 
 if(!mapp(me->query("kindlist")))
   return 0;//����false��ʾû�з���
 if(!(kind1=me->query("kinds")))
   return 0;//����false��ʾû�з���
 if(kind>kind1 || kind<1)
   return 0;//����false��ʾû�з���
 kindstr=sprintf("%d",kind);
 joiner=([]);
 joiner=query("joiner");
 if(!mapp(joiner)&&!mapp(joiner[kindstr]))
   return 0;

 list=keys(joiner[kindstr]);  
 for(i=0;i<sizeof(list);i++)
   if(list[i]==id) return 1;//����true
 return 0;
}

private int set_property(object who,int type,string arg)
{
 string id;     
 int kind;
 mapping joiner=([]);
 string kindstr;
 if(!who) return 0; 
 if(!arg)
   return notify_failed(who,"��Ҫ��ʲô��\n");
 if(!wizardp(who))
   return notify_failed(who,"�㲻����ʦ����Ȩ���ñ�����Ϣ��\n");
 if(sscanf(arg,"%d %s",kind,id)!=2)
   return notify_failed(who,"���ò����������ԡ�����set_price 1 smile\n");
 if(!user_in_kinds(id,kind))

   return notify_failed(who,"�������û����������ߡ�\n");
 joiner=query("joiner"); 
 kindstr=sprintf("%d",kind);  

 switch(type) {
  //set 
  case 1: joiner[kindstr][id]["price"]="Y";
          save();
          return notify_failed(who,"����"+sprintf("%d��%sΪ",kind,id)+"�ѻ�����\n"); 
  case 2: joiner[kindstr][id]["fight"]="Y";
          save();
          return notify_failed(who,"����"+sprintf("%d��%sΪ",kind,id)+"�ѱ�����\n"); 
  case 3: joiner[kindstr][id]["winnum"]=1;
          save();
          return notify_failed(who,"����"+sprintf("%d��%sΪ",kind,id)+"�ھ���\n"); 
  //unset        

  case 4: joiner[kindstr][id]["price"]="N";
          save();
          return notify_failed(who,"ȡ��"+sprintf("%d��%s��",kind,id)+"����״̬��\n"); 
  case 5: joiner[kindstr][id]["fight"]="N";
          save();
          return notify_failed(who,"ȡ��"+sprintf("%d��%s��",kind,id)+"����״̬��\n"); 
  case 6: joiner[kindstr][id]["winnum"]=0;
          save();
          return notify_failed(who,"ȡ��"+sprintf("%d��%s��",kind,id)+"�ھ��ƺš�\n"); 
  }     
}

int do_price(string arg)
{
  object who=this_player();     
 return set_property(who,1,arg);
}

int do_fight(string arg)
{
  object who=this_player();     
 return set_property(who,2,arg);
}

int do_winner(string arg)
{
  object who=this_player();     
 return set_property(who,3,arg);
}

int do_unprice(string arg)
{
  object who=this_player();     
 return set_property(who,4,arg);
}
int do_unfight(string arg)
{
  object who=this_player();     
 return set_property(who,5,arg);
}

int do_unwinner(string arg)
{
  object who=this_player();     
 return set_property(who,6,arg);
}

void announcing (string str)
{
  if (DEBUG)
  {
    object smile = find_player ("smile");
    if (wizardp(smile))
      tell_object (smile,"ˮ½��᣺"+str);
  } else
    {

     object wei = load_object (WEI);
     wei->command_function("chat "+str);
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


//���ҳ��û���Ӧ�����
int query_user_kinds(object who)
{
 mapping kindlist;
 string kindstr;
 string type;
 int kind,i,num;
 object me=this_object();
 
 if(!who) return 0;
 if(!mapp(me->query("kindlist")))
   return 0;//����false��ʾû�з���
 kindlist=me->query("kindlist");
 if(!(kind=me->query("kinds")))
   return 0;//����false��ʾû�з���
 type=me->query("type");
 if(type=="1") num=who->query("age");
 else if(type=="2") num=who->query("combat_exp")/1000;
      else return 0;
      
 for(i=1;i<=kind;i++)
  {
   kindstr=sprintf("%d",i);

//�����[min_num,max_num]�����Ǿͷ���������
   if(   num>=kindlist[kindstr]["min_num"] 
      && num<=kindlist[kindstr]["max_num"] )
     return i;//�������
  }
 return 0;
}

private void fullstate(object who)
{
 who->delete_temp("apply/id");
 who->delete_temp("apply/name");
 who->delete_temp("apply/short");
 who->delete_temp("apply/long");
 who->set("sen",who->query("max_sen"));
 who->set("eff_sen",who->query("max_sen"));
 who->set("kee",who->query("max_kee"));
 who->set("eff_kee",who->query("max_kee")); 

 who->set("water",who->query("max_water"));
 who->set("food",who->query("max_food"));
 who->set("force",who->query("max_force"));
 who->set("mana",who->query("max_mana"));
 who->delete_temp("no_move");

 who->clear_condition();
 message_vision(HIG"ˮ½��ʿ��$N����һ�Ż��굤��$Nֻ���þ���ȫ�ָ��ˡ�\n",who);
}

void start_fight(object player1,object player2)
{
 string id1,id2;
 if(!player1 || !player2) return;

 reset_eval_cost(); 
 fullstate(player1);
 fullstate(player2);
 player1->kill_ob(player2);
 player2->kill_ob(player1);
}

int do_dofight(string arg)
{
  object who=this_player();
  object player1,player2;
  string id1,id2;
  int i,j;
  

  if(!who)
   return 0; 
  if(!wizardp(who))
   return notify_fail("��û��ʹ����������Ȩ�ޡ�\n");
  if(!query("sldh_num"))
   return notify_fail("���ȳ�ʼ����Ȼ����lists�б���ʾһ�Ρ�\n");
  if(!arg||sscanf(arg,"%s %s",id1,id2)!=2)
   return notify_fail("��ָ������������ҽ���ս��������dofight smile smile1\n");
  if(!(player1=find_player(id1))) 
   return notify_fail("û�������ң�"+id1+"\n");
  if(!(player2=find_player(id2)))
   return notify_fail("û�������ң�"+id2+"\n");
   i=query_user_kinds(player1);
   j=query_user_kinds(player2);
  if(i!=j)
   return notify_fail("��������Ҳ���ͬһ�����ġ�\n");
  if(player1->query_temp("netdead"))
   return notify_fail(sprintf("%s(%s)���ڶ����У����ܲ��������\n",player1->query("name"),id1)); 
  if(player2->query_temp("netdead"))
   return notify_fail(sprintf("%s(%s)���ڶ����У����ܲ��������\n",player2->query("name"),id2)); 
  if(!present("wei zheng",environment(who)))
   return notify_fail("κ���˲��ڳ������ܿ�ʼ�����أ�\n");
  if(!environment(who))
   return notify_fail("�������ƾ���ŵ���˼����֮�أ����ܽ��б������\n");
  if(!environment(who)->query("match_ground"))
   return notify_fail("���ﲻ��ˮ½�����б����ĵط������ܽ��б������\n");
  //����fight״̬ 
  set_property(who,2,sprintf("%d %s",i,id1));
  set_property(who,2,sprintf("%d %s",j,id2));
  message_vision(HIR+sprintf("%s��һֻ�������ץ���ˡ�\n",player1->query("name"))+NOR,who);
  player1->move(SLDHGROUND);
  message_vision(HIR+sprintf("%s��һֻ�������ץ���ˡ�\n",player2->query("name"))+NOR,who);
  player2->move(SLDHGROUND);
  message_vision(HIR+sprintf("%s��%s��һ˫����ץ�˹�����\n",player1->query("name"),player2->query("name"))+NOR,who);
  announce(sprintf("���������� %s(%s) VS %s(%s)",player1->query("name"),id1,player2->query("name"),id2));
  remove_call_out("start_fight");
  call_out("start_fight",5,player1,player2);
  return 1;
}
