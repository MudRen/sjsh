#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
        string str;

	object weapon;
	extra = me->query_skill("feitian-sword",1);
	if ( extra < 180) return notify_fail("��ġ����������������������죡\n");
           if(me->query("family/family_name")!="��������")
           return notify_fail("����ͷ������ֻ�н������˵��Ӳſ���ʹ�ã�\n");
       if(me->query("swordman/jiulong_perform")!=1)
                return notify_fail("�㻹ûѧ�ᡸ��ͷ��������\n");
        if( (int)me->query("max_force") < 1500 )      
                return notify_fail("�������������\n");
        if( (int)me->query("force") < 1000 )      
                return notify_fail("����������㡣\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����ͷ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra);
	weapon = me->query_temp("weapon");
	  message_vision(WHT  "\n\n$N�ӳ������������еľ�����ص�һʽ�������ţ�ͷ��������������\n\n" NOR,me,target);
        message_vision(YEL  "\n��������" NOR,me,target);
	  COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision( HIC  "\nˮ������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIW  "\nľ������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        
              if( (int)me->query_skill("feitian-sword", 1) > 200 )   {
        message_vision(HIG  "\n��������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM  "\n��������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIR  "\n��������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              }
  
              if( (int)me->query_skill("feitian-sword", 1) > 250 )   {
              message_vision(HIB  "\n��������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(MAG  "\n��������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(RED  "\n��ͷ������" NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              }
                     if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�÷������������塺"HIW"��ͷ����"HIM"��ɱ���ˡ�";
        message("channel:rumor",HIM"��"HIW"��Ѩ����"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());;
	               }

       me->add("force", -500);
        me->receive_damage("sen", 100);
       me->start_busy(2+random(2));
       me->add_temp("apply/attack",-extra);
       me->add_temp("apply/damage",-extra);
	return 1;
}
