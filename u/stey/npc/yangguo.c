inherit NPC;                                                                                         
inherit F_MASTER;                                                                                     
#include <ansi.h>                                                                                     
string ask_me();                                                                                      
void create()                                                                                         
{                                                                                                     
        set_name("���", ({ "yang guo", "yang" }));                                                   
        set("nickname", "�����");                                                                    
      set("long",                                                                                     
                "�����������������һ����񳿡������ף���ü���ޣ�����������\n"                      
                "��Ȼ��ֻ��һֻ�첲�����ǿ�ΰ����������˸о�Ӣ�����ˡ�\n");                          
        set("gender", "����");                                                                        
        set("age", 32);                                                                               
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
        set_skill("force", 200);                                                                      
        set_skill("dodge", 200);                                                                      
        set_skill("parry", 200);                                                                      
        set_skill("unarmed", 200);                                                                    
        set_skill("sword", 200);                                                                      
            set("inquiry",                                                                            
                ([                                                                                    
                           "����֮��" : (: ask_me :),                                                 
              ]));                                                                                    
        create_family("��Ĺ��", 2, "�������");                                                       
        setup();                                                                                      
      carry_object("/u/stey/obj/jzj")->wield();                                                        
}                                                                                                     
                                                                                                      
void attempt_apprentice(object ob)                                                                    
{                                                                                                     
        mapping fam;                                                                                  
        ob = this_player();                                                                           
        fam = ob->query("family");                                                                    
       if (!fam || fam["family_name"] != "��Ĺ��"){                                                   
                command("say "+RANK_D->query_respect(ob)+"���ҹ�Ĺ���ˣ���֪�˻��Ӻ�̸��");         
                return;                                                                               
                }                                                                                     
//        for(i=0; i<sizeof(skl); i++) {                                                              
//              if (skl[sname[i]] < 100)                                                              
//              command("say ��Ĺ�Ļ�����ѧδ��������ѧ���ҵĹ��򣬻��ǻ�ȥ�Ȱ��书������ðɡ�");    
//                return;                                                                             
//      }                                                                                             
        if ((int)ob->query_skill("yunu-xinjing",1)<100){                                              
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "�����Ů�ľ�δ��������������ߵ���ѧ��");                                    
                return;                                                                               
                                                                                                      
}                                                                                                     
       if ((int)ob->query_skill("yunu-shenfa",1)<100){                                                
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "�����Ů��δ��������������ߵ���ѧ��");                                    
                return;                                                                               
        }                                                                                             
        if ((int)ob->query_skill("yunu-jianfa",1)<100){                                               
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "�����Ů����δ��������������ߵ���ѧ��");                                    
                return;                                                                               
        }                                                                                             
      if ((int)ob->query_skill("cuff",1)<100){                                                        
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "��Ļ���ȭ��δ��������������ߵ���ѧ��");                                    
                return;                                                                               
        }                                                                                             
        if ((int)ob->query_skill("sword",1)<100){                                                     
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "��Ļ�������δ��������������ߵ���ѧ��");                                    
                return;                                                                               
        }                                                                                             
     if ((int)ob->query_skill("strike",1)<100){                                                       
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "��Ļ����Ʒ�δ��������������ߵ���ѧ��");                                    
                return;                                                                               
        }                                                                                             
       if (ob->query_int() < 30) {                                                                    
                command("say ��λ" + RANK_D->query_respect(ob) +                                      
                        "��Ŀǰ����������������ߵ���ѧ��");                                          
                return;                                                                               
        }                                                                                             
   message_vision(HIY "���ͻȻ΢һ����������Խ����ʾ��һ��������������ˮ����������׷�¡�\n"NOR,ob);
       write(HIY"�㿴�ſ��ţ�ͻȻ�����������һ�㣬�������1��\n"NOR);                            
                                                                                                      
        command("pat " + ob->query("id"));                                                            
        command("chat* ���ϸ��ֳ�һ˿Ц�ݣ�Ȼ��������Ŀ���һ��С��Ů��");                            
        command("recruit " + ob->query("id"));                                                        
        ob->set("title",HIW"��Ĺ��������´���"NOR);                                                  
        ob->add("dex",1);                                                                             
}                                                                                                     
string ask_me()                                                                                       
{                                                                                                     
       mapping fam;                                                                                   
       object ob;                                                                                     
       ob = this_player();                                                                            
       if (!(fam = this_player()->query("family")) || fam["family_name"] != "��Ĺ��"                  
             ||  fam["master_name"] != "���")                                                        
               return RANK_D->query_respect(this_player()) +                                          
               "���ҹ�Ĺ����,��֪���˻�����?";                                                        
          if (!ob->query_temp("xth_hm"))                                                              
            return RANK_D->query_respect(this_player()) +                                             
               "��֪��ʲ������֮����?";                                                               
                      ob->delete_temp("xth_hm");                                                      
               ob->set_temp("make/xtj_look1",1);                                                      
            ob->set_temp("yg_pbask",1);                                                               
       return "������Ϣ,��������,˫�����,���ص���,�����ں�ˮ�������ľ���,��ú�ȥ����һ��.";         
}                                                                                                     
                                                                                                      
void kill_ob(object me)                                                                               
{                                                                                                     
        command("chat* nomatch " + me->query("id"));                                                  
                                                                                                      
        ::kill_ob(me);  
}                                                                             