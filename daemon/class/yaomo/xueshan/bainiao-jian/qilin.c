#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int i;
        string str;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С������ʽ����\n");

        if(!me->is_fighting())
                return notify_fail("�������ʽ��ֻ����ս����ʹ�ã�\n");
         
        if(me->query("family/family_name")!="��ѩɽ")
                return notify_fail("�㲻���ñ��ɵ����⹥��\n");

        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");

         if((int)me->query("force") < 900 )
                return notify_fail("����������㣡\n");

        if((int)me->query("kee") < 200 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");

              i=(int)me->query_skill("bainiao-jian",1)+(int)me->query_cor();

        if( i < 120)
                return notify_fail("��İ��񽣷��𻹲�����ʹ����һ�л������ѣ�\n");

        message_vision(HIC"$N���һ���޺������⥣�״�����룬����"+me->query_temp("weapon")->name()+
                                      HIC"��ͻ�һ��������뵣��������ʽ���ľ��辡չ���ɣ�\n"NOR,me,target);

        me->delete("env/brief_message");
        target->delete("env/brief_message");

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->set_temp("QJB_perform", 10);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("QJB_perform");

        me->receive_damage("kee", 200);
        me->add("force",-300);
           me->start_busy(1+random(1));

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
           if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=HIW+target->name()+HIM"��"HIG+me->name()+HIM"�ð��񽣷�֮����"+HIY+"�������ʽ��"+HIM+"ɱ���ˣ���˵"+target->name()+"���оŽ�,ʬ�ױ�����������ѣ�";
                         message("channel:rumor",HIM"��"+HIC+"��������"+HIM+"��ĳ�ˣ�"+str+"\n"NOR,users());                       
                       }


        return 1;
}


