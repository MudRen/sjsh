//����ħ�ǵ�
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int addon, tmp, atk;
        object weapon;
        extra = me->query_skill("tianlang-blade",1);
        if ( extra < 150) return notify_fail("�������ҹħ�����������죡\n");

        addon = me->query_skill("shouya-force",1);
        tmp= me->query_skill("force",1);
        if ( addon < 120 )return notify_fail("�������ħ�����������죡\n");
        if ((int)me->query("force")<1000)
                return notify_fail("������������ˡ�\n");
        
        if(me->query("family/family_name") != "��ս�")
                return notify_fail("��ʡʡ���ˡ�\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("û�±����ü���ħ�ǵ���\n");
        
        atk = (addon+tmp)/2;
        me->add_temp("apply/attack",atk);
        me->add_temp("apply/damage",extra);
        weapon = me->query_temp("weapon");
        message_vision(HIW"\n$N������ͨ��������ħ����ת���죬���弱��ʩչ������ħ�ǵ��ľ�����\n "NOR, me,target);
        message_vision(HIC"���������籩�������$n\n"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(HIM"$N�ڱ������ĵ�����Ʈҡ���������$n����������һѸ���ޱȵĿ���$N������\n"NOR,target,me);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-atk);
        me->add_temp("apply/damage",-extra);
        me->add("force",-500);
        me->start_busy(random(4));
        return 1;
}

