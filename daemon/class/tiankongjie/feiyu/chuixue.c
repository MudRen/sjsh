//lost

#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
    object weapon;
        string who1, who2;
    int damage, lvl, r_lvl, count, form, skill, i;
    string msg;

        if( !me->query_skill("feiyu", 1) )
                return notify_fail("�㲻����¥����ѩ��\n");
if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("��Ҫ��˭ʩչ��һ�С���¥����ѩ����\n");
        if( skill > 300 ) skill=300;
        if(me->query("family/family_name") != "��ս�" )
                return notify_fail("�����Ķ�͵ѧ�����书��Ҳ���á���¥����ѩ��?\n");
        if(!me->is_fighting())
                return notify_fail("����¥����ѩ��ֻ����ս����ʹ�ã�\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("�������������\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("����������㣡\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("��ľ����㣬û����ʩ���⹦��\n");
        if((int)me->query_skill("feiyu", 1) < 100)
                return notify_fail("��ķ��������𻹲�����С���߻���ħ��\n");               
        if (me->query_skill_mapped("force")!="mtl-force")
                return notify_fail("��¥����ѩ���������٢���ľ�����ʹ�á�\n"); 
 //               if( time()-(int)me->query_temp("xingyun_end") < 10 )
 //               return notify_fail("�����ö�Ͳ����ˣ�\n"); 
            me->delete("env/brief_message");
            target->delete("env/brief_message");
    skill = (int)me->query_skill("feiyu", 1);
        lvl = skill/20;
        r_lvl = 3+random(lvl);
        if( r_lvl < 1) r_lvl = 1;
        count = me->query_str();
        write( HIW "��Ĭ����٢���ľ���ʹ����¥����ѩ��ƬƬ��ë�������,˲�����������һ������," + target->name() + "�Ĺ������������ء�\n"NOR);
        tell_object(target, HIW"��Ȼ���㷢����һ����ֵ���������Ϯ��,����ƬƬѩ�׵���ë������Χʹ�㶯̽���á�\n"NOR);
 if (random(me->query("force",1)) > 6*target->query("force",1)/5 )
        {
                target->start_busy(random(6));                
                damage = skill/2 + r_lvl*target->query("force_factor",1);                
                target->receive_damage("kee", damage);
                target->receive_wound("kee", damage);
                me->add("force", -damage);
                                msg = CYN "$NĬ���񹦣�ʹ����¥����ѩ��\n"NOR;
                        msg += HIW "�����ֽ�$n������ȫ��������ȥ��\n" NOR;                
                if( damage < 70 )
                        msg += HIM"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
                else if( damage < 300 )
                       msg += HIR"���$n��$N���������𣬡��١���һ������������\n"NOR;
                else if( damage < 450 )
                       msg += RED"���$n��$N�ķ���ƬƬ��͸������\n"NOR;
                else
                       msg += RED"���$n��$N����ë��͸�ض�������\n"NOR;
                message_vision(msg, me, target);
        }
        else 
        {
                tell_object(target, HIW"�����������ƺ��й����������������ĳ��о�Ȼ���˻��������Լ���\n"NOR);
                target->start_busy(random(6));
                message("vision", HIW"\n" + target->name() + "����ë��ס��ƬƬ��ë�������㲻ͣ�����Լ�������\n\n"NOR, environment(me), target);
                for(i = 0; i < r_lvl; i++)
                COMBAT_D->do_attack(target, target, target->query_temp("weapon") );
                me->add("force", -200);
                }

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);}
                                
        }
        me->set_temp("xingyun_end",time());
        me->start_busy(2);
        return 1;
}


