#include <ansi.h>                                                                             
inherit NPC;                                                                                  
string ask_tea();                                                                             
int singing();                                                                                
#include </u/fly/npc/npc.h>;                                                                  
void create()                                                                                 
{                                                                                             
       set_name("����", ({ "daiyu"}) );                                                       
       set("title", MAG "��������ʤ����" NOR);                                                
       set("gender", "Ů��" );                                                                
       set("shen_type", 1);                                                                   
       set("age", 16);                                                                        
       set("str", 10);                                                                        
       set("con", 40);                                                                        
       set("int", 40);                                                                        
       set("dex", 40);                                                                        
       set("per", 100);                                                                       
       set("kar", 50);                                                                        
       set("no_clean_up",1);                                                                  
       set("long",                                                                            
HIW"����ʮ����֮һ��������                                                                  
̬������֮���Ϯһ��֮����                                                                  
�о�ʱ��毻���ˮ���ж������������硣\n"NOR );                                                 
       set("combat_exp", 20000);                                                              
       set("attitude", "peaceful");                                                           
       set("max_qi", 300);                                                                    
       set("max_jing", 300);                                                                  
       set("neili", 100);                                                                     
       set("max_neili", 100);                                                                 
       set_skill("literate", 500);                                                            
       set("inquiry", ([                                                                      
                   "name" : "СŮ��������",                                                 
                   "here" : "�����Ǿ��������ҡ�",                                             
                   "stey" : "stey���Ǳ�����������ô�������ⶼ��֪����",                         
                   "��ѩ" : "������������˰�������ô�������ⶼ��֪����",                     
                   "Ѧ����" : "�����ҽ�㡣",                                                 
                   "����" : "�����ҽ�㡣",                                                   
                   "��" : (: ask_tea :),                                                      
                   "tea" : (: ask_tea :),                                                     
       ]) );                                                                                  
       setup();                                                                               
       set("chat_chance", 2);                                                                 
       set("chat_msg", ({                                                                     
 "��������������죬�����������������\n",                                                  
 "����������������̾ͣ���£�����ӽ���š�\n",                                                  
 "�����������ⷢ�������\n",                                                                  
 (: singing :),                                                                               
       }) );                                                                                  
       //carry_object("/u/stey/obj/pipa");                                                       
       //carry_object("/u/stey/obj/qupu");                                                       
       //carry_object("/u/stey/obj/jinshan")->wield();                                           
       if( clonep() ) CHANNEfL_D->register_relay_channel("chat");                              
}                                                                                             
void init()                                                                                   
{                                                                                             
        object ob;                                                                            
                  ::init();                                                                   
                  if( interactive(ob = this_player()) && !is_fighting() ) {                   
                remove_call_out("greeting");                                                  
                call_out("greeting", 1, ob);                                                  
        }                                                                                     
  add_action("do_mo", ({"18mo", "kiss", "hug", "lean", "flirt", "interest"}));                
  add_action("do_mo", ({"fire", "kick", "smash", "taste", "hehe", "kiss1"}));                 
}                                                                                             
void greeting(object ob)                                                                      
{                                                                                             
        if( !ob || environment(ob) != environment() ) return;                                 
        if((string)ob->query("id")=="fly") return;                                            
        if(ob->query_temp("kill_daiyu"))                                                      
               {                                                                              
                message_vision("����üͷһ�壺�������֮ͽ�����ˣ�������ȥ��\n",ob);          
                message_vision("ֻ�������Ҷ��ܽ�������$N�Ұ����˳�ȥ��\n",ob);                
                ob->move("/d/city/kezhan");                                                   
                ob->receive_damage("qi", 100);                                                
                message_vision(ob->name() + "�ֱ����Ұ����˳�����\n",ob);                     
        }                                                                                     
        else                                                                                  
                say("������˸��򸣣���λ" + RANK_D->query_respect(ob)                        
              + "�������ӭ�������͡�\n");                                                    
}                                                                                             
