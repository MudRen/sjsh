
//ˮ½��ᱨ��ʹ

// /d/kaifeng/npc/baomingshi.c
#include <ansi.h>
inherit NPC;
inherit F_SAVE;
#define DEBUG 0
#define DOC "/d/kaifeng/obj/sldhdoc" 
mapping JOINER=([]);

private int query_kinds(int min_num,int max_num);
private string listone(object who,int num);
void announce(string str);
int notify_failed(object ob,string str);
int start(object who,string arg);
int age(object who,string arg);
int dx(object who,string arg);
int delkind(object who,string arg);
int use(object who,string arg);
int closekind(object who);
int finish(object who);

int list(object who,string arg);
void announcing(string str)
{
  if (DEBUG) {
    object aoao = find_player ("aoao");
    if (aoao)
     if (wizardp(aoao))
       tell_object (aoao," �� "+str);
  }  else command_function("chat "+str);
}

void announce(string str)
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

int notify_failed(object ob,string str)
{
 if(!ob) return 0;
 tell_object(ob,str);
 return 1; 
}

int start(object who,string arg)
{
 string types;
 string str;
 mapping typestring;
 object me=this_object();
 object doc;
  if(!arg)
   return notify_failed(who,"����start age��start dx��ָʾ���α������õķ��ࡣ\n");


  types=lower_case(arg);
 if(types!="age"&&types!="dx") 
   return notify_failed(who,"��Ч�������࣬����age��dx��ָʾ���α������õķ��ࡣ\n");

  if(types=="age") me->set("type","1");
  if(types=="dx")  me->set("type","2");
  str=me->query("type")=="1"?"���������":"��ѧ������";
//initializing this_object's values
  me->set("min_combat_exp",15);
  me->set("min_age",14);
  me->delete("kinds");
  me->delete("kindlist");
  me->delete("ages");
  me->delete("dxs");
  me->delete("stop_report");
  typestring=([]);
  typestring["1"]="�������";
  typestring["2"]="��ѧ����";
  JOINER=([]);
  me->set("typestring",typestring);
  me->save();

  doc=new(DOC);
  doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
  doc->restore();
  doc->set("typestring",typestring);
  doc->set("type",query("type"));
  doc->save();
  destruct(doc);
  
  tell_object(this_player(),"����ˮ½��ᱨ������"+str+"\n");
  str="����ˮ½��ᱨ������"+str+"\n";
  announce(str);
  return 1;
}

//�����Ƿ�����ͬ����𣬻����ص������
int query_kinds(int min_num,int max_num)
{
 mapping kindlist;
 string kindstr;
 int kind,i;
 object me=this_object();
 

 if(!mapp(me->query("kindlist")))
   return 0;//����false��ʾû�з���
 kindlist=me->query("kindlist");
 if(!(kind=me->query("kinds")))
   return 0;//����false��ʾû�з���
 for(i=1;i<=kind;i++)
  {
   kindstr=sprintf("%d",i);
//������a1����[a2,b2],b1����[a2,b2],[a1,b1]����[a2,b2]���ֿ��ܡ�
   if((min_num>=kindlist[kindstr]["min_num"]&&min_num<=kindlist[kindstr]["max_num"])||
      (max_num>=kindlist[kindstr]["min_num"]&&max_num<=kindlist[kindstr]["max_num"])||
      (min_num<kindlist[kindstr]["min_num"]&&max_num>kindlist[kindstr]["max_num"]))
     return 1;//����true��ʾ���ַ�Χ
  }
 return 0;
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
int age(object who,string arg)
{
 int min_age,max_age;
 int kinds;
 string kindstr;
 mapping kindlist;
 object doc;
 object me=this_object();
 
 if(!arg) 
   return notify_failed(who,"��������Ϊ��!\n");
 if(me->query("type")!="1")
  return notify_failed(who,"�Բ��𣬱���ˮ½���ʹ�õĲ�����������ƣ������趨���䡣\n");
 if(sscanf(arg,"%d %d",min_age,max_age)!=2)
  return notify_failed(who,"����addage ��С���� �������������������顣\n"+

                           "ʾ����adddx 14 17 ��ʾ����һ��14��17��������顣\n");
 if(min_age>=max_age||min_age<me->query("min_age"))
  return notify_failed(who,"��С�������С��������估���ڵ���"+
                       chinese_number(me->query("min_age"))+"�ꡣ\n");
 if(query_kinds(min_age,max_age))
  return notify_failed(who,"�趨�����������ǰ���趨���������Χ���ص��ĵط���"+
                          "����lists�������ķ��飬Ȼ�����衣\n");
 if(!(kinds=me->query("kinds")))
    kinds=1;
 else kinds=me->query("kinds")+1;
 me->set("kinds",kinds);

 kindlist=([]);
 kindstr=sprintf("%d",kinds); 
 kindlist[kindstr]=([]);
 kindlist[kindstr]["min_num"]=min_age;
 kindlist[kindstr]["max_num"]=max_age;
//������Ҳ���������� 
 JOINER[kindstr]=([]);
 if(me->query("kindlist"))
   kindlist+=me->query("kindlist");
   
 me->set("kindlist",kindlist);

 tell_object(who,"�����������"+kindstr+"��"+chinese_number(min_age)+"����"+chinese_number(max_age)+"�ꡣ\n");
 me->save();
  doc=new(DOC);
  doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
  doc->restore();
  doc->set("kinds",kinds);
  doc->set("kindlist",kindlist);
  doc->save();
  destruct(doc);
  return 1;
  
}

int dx(object who,string arg)
{
 int min_dx,max_dx;
 int kinds;
 string kindstr;
 mapping kindlist;
 object doc;
 object me=this_object();
  
 if(!wizardp(who))
   return notify_failed(who,"��ʹ�õ�ָ����������ݡ�\n");
 if(!arg) return notify_failed(who,"��������Ϊ��!\n");
 if(me->query("type")!="2")
  return notify_failed(who,"�Բ��𣬱���ˮ½���ʹ�õĲ�����ѧ�����ƣ������趨��ѧ��\n");
 if(sscanf(arg,"%d %d",min_dx,max_dx)!=2)

  return notify_failed(who,"����adddx ��С��ѧ �����ѧ�����ӵ��з��顣\nʾ����adddx 300 1000 ��ʾ����һ��300��1000�����ѧ�顣\n");

 if(min_dx>=max_dx||min_dx<me->query("min_combat_exp"))
  return notify_failed(who,"��С��ѧ����С�������ѧ������"+chinese_number(me->query("min_combat_exp"))+"�ꡣ\n");

 if(query_kinds(min_dx,max_dx))
  return notify_failed(who,"�趨����ѧ������ǰ���趨���������Χ���ص��ĵط�������lists�������ķ��飬Ȼ�����衣\n");

 if(!(kinds=me->query("kinds")))
    kinds=1;
 else kinds=me->query("kinds")+1;
 me->set("kinds",kinds);

 kindlist=([]);
 kindstr=sprintf("%d",kinds); 
 kindlist[kindstr]=([]);

 kindlist[kindstr]["min_num"]=min_dx;
 kindlist[kindstr]["max_num"]=max_dx;
//������Ҳ���������� 
 JOINER[kindstr]=([]);
 if(me->query("kindlist"))
   kindlist+=me->query("kindlist");
 me->set("kindlist",kindlist);
 tell_object(who,"������ѧ���"+kindstr+"��"+chinese_number(min_dx)+"��"+chinese_number(max_dx)+"��\n");
 me->save();
  doc=new(DOC);
  doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
  doc->restore();
  doc->set("kinds",kinds);
  doc->set("kindlist",kindlist);
  doc->save();
  destruct(doc);
 
 return 1;
}

int delkind(object who,string arg)
{
 int num,i,j;
 mapping kindlist,joiner;
 string kindstr,kindstr1;
 object doc;
 object me=this_object();
 
 if(!arg) return notify_failed(who,"��������Ϊ��!\n");
 if(!(num=me->query("kinds")))
  return notify_failed(who,"�Ƿ��Ĳ������֣�������û�����ӷ��飬����ʹ��addage��"+

                           "adddx�����ӡ�\n���������ñ���ˮ½��ᱨ��ʹ��\n");
 if(num<1) 
  return notify_failed(who,"�㻹û��������أ�ûʲô��ɾ�ġ�\n");

 if(sscanf(arg,"%d",i)!=1)
  return notify_failed(who,"��ʹ��delkind ������ɾ�����õ����\n"+
                           "���磺delkind 1��ʾɾ����ǰʹ���飬����14-17���顣\n");
 if(i>num||i<1)
  return notify_failed(who,"Ҫɾ������𳬹��˵�ǰ���е��������\n"); 
  
  kindlist=([]);
  me->set("stop_report",1);
  kindlist=me->query("kindlist");
  //��Ҫ������
  if(mapp(kindlist))
   for(j=i;j<=num;j++) {
         kindstr=sprintf("%d",j);
    map_delete(kindlist,kindstr);
    if(j+1<=num) {
       kindstr1=sprintf("%d",j+1);
       kindlist[kindstr]=([]);
       kindlist[kindstr]["min_num"]=kindlist[kindstr1]["min_num"];
       kindlist[kindstr]["max_num"]=kindlist[kindstr1]["max_num"];      
    }
   } 
  if(mapp(JOINER))
   for(j=i;j<=num;j++) {
         kindstr=sprintf("%d",j);
     map_delete(JOINER,kindstr);  
    if(j+1<=num) {
       kindstr1=sprintf("%d",j+1);
       JOINER[kindstr]=([]);
       joiner=([]);
       joiner=JOINER[kindstr1];
       JOINER[kindstr]=joiner;
    }
   } 
  me->set("kindlist",kindlist);
  num-=1;
  me->set("kinds",num);
  me->delete("stop_report");
  me->save();
//save to joiner file
  doc=new(DOC);
  doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
  doc->restore();

  doc->set("joiner",JOINER);
  doc->set("kindlist",me->query("kindlist"));
  doc->set("type",me->query("type"));
  doc->set("typestring",me->query("typestring"));
  doc->set("kinds",me->query("kinds"));
  doc->save();
  destruct(doc);
 tell_object(who,"ɾ����"+chinese_number(i)+"��ɹ���\n");
 return 1;
}

int finish(object who)
{
 object doc,env;
 string msg;
 object me=this_object();
 
   me->set("stop_report",1);
   me->save();
  if(env=environment(me))
   {
     env->delete("no_fight");
     env->delete("no_magic");

     env->delete("no_clean_up");
     env->delete("no_steal");
     env->delete("no_bian");
     env->delete("has_stand_here");
   }
   doc=new(DOC);
   doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
   doc->restore();
   doc->set("kindlist",me->query("kindlist"));
   doc->set("type",me->query("type"));
   doc->set("typestring",me->query("typestring"));
   doc->set("kinds",me->query("kinds"));
   doc->set("joiner",JOINER);
   doc->save();
   destruct(doc);   
   msg="��"+chinese_number(me->query("sldh_num"))+"��ˮ½��ᱨ������ȫ����ɣ�";

   announce(msg);
   msg="�Ϸ�Ը���δ��Բ���ɹ���\n";
   announce(msg);
 return 1;
}

private string listone(object who,int num)
{
 int i;
 string msg,kindstr,str;
 mapping kindlist,joinerlist,typestr; 
 string *list,type;
 object doc;
 object me=this_object();
 
 doc=new(DOC);
 if(!doc) 
  {
   notify_failed(who,"�쳣����������Ŀ���ļ�"+DOC+"�����ڡ�\n");
   return "�쳣����\n";
  }

 doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
 doc->restore();
 kindstr=sprintf("%d",num);
 kindlist=me->query("kindlist");
 joinerlist=doc->query("joiner");
 typestr=me->query("typestring");

 type=me->query("type");
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
       str+=str1;
      } 
     (i-1)%7!=0?str+="\n\n":str=str;
     msg+=HIC+str+NOR;
     msg+=HIW+"���ܹ�"+chinese_number(sizeof(list))+"����Ҳμӱ��鱨����"+NOR+"\n";
     if(!me->query("total_num")) me->set("total_num",sizeof(list));
     else me->set("total_num",me->query("total_num")+sizeof(list));
   }
  }
 else msg+="������û����Ҳμӱ�����\n";
 return msg;
}

int list(object who,string arg)
{
 int i,num,kinds;
 string msg,str;
 object me=this_object();
 
 me->set("total_num",0);

 msg=HIY"��"+chinese_number(me->query("sldh_num"))+"��ˮ½�����鼰�������б�\n"NOR;
 msg+=HIG"������������������������������������������������������������������������������������"NOR+"\n";
 kinds=me->query("kinds");
 if(!arg)
  if(kinds>0)
   for(i=1;i<=kinds;i++) {
    msg+=listone(who,i);
   if(i!=kinds) 
 msg+=HIG"�š�����������������������������������������������������������������������"NOR+"\n";    
   } 
 msg+=HIG"������������������������������������������������������������������������������������"NOR+"\n";       
 str=sprintf("%70s","�ܹ���"+chinese_number(me->query("total_num"))+"����Ҳμӱ���ˮ½��ᱨ��");
 str=HIY+str+NOR+"\n\n";
 msg+=str;
 tell_object(who,msg);
 return 1;
}

void create()
{

        set_name("ˮ½��ᱨ��ʹ", ({ "sldh baoming shi", "shi zhe"}) );
        set("age",500);
        set("combat_exp",8000000);
        set("force",10000);
        set("max_force",7000);
        set("mana",16000);
        set("max_mana",8000);
            set_skill("spells", 500);
        set("inquiry", ([
            "rumors":  "Ҫ��������������report����μӡ�",
        ]) );
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();

}

string short()
{
 object me=this_object();
 
 return "��"+chinese_number(me->query("sldh_num"))+"��ˮ½��ᱨ��ʹ"+"("+me->query("id")+")";
}

string long()
{
   object me=this_object();
return "\nˮ½��ᱨ��ʹִ��ˮ½��ᱨ����Ȩ���Ǿٰ�ˮ½������ʦ�ĵ������֡�\n����ʲô���ʿ��Դ���help report��������\n";
}

string query_save_file()
{

  return DATA_DIR "sldh/reporter";
}
void init()
{
  object env;
  object me=this_object();
  
 if(!(env=environment(me))) destruct(me);
 if(!env->query("has_stand_here"))
  {
   env->set("has_stand_here",1);
   env->set("no_clean_up",1);
   env->set("no_fight",1);
   env->set("no_magic",1);
   env->set("no_bian",1);
   env->set("no_steal",1);
   this_object()->restore();
   if(!me->query("sldh_num"))
     me->set("sldh_num",1);
   else me->set("sldh_num",me->query("sldh_num")+1);
   me->save();
   remove_call_out("greeting");

   call_out("greeting",5);
   me->delete("kinds");
   me->delete("kindlist");
   me->delete("ages");
   me->delete("dxs");
  }

  add_action("do_report","report");
  add_action("do_help","help");
  add_action("do_list","lists");
  
 if(wizardp(this_player())) {
  add_action("do_start","start");
  add_action("do_age","addage");
  add_action("do_dx","adddx");
  add_action("do_delkind","delkind");
  add_action("do_finish","finish");
 } 
}

void greeting()
{
 string msg;

 object me=this_object();
 
 msg="��"+chinese_number(me->query("sldh_num"))+"��ˮ½�����ʽ����������ʼ�����ҵ�������ʮ�ֽ�ͷ��ʹ��report�������";
 announce(msg);
 remove_call_out("greeting");
}

int do_report()
{
 object player=this_player();
 object me=this_object();
 object doc;
 int num,j,k;
 string msg,kindstr,ids,i;
 string *list;
 mapping temp=([]);
 mapping kindlist=([]);
if(!DEBUG)  
 if(wizardp(player))
  return notify_fail("��ʦ���ܲμ�ˮ½��ᡣ\n");

 if(userp(player))
  {

    if(!(i=me->query("type")))
      return notify_fail("�Բ�����ʦ��û����׼�������Ժ�������\n"); 
    if(!me->query("kinds"))
     return notify_fail("�Բ�����ʦ��û׼���ã���Ⱥ���ʦ׼���׵�����������\n");
    if(me->query("stop_report"))
     return notify_fail("�Բ����Ѿ�ֹͣ������\n");
//������ұ��������ĺ˶�   
    switch(i) {
//��ѧ����
     case "1":num=player->query("age");
            if(num<me->query("min_age"))
              return notify_fail("�Բ��������ѧ̫С������Ҫ"+
                       chinese_number(me->query("min_age"))+"���ܲμ�ˮ½��ᡣ\n");

            if(player->query("combat_exp")/1000<me->query("min_combat_exp"))
              return notify_fail("�Բ��������ѧ̫�٣�����Ҫ"+
                       chinese_number(me->query("min_combat_exp"))+"���ܲμ�ˮ½��ᡣ\n");
            break;
//��ѧ����
     case "2":num=player->query("combat_exp")/1000;
            if(num<me->query("min_combat_exp"))
              return notify_fail("�Բ��������ѧ̫�٣�����Ҫ"+
                     chinese_number(me->query("min_combat_exp"))+"���ܲμ�ˮ½��ᡣ\n");
            if(player->query("age")<me->query("min_age"))

              return notify_fail("�Բ��������ѧ̫С������Ҫ"+
                     chinese_number(me->query("min_age"))+"���ܲμ�ˮ½��ᡣ\n");

            break;
     default: return notify_fail("�Բ������ڻ�û��ʼˮ½��ᱨ�������Ժ�\n");
    }
    doc=new(DOC);
    doc->set("file_name",DATA_DIR+"sldh/joiner"+sprintf("%d",me->query("sldh_num")));
    doc->restore();
    j=query_user_kinds(player);
    if(j==0) return notify_fail("�Բ����㲻���ϱ����������޷�����ֵ����ʵķ���ȥ��\n");
    
    if(!mapp(this_object()->query("kindlist")))
      return notify_fail("�Բ����㲻���ϱ����������޷�����ֵ����ʵķ���ȥ��\n");
      
     kindlist=this_object()->query("kindlist");
     kindstr=sprintf("%d",j);  
    if(i=="1") 
     msg=chinese_number(kindlist[kindstr]["min_num"])+"����"+
         chinese_number(kindlist[kindstr]["max_num"])+"��������";
    else if(i=="2")     
     msg=chinese_number(kindlist[kindstr]["min_num"])+"����"+
         chinese_number(kindlist[kindstr]["max_num"])+"����ѧ��";
    
    ids=player->query("id");
    if(mapp(JOINER))
     for(k=1;k<=query("kinds");k++)
      {
       i=sprintf("%d",k);       
       if(mapp(JOINER[i]))
       {
         list=keys(JOINER[i]);
         for(j=0;j<sizeof(list);j++)
          if(list[j]==ids) return notify_fail("�㲻���Ѿ���������\n");
        }
      }

    temp[ids]=([]);
    temp[ids]["price"]="N";//���ָʾ�ñ������Ƿ�����ˮ½��ά��
    temp[ids]["fight"]="N";//���ָʾ�ñ������Ƿ�μ���ˮ½���
    //����һ������ָʾ���������߲μ�ˮ½����õ����Σ�ͨ��ָֻʾ�ھ���Ǿ���
    temp[ids]["winnum"]=0;//1ָʾchampion,0ָʾnormal
    if(mapp(JOINER[kindstr]))
     JOINER[kindstr]+=temp;
    else {
        JOINER[kindstr]=([]);

        JOINER[kindstr]+=temp;
    }
    doc->set("joiner",JOINER);
    doc->save();
    msg="��"+chinese_number(me->query("sldh_num"))+"��ˮ½���"+msg+
        "\n�¼ӱ�����"+player->query("name")+"("+player->query("id")+")"+"һ����";
    announce(msg);
    destruct(doc);
  }
  return 1;
}

int do_start(string arg)
{
 object me=this_player();
 if(!me) return 0;
  start(me,arg);
 return 1;
}

int do_age(string arg)
{
 object me=this_player();

 if(!me) return 0;
 age(me,arg);
 return 1;
}

int do_dx(string arg)
{
 object me=this_player();
 if(!me) return 0;
 dx(me,arg);
 return 1;
}

int do_delkind(string arg)
{
  object me=this_player();
 if(!me) return 0;
  delkind(me,arg);
 return 1;
}

void destroy_me()
{

 message_vision(HIG"ֻ��һ�����̴ӵص�ð�𣬱���ʹٿ�����Ȼ�����ˣ�\n"NOR,this_object());
 destruct(this_object());
}

int do_finish()
{
 object me=this_player();
 if(!me) return 0;
  finish(me);
  remove_call_out("destroy_me");
  call_out("destroy_me",2);
 return 1;
}

int do_list(string arg)
{
 object me=this_player();
 if(!me) return 0;
 list(me,arg);
 return 1;
}

int help(object who)

{
 string msg;
 msg ="\n\nˮ½��ᱨ����֪��\n";
 msg+="ˮ½��ᱨ�����ڱ���ʹ���ڵķ���ʹ��report����ɱ�\n";
 msg+="������Ȼ�����ɹ����Ҫ�����Ƿ���ϵ�ʱ����������\n";
 msg+="���������У�����ʹ��lists����鿴��ǰ��������Լ�����\n";
 msg+="�����\n\n";
if(wizardp(who))
 {
 msg+="
��Ϊ��ʦ��ʹ�õ�ָ�ִ�е��Ⱥ�˳������Ϊ��\n";
 msg+="
1��start��ÿ�β����µķ������ͱ���ʹ��start age��
start dx���б������������ԭ�����趨��\n";
 msg+="
2��addage,adddx��addage��adddx������������һ�������
������Բ�������ʹ�ÿ�ʹ�ð�����\n";
 msg+="
3��delkind��delkind������ɾ������������������
���ַ����д������delkind��������delkindָ���ɾ����
����һ�е�ǰ���ð����ѱ�������ҡ�\n";
 msg+="
4��lists��lists��Ҫ�����ۿ���ǰ�ı���������������г�
���ÿ��������ߣ������������ܵı���������\n";
 msg+="
5��finish�����ָ��ָʾ��ǰ����һ�н���,����ʹ��������
��Ӧ�ô���,��������������,����ɨ����ʹ�ڵ�ǰ�������µ�
�仯��Ȼ�������ʹ��\n";
 }
 tell_object(who,msg);
 return 1;
}

int do_help(string arg)
{
 object me=this_player();
 if(!me) return 0;
 if(!arg) return 0;
 if(lower_case(arg)=="report")
  help(me);
 else return 0;

 return 1;
}
