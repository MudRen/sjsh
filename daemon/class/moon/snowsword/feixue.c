#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,moonforce,moondance,ini_damage_apply,times,damage;
   string desc_msg="";
  int sword_level;
        
        snowsword = (int)me->query_skill("snowsword", 1);
        moonforce = (int)me->query_skill("moonforce", 1);
        moondance = (int)me->query_skill("moondance", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ����ѩ���졹��\n");

        if(!me->is_fighting())
                return notify_fail("����ѩ���졹ֻ����ս����ʹ�ã�\n");
        
        
        sword_level=(int)(snowsword/80);
        if( snowsword < 80)
                return notify_fail("��ķ��ѩ�轣�����𻹲�����ʹ����һ�л������ѣ�\n");

        if(me->query("family/family_name") != "�¹�")
                return notify_fail("[��ѩ����]���¹�����֮�ܣ�\n");
        
        if( moonforce < 80)
                return notify_fail("���Բ���ķ���Ϊ������ʹ����һ�л������ѣ�\n");
        
        if( moondance < 80)
                return notify_fail("������������輶�𻹲�����ʹ����һ�л������ѣ�\n");
                
        if( me->query("force_factor") > 0)
                return notify_fail("����ѩ���졹�������в������������������ܽ������飿\n");
        
        if( time()-(int)me->query_temp("feixue_end") < 10 )
                return notify_fail("�����ö�Ͳ����ˣ�\n");
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "��";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N��߳һ�����ż�һ�㣬���弱���������ڰ����һ��������
ͬʱ�����ᶶ��������������ѩ����Ҷ����$n��\n"NOR,me,target);
        damage=1;
        //��ѩ��ʽ        
        message_vision(HIC"\n$Nͬʱʹ�����ѩ�轣�ķ�ѩ��ʽ ���ڰ����ѹ��$n��\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",30);
        me->set_temp("WX_perform", 6);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) {me->add_temp("apply/damage",30);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 7);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        if (damage < 1) {me->add_temp("apply/damage",30);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 8);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //������ʽ
        if( snowsword > 119 && moonforce > 119 && moondance > 119 )
            {
            	message_vision(HIC"\n$N��������Ʈ�������̤�������־ʹ̳����Ľ���\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 9);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 10);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 11);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 12);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

              }
      
           //��ѩ����
           if( snowsword > 179 && moonforce >179  && moondance > 179 )
               {
               	    message_vision(HIC"\n$N���������������Ϊ���ѩ��������䣬����һ�ɺ�������$n��\n"NOR,me,target);
               	    
                    if (damage < 1) {me->add_temp("apply/damage",30);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 13);
                    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                     if (damage < 1) {me->add_temp("apply/damage",90);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 14);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                    
                    if (damage < 1) {me->add_temp("apply/damage",90);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 15);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"��"+me->name()+"���¹����С���ѩ���졹ɱ���ˡ���˵ʬ�屻�ָ����"+desc_msg+"ʮ���ˣ�";
//                     message("channel:rumor",HIM"���¹����ӡ�ĳ�ˣ�"+str+"\n"NOR,users());
	               }
	          }
	                
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

         me->set_temp("feixue_end",time());
        return 1;
}

