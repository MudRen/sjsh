// /daemon/class/fighter/wusi-mace/andu
// 陈仓暗渡
// 不要自己学什么，完全用对方的武功攻击对方
// 慕容绝学？呵呵。。。
// writted by jie 2001-2-12

#include <ansi.h>

inherit SSERVER;
int perform(object me,object target)
{
        int damage;
        string msg;
        string limb,*limbs,attack_skill,attack;
        object weapon;
        mapping action;
        if( !target ) target = offensive_target(me);

        if(!target||!target->is_character() || !me->is_fighting(target) )
        return notify_fail("陈仓暗渡只能对战斗中的对手使用。\n");
        if( (int)me->query_skill("literate",1)<80)
        return notify_fail("你的读书识字差，怎么晓得行军韬略，用不了「陈仓暗渡」。\n");
                
        if( (int)me->query_skill("wusi-mace",1)<50)
        return notify_fail("你的无私锏法不够娴熟，不会使用「陈仓暗渡」。\n");
        if( (int)me->query_skill("lengquan-force",1)<50)
        return notify_fail("你的冷泉神功不够深厚，不会使用「陈仓暗渡」。\n");
                                
                        
        if( (int)me->query("force",1)<200)
        return notify_fail("你现在内力太弱，不能使用「陈仓暗渡」。\n");
                        
        msg=HIY"$N略一凝神，计上心来，「陈仓暗渡」神功妙计斗然施展！！\n"NOR;

        me->start_busy(3);
        target->start_busy(random(3));
                
        damage = (int)me->query_skill("wusi-mace",1);
                
        damage = damage/2 + random(damage);
                
        target->receive_damage("kee",damage);
        target->receive_wound("kee",damage/3);
        me->add("force",-damage/10);
                
        weapon=target->query_temp("weapon");
        if(objectp(weapon))
                attack_skill=weapon->query("skill_type");
        else
                attack_skill="unarmed";
        attack=target->query_skill_mapped(attack_skill);
        if(!attack)     attack=attack_skill;
        msg +=HIY"$N施施然递出$n所学的\n          ——"HIM+to_chinese(attack)+HIY"——\n好象行军打仗，攻韬守略，居然法度不乱！\n"NOR;

        limbs=target->query("limbs");
        limb = limbs[random(sizeof(limbs))];
        action=target->query("actions");
        if( !mapp(action) ) {
                target->reset_action();
                action=target->query("action");
                
        }
        msg += action["action"]+"！\n";
        msg+=HIR"$n没料到对方递过来的都是自己精妙绝学，顿时惊慌失措！\n结果在$l造成"+action["damage_type"]+"！！\n\n"NOR;
        msg=replace_string(msg,"$l",limb);
        if(objectp(weapon)) msg=replace_string(msg,"$w",weapon->name());
        message_vision(msg, me, target);
        COMBAT_D->report_status(target, 0);
        return 1;
}

