//hongtianza.c ��������֮�������ҡ�
// Modified by stey 2001
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
    string msg,*limbs;
    int i,size,damage;
    object my_w,target_w;
    my_w = me->query_temp("weapon");
    target_w = target->query_temp("weapon");
    if( !target ) target = offensive_target(me);


    if( target->is_busy() )
    return notify_fail(target->name() + "Ŀǰ��ãȻ��֪���룬�ӽ������ɡ�\n"
);
    if( (int)me->query_skill("huoyun-qiang",1) < 10)
    return notify_fail("��Ŀǰ������ʹ�����������ҡ��\n");
    if( (int)me->query("force") < 100 )
    return notify_fail("�������������\n");
    me->add("force", -60);
msg = CYN"$NͻȻ����һ���������ң����ң��������ң��������о�ǹ��Ȼ����$p���б��У�\n"NOR;
    me->start_busy(1);

    if (target->query_temp("weapon") ||
   target->query_temp("secondary_weapon")) {

    if( random(me->query("combat_exp")) >
   (int)target->query("combat_exp")/3 ) {
    if( target_w->weight() > 2 * random(my_w->weight()) ) {
msg += "���$p���е�"+target_w->query("name")+"��$P�ĺ������Ҹ����ţ���Ҳ���ղ��
ס���������ַɳ���\n" NOR;
    target_w->unequip();
    target_w->move(environment(target));
    target->reset_action();
    target->start_busy( (int)me->query_skill("huoyun-qiang") / 20 );
}
   msg += HIC
"ֻ��$n���е�"+target_w->query("name")+"��Ȼ���Ҷ������Σ�����
�ܵ�$N�ľ����ļ�������$nѸ����ȥ��\n"NOR;
    message_vision(msg,me,target);
    target_w->unequip();
    target_w->move(environment(target));
    target_w->set("name", target_w->query("name") + "����Ƭ");
    target_w->set("value", target_w->query("value")/10);
    target_w->set("weapon_prop", 0);
    target->reset_action();
    target->start_busy( (int)me->query_skill("huoyun-qiang") / 20 );
    limbs=target->query("limbs");
    me->start_busy(1);
    msg += "���$p���������������˸����ֲ�����\n" NOR;
    size=(int)(me->query_skill("huoyun-qiang")/10);
    damage=random(size)+size;
damage=damage+me->query_str()/3+random(me->query_temp("apply/damage"));
    for(i=0;i<=random(size);i++)
   {
   msg =HIB"���͡�����Ƭ����$p"+limbs[random(sizeof(limbs))]+"��\n"NOR;
   message_vision(msg,me,target);
   target->receive_damage("kee",damage,me);
   target->receive_wound("kee",damage/3,me);
   }
    COMBAT_D->report_status(target);
    } else {
    msg += "����$p��æ���Լ��ı�����������û����$P�ļ�ı�óѡ�\n" NOR;
    }
    return 1;
    }
    return notify_fail(target->name() + "Ŀǰ�ǿ��֣�������ʲô��\n");
}

