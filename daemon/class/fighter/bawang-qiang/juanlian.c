//juanlian.c by peaceful

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void juanlian_ok(object);
int perform(object me, object target)
{
        int damage;
              object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С����鵹��������\n");
        if(!me->is_fighting())
                return notify_fail("�����鵹������ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("�������������\n");
          if((int)me->query("force") < 300 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("bawang-qiang", 1) < 100)
                return notify_fail("��İ���ǹ���������죬ʹ����һ�л������ѣ�\n");
         if(me->query_temp("no_juanlian"))
                        return notify_fail("���ù����У�������δ�ָ����Ȼ�����ðɣ�\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIC"\n$N�����б���һ�������¶��Ϸ���������һ�ɴ�����$n��ӿ����������ɳ��ˮ����Ļ������\n"NOR,me);

               me->set_temp("TP_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("TP_perform");

        me->receive_damage("sen", 50);
        me->add("force", -150);
        me->set_temp("no_juanlian",1);
                call_out("juanlian_ok",2+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}
void juanlian_ok(object me)
{ if (!me) return;
      me->delete_temp("no_juanlian");
}
