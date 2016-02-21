inherit ROOM;
#include <ansi.h>;
int WTS=4;
string this_place="/u/repoo/liudao/one/questroom";
//need to change above line if this room is moved to another place.
string sheet,num,*wt;
string sheet1,num1,*wt1;
int length,length1,running;
string current,current_all,last,last_all;
string curr_show;
int index,chance;
int wt_index,answerd,ans_curr,ans_last;
void new_wt();
void copy_to_old();
void do_test();
void do_init(object me);
void wt_reward(object me,string arg);
void wt_reward1(object me);
void wt_penalty(object me);
int find_newline();
string enscript(string arg);
void create ()
{
  set ("short", "������");
  set ("long", @LONG
�����ҡ�
LONG);
  set("exits", ([ /* sizeof() == 3 */
]));
  set("no_fight", 1);
  set("no_magic", 1);
  set("objects", ([
  ]));
  setup();
  remove_call_out("do_test");
  wt_index=1;
  running=0;
}
void init()
{   
     add_action("do_answer","answer");
          call_out("do_init",1,this_player());
     if(running==0) {
       running=1;
       new_wt();
       copy_to_old();
       new_wt();
       call_out("do_test",2);
     }
}
void do_init(object me)
{ 
    tell_object(me,"\nanswer <...>���ش�.\n\n");
    return;
}
int do_answer(string arg)
{ 
    object me=this_player();
    if(!arg) return notify_fail("�ش�ʲô��\n");
    if( living(me) ) me->receive_damage("sen",5+random(15));
    arg=replace_string(arg," ","");
    switch(random(2)) {
     case 0: message_vision("$N˵�������ǣ�����"+arg+"��\n",me);
             break;
     case 1: message_vision("$N�����"+arg+"��\n",me);
             break;
    }
    if(arg==current&&strlen(current)>2) {
      if(ans_curr==1) {
       write("�����Ѿ��ش��ˡ�\n");
       return 1;
      }
      ans_curr=1;
      
      //change to a new poem once this one is answered.
      index=length-1;
      me->set_temp("wt/index",wt_index);
      wt_reward(me,current_all);
    } else if(arg==last&&strlen(last)>2) {
      if(ans_last==1) {
       write("�����Ѿ��ش���ˡ�\n");
       return 1;
      }
      ans_last=1;
      wt_reward(me,last_all);
    } else {
      write("���󲻶԰ɣ�\n");
      me->add_temp("wt/wrong",1);
    }
    return 1;
}
void wt_reward(object me,string arg)
{
    me->set_temp("wt/wrong",0);
    message_vision("��"+arg+"������\n",me);
    wt_reward1(me);
}
void wt_reward1(object me)
{  
      me->save();
      message_vision("$Nhoho!!!\n",me);
    }
void do_test()
{  
   int newt;
   string first,second,quest;
   if(strlen(current)>2&&ans_curr==0) {
     last=current;
     last_all=current_all;
     ans_last=0;
   }
   
   newt=0;
   while(newt==0) {
    if(!find_newline()) {
     copy_to_old();
     new_wt();
    } else {
      if(sscanf(wt[index],"%s  %s",first,second)==2 &&
       !sscanf(wt[index],"%*s��") && 
       !sscanf(wt[index],"%*s��") &&
       !sscanf(wt[index],"%*s��") ) {
         if(strlen(first)>2&&strlen(second)>0) {
	   newt=1;
         } 
}
}
}
   first=replace_string(first," ","");
   second=replace_string(second," ","");
   current_all=first+"  "+second;
   ans_curr=0;
     quest=enscript(first);
     current=second;
     curr_show=quest+enscript("������");
     switch(random(2)) {
       case 0: 
         tell_room(this_object(),"��"+quest+"���Ĵ���ʲô��\n");
         break;
       case 1:
         tell_room(this_object(),""+quest+"����������ʲô���ţ�\n");
         break;
     }
   if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
       call_out("do_test",60);
   else
       running=0;
   return;
}
void copy_to_old()
{    int i;
     length1=length;
     wt1=({});
     last="";
     for (i=0;i<length;i++)
       wt1+=({wt[i]});
     return;
}
void new_wt()
{   string filename,buf;
    int i,j,k;
    length=0;
    while (length==0) {
    while((k=(1+random(WTS)))==wt_index);
    filename=__DIR__"wt/wt"+k;
    buf=read_file(filename,1,1);
    sscanf(buf,"%s��%s",sheet,num);
//      tell_room(this_object(),""+sheet+"����������ʲô���ţ�\n");
    i=0;
    j=0;
    wt=({});
    while(buf=read_file(filename,3+i,1)) {
      if(strlen(buf)>0) {
        buf=replace_string(buf,"\n","");
        wt+=({buf});
        j++;
      }
      i++;
    }
    length=j;
    }
    wt_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
    if(length<3) {
      chance=100;
    }
    return;
}
int find_newline()
{
   index++;
   while(index<length) {
     if(random(100)<chance) {
       return 1;
     } else index++;
   }
   return 0;
}
string enscript(string arg)
{    string result;
     string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
                     HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
                     HBBLU,HBMAG,BBLK,BRED,BGRN});
     int len,i;
     len=sizeof(color);
     result="";
     i=sizeof(arg);
     while(i>2) {
       if(random(2)==0) {
         result=color[random(len)]+NOR+arg[i-2..i-1]+result;
       } else {
         result=arg[i-2..i-1]+result;
       }
       i-=2;
     }
     result=NOR+arg[0..1]+result;
     return result;
}
