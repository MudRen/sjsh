int singing()                                                              
{                                                                          
 if(present("qu pu", this_object())){                                      
 switch(random(6)) {                                                       
       case 0 : command("chang yuanyuan_qu"); break;                       
       case 1 : command("chang wenshi_jian"); break;                       
       case 2 : command("chang dielian_hua"); break;                       
       case 3 : command("chang wanghai_chao"); break;                      
       case 4 : command("chang chunjiang_huayueye"); break;                
       case 5 : command("chang jiangjin_jiu"); break;                      
     }                                                                     
   return 1;                                                               
 }                                                                         
 else command("say ������Ү :(\n");                                        
 return 1;                                                                 
}                                                                          
void kill_ob(object me)                                                    
{                                                                          
      object ob;                                                           
      ob = this_object();                                                  
      if (!present("jinzhong shan",ob))                                    
                carry_object("/u/fly/jinshan")->wield();                   
      if(me->query("id")!="fly")                                           
      me->set_temp("kill_fly", 1);                                         
      command("hui " + me->query("id"));                                   
              switch(random(4)) {                                          
       case 0 : me->set("title", BLU"��ͽ��"NOR); break;                   
       case 1 : me->set("title", BLU"������Ƥ����"NOR); break;             
       case 2 : me->set("title", BLU"Ϲ��ɫ��"NOR); break;                 
       case 3 : me->set("title", BLU"�廨��ͷһ����"NOR); break;           
       }                                                                   
                     command("chat " + me->query("name") + "�Ǹ�����å��");
                     me->apply_condition("killer", 100);                   
}                                                                          
string ask_tea()                                                           
{                                                                          
        object me,obj;                                                     
        me=this_player();                                                  
        if( !objectp(obj = present("maofeng", me)) ){                      
        command(":)");                                                     
        command("say �õģ�СŮ����͸�����衣\n");                       
        new("/u/fly/tea")->move(me);                                       
        message_vision("$N����һ�������ë���$n��\n",this_object(),me);   
        return "������Ʒ����\n";                                           
        }                                                                  
        else return "���Ǹո�������\n";                                  
}                                                                          
int do_mo(string target)                                                   
{                                                                          
     object me,ob;                                                         
     me = this_player();                                                   
     ob = this_object();                                                   
      if( !target ) return 0;                                              
      if(target == "xue" ||                                                
         target == "xue baochai" ||                                        
         target == "daiyu" ||                                              
         target == "baochai") {                                            
        if((string)me->query("id")=="fly")                                 
            {                                                              
                switch(random(4))                                          
                {                                                          
                case 0 : command("kiss fly");break;                        
                case 1 : command("blush"); break;                          
                case 2 : command("xixi fly"); break;                       
                case 3 : command("lover fly"); break;                      
                }                                                          
                return 0;                                                  
                }                                                          
        if ((string)me->query("gender") == "Ů��") {                       
                command("hmm " + me->query("id"));                         
                message_vision("$N˵�����ø��ᱡŮ�ӣ�\n",ob);             
                return 1;                                                  
                          }                                                
        else {                                                             
          message_vision("$N��������һ�ڣ��ø�����֮ͽ��������ȥ��\n",ob); 
          message_vision("ֻ�������Ҷ��ܽ�������$N�Ұ����˳�ȥ��\n",me);   
          command("chat " + me->query("name") + "�Ǹ��޳�����֮ͽ��");     
          me->move("/d/city/kezhan");                                      
          me->receive_damage("qi", 100);                                   
          me->receive_wound("qi", 50);                                     
          message_vision(me->name() + "�����Ұ����˳�����\n",me);          
          return 1;                                                        
              }                                                            
        }                                                                  
}                                                                          