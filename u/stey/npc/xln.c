inherit NPC;                                                                        
#include <ansi.h>                                                                   
void create()                                                                       
{                                                                                   
        set_name("С��Ů", ({ "xiao longnv", "longnv" }));                          
        set("nickname", "�������");                                                
        set("long",                                                                 
                "ӯӯ��վ��һλ�������׵�Ů�ӣ�����������һ��Ѫɫ���Եò԰��쳣��\n"
                "����һϮ��ɴ��İ��£����������������\n");                      
        set("gender", "Ů��");                                                      
        set("age", 17);                                                             
        set("attitude", "friendly");                                                
        set("str", 30);                                                             
        set("int", 30);                                                             
        set("con", 30);                                                             
        set("dex", 30);                                                             
     set("max_kee", 5000);                                                          
        set("max_sen", 3000);                                                       
        set("force", 10000);                                                        
        set("max_force", 5000);                                                     
        set("eff_sen", 3000);                                                       
        set("enforce_actor", 150);                                                  
        set("combat_exp", 2000000);                                                 
        set("chat_chance_combat", 10);                                              
//       set("chat_msg_combat", ({                                                  
//                (: perform_action, "sword.xuan" :),                               
//        }));                                                                      
        set_skill("force", 200);                                                    
        set_skill("dodge", 200);                                                    
        set_skill("parry", 200);                                                    
        set_skill("unarmed", 200);                                                  
        set_skill("sword", 200);                                                    
        create_family("��Ĺ��", 2, "�������");                                     
        setup();                                                                    
        //carry_object("/u/fly/obj/wcloth")->wear();                                  
 carry_object("/u/stey/obj/snj")->wield();                                           
                                                                                    
}                                                                                   
void kill_ob(object me)                                                             
{                                                                                   
        command("chat* ? " + me->query("id"));                                      
        command("chat* nomatch " + me->query("id"));                                
        ::kill_ob(me);                                                              
}                                                                                   
void init()                                                                         
{                                                                                   
        add_action("do_ok","sendmail");                                             
}                                                                                   
                                                                                    
int do_ok()                                                                         
{                                                                                   
        object ob = this_player();                                                  
        string email=ob->query("email");                                            
        "/adm/daemons/smtp_d"->send_mail(ob,email);                                 
        return 1;                                                                   
}                                                                                   
