
//   ˮ½��ᷢ��̨

#include <ansi.h>
inherit ITEM;
inherit F_SAVE;

mapping sldher;
#define sldhdoc "/d/kaifeng/obj/sldhdoc"

void setup()
{
  object env=environment(this_object());
 if(clonep() && env)
   move(env);
  set("no_get", 1);
  restore();
}

void create ()
{
    set_name(HIC"ˮ½��ᷢ��̨"NOR, ({ "fajiang tai"}) );
    set ("long", "

������һ��ˮ½��ᷢ��̨����ˮ½�����ɺ���ҿ���վ��
����̨(stand)����ȡ��Ʒ����ʦҪ�˽�÷���̨���ʹ�ã���
����help fajiang��

");
    set("unit","��");
    set("type","misc");
    seteuid(getuid());
    set("no_put",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_give",1);
    set("value",10000);
    setup();
}

string short()
{
 string str;
 str="����";
 return HIC"ˮ½��ᷢ��̨"NOR+"(fajiang tai)"+"(Ŀǰ�����У�"+str+"Сʱ��ֹͣ����)";
}

string long()
{
 string msg;
 msg="\n����һ��ˮ½��ᷢ��̨����ˮ½�����ɺ���ҿ���վ��\n";
  msg+="����̨(stand)����ȡ��Ʒ����ʦҪ�˽�÷���̨���ʹ�ã���";
  msg+="����help fajiang��\n";
 return msg; 
}

void init ()
{
  object who = this_player();
   add_action("do_stand","stand");
   add_action("do_start","start");
   add_action("do_finish","finish");
   add_action("do_list_sldh","lists");
}

string query_save_file()
{
   return DATA_DIR + "sldh/sldhprt";
}
int can_give(string id)
{
 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 if(!sldher)
  return 0;
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return 0;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id) return 1;
  }
 return 0;
}

int have_give(string id)
{
 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 if(!sldher)
  return 1;
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return 1;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id)
       if(tmp[id]["price"]=="Y")
         return 1;
  }
 return 0;
}
int give_promotion(object who)
{
 mapping tmp=([]);
 string *list,*list1,id,msg;
 object doc;
 int i,j,k,g,found,kind,fight;
 int potential,base_qn,step_qn;
 
 if(!sldher)
  return 0;
 list=keys(sldher);
 k=sizeof(list);
 found=0;
 id=who->query("id");
 if(k<=0) return 0;
 fight=0;
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(list1[j]==id) {
     if(tmp[id]["winner"]>0) set("first/"+id,1);
     if(tmp[id]["fight"]=="Y") fight=1;
     
      tmp[id]["price"]="Y";
      sldher[list[i]]=tmp;
      save();
      doc=new(sldhdoc);
     if(doc) {
       doc->set("file_name",query("filename"));
       doc->restore();  
       doc->set("joiner",sldher);
       doc->save();
       destruct(doc);
      }
      found=1;
      sscanf(list[i],"%d",kind);
     break; 
    }
   if(found) break; 
  }    


 //end match id 
 base_qn=query("base_qn");
 step_qn=query("step_qn");
 i=query("value_give");//�����ٷ���������
 //���û���qn�Ͳ���Ǳ�ܡ�
 if(base_qn<5000) base_qn=10000;
 if(step_qn<1000) base_qn=5000;
  if(found)
  {
    potential=base_qn+(kind-1)*step_qn;
    if(query("first/"+id))
    {
     potential=potential*2-potential/2;
     j=i-(kind-1)*10;
     if(j<20) j=20;
    } else if(!fight) potential=potential/2;
   } else return 0;

 msg="��"+chinese_number(query("sldh_num"))+"��ˮ½���"+chinese_number(kind)+"��";
 
 if(query("first/"+id))
  msg+="�ھ�������"+who->query("name")+"("+id+")";
 else if(fight) msg+="����������������"+who->query("name")+"("+id+")";
      else msg+="����������������"+who->query("name")+"("+id+")";

 msg+="���"+sprintf("%d",potential)+"��Ǳ��";
 if(query("first/"+id)) {
        msg+="��"+sprintf("%d�㷨��%d������������",j,j);
        who->add("potential",potential); 
        who->add("max_mana",j);
        who->add("max_force",j);
 }      
 else {
        msg+="������\n";
        who->add("potential",potential); 
 }      
 msg=HIC+msg+NOR;
 CHANNEL_D->do_channel(this_object(), "sldh", msg);
 save();
 who->save();
 return 1; 
}
        
string get_first()
{

 mapping tmp=([]);
 string *list,*list1;
 int i,j,k,g;   
 string msg;
 msg="";
 if(!sldher)
  return "û�йھ���\n";
 list=keys(sldher);
 k=sizeof(list);
 if(k<=0) return "û�йھ����ݡ�\n";
 msg="";
 for(i=0;i<k;i++)
  {
   tmp=sldher[list[i]];
   list1=keys(tmp);
   g=sizeof(list1);
   if(g<=0) continue;
   for(j=0;j<g;j++)
    if(tmp[list1[j]]["winnum"]>0) {
      set("first/"+list1[j],1);
      msg+="��"+list[i]+"��"+list1[j]+"\n";
    }  
  }
if(msg!="")  
 msg="����ھ�����Ϊ��\n"+msg;   
else msg="����ھ���δ������\n"; 
 return msg;
}

int notify_failed(object ob,string str)
{
 if(ob)
  tell_object(ob,str);
 return 1;
}


int do_stand(string arg)
{
 object who=this_player();
 string id;
 if(!arg) 
  return notify_failed(who,"��Ҫվ������\n");
 if(arg!="fajiang tai" && arg!="����̨")
  return notify_failed(who,"��Ҫվ��ʲô�ط���ȥ��\n");  
 if(!query("start"))

  return notify_failed(who,"�Բ������ڻ�û��ʼ������\n");  
 if(!query("init"))
  return notify_failed(who,"�Բ������ڻ�û��ʼ������\n");  
 if(!query("finish"))
  return notify_failed(who,"�Բ������ڻ�û��ʼ������\n");  
  
 id=who->query("id");
 if(!can_give(id))
  return notify_failed(who,"�Բ����㲻�ܻ��ˮ½��ά����\n");
 if(have_give(id))
  return notify_failed(who,"���Ѿ��ù�ˮ½��ά�����벻Ҫ�����ˡ� \n");
 if(!give_promotion(who))
  return notify_failed(who,"�㲻�ܻ�ý�����ԭ����δ֪��������ò�������������ʦЭ��Ͷ�ߡ�\n");
 return 1;
}
//����ھ�
private void input_first(string arg,object me,object who)
{
 string first;
 int i;
 if(!arg) {
    tell_object(who,"\n��������������(y�˳�)��");
    input_to("input_first",0,me,who);
    return;             
 }      

 if(arg=="y") return;
 if(sscanf(arg,"%d %s",i,first)!=2) {
    tell_object(who,"\n��������������(y�˳�)��");
    input_to("input_first",0,me,who);
    return;             
 }
 set("first/"+first,1);
 save();
 return;
}
//����Ǳ�ܺͷ�������
private void input_qn(string arg,object me,object who)
{
 int base_qn,step_qn,value_give;
 if(sscanf(arg,"%d %d %d",base_qn,step_qn,value_give)!=3)
 {
    tell_object(who,"\n�������������Ǳ�ܣ�����Ǳ�ܣ�����������ֵ(0 0 0�˳�)��");
    input_to("input_qn",0,me,who);
    return;             
 }
 
 if(base_qn==0) return;
 if(base_qn<1000||step_qn<1000||value_give<30) {
    tell_object(who,"\n̫С���˰ɣ��������������Ǳ�ܣ�����Ǳ�ܣ�����������ֵ(0 0 0�˳�)��");
    input_to("input_qn",0,me,who);
    return;             
 }      
 if(base_qn>20000||step_qn>15000||value_give>100) {
    tell_object(who,"\n̫���˰ɣ��������������Ǳ�ܣ�����Ǳ�ܣ�����������ֵ(0 0 0�˳�)��");
    input_to("input_qn",0,me,who);
    return;             
 }
 set("base_qn",base_qn);
 set("step_qn",step_qn);
 set("value_give",value_give);

 save();
 tell_object(who,"�ã����뷢����ֵ��ɣ���һ������ھ�ID��\n");
 tell_object(who,get_first());
 tell_object(who,"����������ȷ�������ȷ�밴y,�������ȷ���������͹ھ�ID��\n��:1 smile��\n");
 tell_object(who,"���������ݣ�");
 input_to("input_first",0,me,who);
 return; 
}

//�������
private int input_num(string sldhnum,object me,object who)

{
  object doc;
  int i;
  string filename;
  
  if(sscanf(sldhnum,"%d",i)!=1) {
    tell_object(who,"\n�����ˮ½���������������֣�����������(0�˳�)��");
    input_to("input_num",0,me,who);
    return 0;    
   }    
  if(i==0) return 0;
  
  filename=sprintf("%s%d%s",DATA_DIR + "sldh/joiner",i,".o");
  if(file_size(filename)<0) {
     tell_object(who,"\nû��������ˮ½������������������(0�˳�)��");
     input_to("input_num",0,me,who);
     return 0;
   } 
  doc=new(sldhdoc);
  if(!doc)
    return notify_failed(who,"\n����ˮ½��ᱨ�������ʧ�ܣ��������ļ������ڣ��˳����á�\n");
      
  filename=sprintf("%s%d",DATA_DIR+"sldh/joiner",i);
  doc->set("file_name",filename);
  doc->restore();
  sldher=doc->query("joiner");
  if(!sldher) {
    destruct(doc);
    return notify_failed(who,"��ȡˮ½��ᱨ������ʧ�ܣ��޷����з�����\n");     
   } 
  set("init",1);
  set("sldh_num",i);
  set("filename",filename);
  save();
  destruct(doc);
  tell_object(who,"����ˮ½�������ɹ��������뷢�����ݡ�\n�����ʽ(����Ǳ�� ����Ǳ�� ���������� ��:10000 5000 50\n");
  tell_object(who,"ȱʡ������Ϊ"+sprintf("%d %d %d\n",query("base_qn"),query("step_qn"),query("value_give")));
  tell_object(who,"�����뷢������(0 0 0�˳�)��");
  input_to("input_qn",0,me,who);
  return 1;
}

//��ʼ����
int do_start(string arg)
{
  object who=this_player();
  if(!arg)
   return notify_failed(who,"��Ҫ����ʲô��\n");
  if(wiz_level(who)<1)
   return notify_failed(who,"����Ȩ��������̨��\n"); 
  if(arg!="����"&&arg!="promotion")
   return notify_failed(who,"Ҫ��������̨������start ������\n");
  set("start",1);
  delete("init");
  delete("first");
  delete("finish");
  save();
  tell_object(who,"�ã����ڽ��뷢��̨���ù�������������ȷ��ˮ½���Ľ�����");
  input_to("input_num",0,this_object(),who);
  tell_object(who,"�ã�����̨������ɣ�������finish setting�Ա�ȷ�Ϸ�����\n���д�����start �����������á�\n");
  return 1;
}

int do_list_sldh(string arg)
{
 return 1;
}

int do_finish(string arg)
{
  object who=this_player();
  if(!arg)
   return notify_failed(who,"��Ҫ�趨ʲô��\n");
  if(wiz_level(who)<1)
   return notify_failed(who,"����Ȩ�ر�ˮ½��ᷢ��̨�趨��\n"); 
  if(arg!="setting" && arg!="����̨�趨")
   return notify_failed(who,"Ҫ����趨������finish setting\n");
  if(!query("start"))
   return notify_failed(who,"�㻹û��������̨�ء�\n");
  if(!query("init"))
   return notify_failed(who,"�㻹û�趨ˮ½�������ء�\n");
  set("finish",1);
  save();  
  tell_object(who,"����̨������ɣ������stand fajiang tai�Ϳ��Ը����Ƿ����ˡ�\n");
 return 1;
}
