#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int xiaohunqin,qin,ini_damage_apply,times,damage;
   string desc_msg="";
  int sword_level;
        
        xiaohunqin = (int)me->query_skill("xiaohunqin", 1);
        qin = (int)me->query_skill("qin", 1);
        
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ�������ķ�����\n");

        if(!me->is_fighting())
                return notify_fail("�������ķ���ֻ����ս����ʹ�ã�\n");


        if((int)me->query("max_force") < 3000 )
                return notify_fail("��������������޷�ʩչ�������ķ�����\n");

        if((int)me->query("force") < 1500 )
                return notify_fail("����������㣬�޷�ʩչ�������ķ�����\n");

        if((int)me->query("sen") < 800 )
                return notify_fail("��ľ����㣬�޷�ʩչ�������ķ�����\n");
        sword_level=(int)(xiaohunqin/50);
        if( xiaohunqin < 250)
                return notify_fail("��������ټ��𻹲������޷��������յ����裡\n");

        if((int)me->query_skill("piaoxiang",1) < 250 )
                return notify_fail("���Ѫ��Ʈ�㼶�𻹲������޷��������յ����裡\n");
        if((int)me->query_skill("lingxiyizhi",1) < 250 )
                return notify_fail("�����Ϭһָ���𻹲������޷��������յ����裡\n");
        
        if( qin < 250)
                return notify_fail("���������Ϊ�������޷�ʹ����һ�У�\n");
        
                
        
        if( time()-(int)me->query_temp("wuxue_end") < 10 )
                return notify_fail("�����ʹ������������ʱ�޷�ʩչ�������ķ�����\n");
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "��";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N����һЦ���˾��־��������������٣���ʱ�����������£���������������$n��\n"NOR,me,target);
        damage=1;
        //ǰ����
        message_vision(HIC"\n$Nͬʱ������������������������繥��$n��\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",100);
        me->set_temp("WX_perform", 0);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) {me->add_temp("apply/damage",100);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //������
        if( xiaohunqin > 249 && qin > 249 )
            {
                message_vision(HIC"\n$N��Хһ�����Գ��֣�����ǿ������,�������ײ���,��ʹ�������С�\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              }
      
           //�������
           if( xiaohunqin > 279 && qin > 279 )
               {
                    message_vision(HIC"\n$N���һ��,�Ų�ǰ��,�ӹ�������������㹥��$n��\n"NOR,me,target);
                    
                    if (damage < 1) {me->add_temp("apply/damage",100);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 9);
                    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      
                     if (damage < 1) {me->add_temp("apply/damage",300);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 10);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
                                  }
                        
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->receive_damage("sen", 100);
        me->add("force", -1000);
        me->start_busy(3);
        me->set_temp("wuxue_end",time());
        return 1;
}
