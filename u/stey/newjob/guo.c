// �¶�ֵ����                                                                 
//created 4-8-97 pickle                                                     
inherit NPC;
#include <ansi.h>
#include "zzzjob.c"
#include "teamjob.c"
string ask_newjob();
string ask_newover();
int job_over(string arg);
                                                            
                                                                            
void create()                                                               
{                                                                           
        set_name("ʱֵ����", ({ "shizhi gongcao", "shi", "hour",            
"gongcao" }) );                                                             
        set("gender", "����" );                                             
        set("long","                                                        
��ֵ��������������������ǰ�ͽ������鲻���                                
��սʧ��������ΪѲ�߹١�������־ͬ���϶���Ϊ                                
�����ֵܡ�ʱֵ����������ô������������ء���                                
���������ֵ�����ߣ�����ȱ�����顣\n"                                       
        );                                                                  
        set("age",35);                                                      
        set("str",25);                                                      
        set("int",25);                                                      
        set("max_kee",1000);                                                
        set("kee",1000);                                                    
        set("max_sen",1000);                                                
        set("sen",1000);                                                    
        set("daoxing",1490000);                                              
        set("combat_exp",1490000);                                           
        set("force",2000);                                                  
        set("max_force",2800);                                               
        set("mana",2500);                                                   
        set("max_mana",2000);                                                
        set("force_factor", 150);                                            
        set("mana_factor", 150);                                             
                                                                            
//        set("eff_dx", 200000);                                              
//        set("nkgain", 300);                                                 
                                                                            
        set_skill("unarmed",300);                                           
        set_skill("parry",300);                                             
        set_skill("dodge",300);                                             
        set_skill("spear",300);                                             
        set_skill("bawang-qiang",300);                                      
	set_skill("moshenbu", 300);                                         
        set_skill("force",300);                                             
	set_skill("spells", 300);                                           
        set_skill("dragonfight",300);                                        
	map_skill("unarmed", "dragonfight");                                
	map_skill("dodge", "moshenbu");                                     
	map_skill("spear", "bawang-qiang");                                 
        map_skill("parry","bawang-qiang");                                  
        set("inquiry", ([                                                   
                "name" : "���¾���ʱֵ���ܣ�������������ǰ�󽫡�",          
                "here" : "��������칬���¹ٷ���������ڴ�Ѳ�顣",        
                       "job"   : (: ask_job :),
         "����"  : (: ask_gonglao :),
         "fangqi": (: ask_fangqi :),
         "����"  : (: ask_fangqi :),
	       	 "��ϸ"  : (: ask_jianxi :),
                "�ع�" : (: ask_newjob :),
                "job2"  : (: ask_newjob :),
                "����"  : (: ask_newover :),
	       	]));
 
	       
 setup();
        carry_object("/d/obj/weapon/spear/biyuqiang")->wield();
        carry_object("/d/obj/armor/yinjia")->wear();
}

void init()
{
        add_action("job_over","task");
}

string ask_newjob()
{
        object *ene;
        object me = this_player();

        if(is_fighting()) 
        {
                ene=query_enemy();
                
                if(sizeof(ene)>1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ���"+sizeof(ene)+"λ�����д輸�£���\n";
                if(sizeof(ene)==1) return "����"+RANK_D->query_respect(me)+"�Ե�Ƭ�̣����Ⱥ�"+ene[0]->name()+"�д輸�£���\n";
        }

        if(me->query_temp("mark/job_shadi")>0 ) return "��"+RANK_D->query_respect(me)+"���������������𣡡�\n";

/*        if((int)me->query("shen") < 0) return "��"+RANK_D->query_respect(me)+"�������������ǲ���ӭ����\n";
*/     
        if ((int)me->query("combat_exp")<100000) return "��"+RANK_D->query_respect(me)+"���޸���֮�������Ǳ��������Ϊ�ã���\n";

    if ( (int)me->query_skill("force") < 80 )
       return "���칬�Ǽ�Σ�չ������ҿ�"+RANK_D->query_respect(me)+"�Ļ����������㣡\n";

      if ((int)me->query_condition("jobshadi_failed"))
{
     message_vision("$N����$nҡ��ҡͷ˵������ʧ���˻�������??\n", this_object(), me);
return "��"+RANK_D->query_respect(me)+"�㻹�Ǳ��������Ϊ�ã���\n";
//return;
}

      if ((int)me->query_condition("jobshadi_limit")>1)
{
     message_vision("$N����$nҡ��ҡͷ˵���㲻����������??\n", this_object(), me);
return "��"+RANK_D->query_respect(me)+"���������ϼ�ȥ����\n";
//return;
}
   if ((int)me->query_condition("guojob2_busy"))
{
     message_vision("$N����$nҡ��ҡͷ˵������ħ���������ڹ�����칬����\n", this_object(), me);
return "��"+RANK_D->query_respect(me)+"��Ȼ���������\n";
//return;
}
	if (me->query("force")>0)
	{
        switch( random(2) ) {
                case 0:
			me->set_temp("mark/job_shadi",1);
        	        me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",4);
                return "������ħ�������ַ�����칬����λ"+RANK_D->query_respect(me)+"ȥ�������Ű�������칬�ɡ�";

	               break;
                case 1:
			me->set_temp("mark/job_shadi",2);
                	me->set_temp("carry_location","northgate1");		
                me->apply_condition("guojob2_busy",4);
                return "������ħ�������ַ�����칬����λ"+RANK_D->query_respect(me)+"ȥ�����Ű�������칬�ɡ�";

	               break;
        	}	
        }
        else
        {
        switch( random(2) ) {
                case 0:
                	me->set_temp("mark/job_shadi",3);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",4);
                return "������ħ�������ַ�����칬����λ"+RANK_D->query_respect(me)+"ȥ�����Ű�������칬�ɡ�";

	               break;
                case 1:
                	me->set_temp("mark/job_shadi",4);
                	me->set_temp("carry_location","southgate1");
                me->apply_condition("guojob2_busy",4);
                return "������ħ�������ַ�����칬����λ"+RANK_D->query_respect(me)+"ȥ�����Ű�������칬�ɡ�";

	               break;
        	}
        }
}

int job_over(string arg)
{
        int job_pot,job_exp;
        object me = this_player();

        if(!arg) return 1;

        if(arg!="over") return 1;
	if(me->query_temp("help_killed")>0)
	{
        	message_vision(CYN "$N������$n�ļ��˵������"+RANK_D->query_respect(me)+"��Ϊ����칬ɱħ����������\n" NOR, this_object(), me);
	        job_exp=((int)me->query_temp("killed_mgb"))*80;
                  job_pot=job_exp*2/3;
                  job_exp=job_exp;
	        me->add("combat_exp", job_exp);
	        me->add("potential",job_pot);
tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��\n"+chinese_number(job_pot)+"��Ǳ��\n");
	        me->delete_temp("killed_mgb");        
                me->delete_temp("job_over");
                me->delete_temp("mark/job_shadi");
                me->delete_temp("help_killed");

                me->apply_condition("guojob2_busy",4);
        	return 1;
        }
        	
        if(me->query_temp("mark/job_shadi")==0)
        {
                message_vision(CYN"$N����$nһ��:��û����ʲô��ɲ���ɡ���\n",this_object(),me);
                return 1;
        }
        
        if(me->query_temp("job_over")==0)
        {
                message_vision(CYN"$N����$nһ��:������û��ɡ���\n"NOR,this_object(),me);
                return 1;
        }

       if(me->query_temp("killed_mgb")<2)
       {
                  message_vision(CYN"$N����$nһ��:����ɱ�˼������ˣ��㻹�����ͣ�����\n"NOR,this_object(),me);
         me->delete_temp("job_over");
         me->delete_temp("mark/job_shadi");
                  return 1;
          }

        message_vision(CYN "$N��$n˵������"+RANK_D->query_respect(me)+"�����ˣ�ȥ��Ϣһ�°ɣ���\n" NOR, this_object(), me);
        me->delete_temp("job_over");
        me->delete_temp("mark/job_shadi");
        job_exp=((int)me->query_temp("killed_mgb"))*80;
        job_pot=job_exp*2/3;
        job_exp=job_exp;
tell_object(me, "�㱻������"+chinese_number(job_exp)+"�㾭��ֵ��\n"+chinese_number(job_pot)+"��Ǳ��\n");
        me->apply_condition("guojob2_busy",4);
        me->add("combat_exp", job_exp);
        me->add("potential",job_pot);
        me->delete_temp("killed_mgb");        
        return 1;

}

string ask_newover()
{
         object me;
         me = this_player();
          if(me->query_condition("jobshadi_limit")<=1)
         return "��û��������,������Ϲ����ʲ��?";
         me->clear_condition("jobshadi_limit");
         me->add("combat_exp",-100+random(20));
         me->apply_condition("jobshadi_failed",6);
         me->delete_temp("mark/job_shadi");
	 me->delete_temp("carry_location");
         me->delete_temp("job_over");
         me->delete_temp("start_job");
	 return "û��ϵ,�´μ���Ŭ�� ��";
}
