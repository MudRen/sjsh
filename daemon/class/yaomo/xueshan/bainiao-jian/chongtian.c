//By exp
#include <condition.h>
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string str;
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("bainiao-jian",1);
        if ( extra < 260) return notify_fail("��İ��񽣷����������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۽��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
if(me->query("family/family_name")!="��ѩɽ")
    return notify_fail("�����͵ѧ����?\n");
if( (int)me->query_skill("sword", 1) < 280 )
    return notify_fail("��Ļ�������̫�ͣ�\n");
        if( (int)me->query_skill("force", 1) < 250 )
    return notify_fail("����ڹ�������죬ʹ�����۽�������ݣ�\n");
if( (int)me->query("max_force") < 2500 )
    return notify_fail("������������Ϊ���㣬ʹ�����۽�������ݣ�\n");    
 if( (int)me->query("force") < 1000 )
         return notify_fail("�������������㣬ʹ�����۽�������ݣ�\n");         
    weapon = me->query_temp("weapon");
       me->add_temp("apply/damage",extra*5);
        message_vision(HIW"$N���е�"+ weapon->name()+  "һ���ʣ��ͻ���һ���⻪����$n��һ�����εĹ⻪�����á��Ի͡�������\n" + HIG"�⻪����������á��߸����ϣ�����Ʈ����$nֻ��������⻪�ݷ�����Լ�ü��
�䣬ȴ�ֲ���ȷ������������ı仯�������ѳ�Խ�����������ļ��ޣ������������޷����š�"NOR,me,target);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIY"������ȷʵ����������޴����ڡ����Ǿ���$n��ȷ��������ʱ������Ȼ�ֲ���
�ˡ�"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        message_vision(WHT"���漣���Ȼ���֣����漣���Ȼ��ʧ��"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       message_vision(HIR"���еĶ����ͱ仯��������һɲ�Ǽ���ɣ���ֹ�����������ǣ�ȴ���������磬ȴ�ֱ�
���Ǻ�������ӽ��漣����Ϊ�߶���仯������������$N�������ġ�"NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->add_temp("apply/damage",-extra*5);
           me->start_busy(1+random(1));
        if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0)) 
{str=HIW+target->name()+HIM"��"HIG+me->name()+HIM"�İ���֮��ѧ"+HIY+"���������졹"+HIM+"ɱ���ˣ���˵"+target->name()+"ʬ���ϲ����������������ۣ�";
message("channel:rumor",HIM"��"+HIR+"��������"+HIM+"��ĳ�ˣ�"+str+"\n"NOR,users());
}

        return 1;
}


