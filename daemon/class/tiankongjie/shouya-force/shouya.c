#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me, object target)
{
        object *ob;
        int i, skill, damage, force;

        if( (int)me->query("force") < 1500 )
                return notify_fail("����������������ðʧ�˹���С�ı����ɡ�\n");
        if( (int)me->query("kee") < 1500)
                return notify_fail("������������ˣ�û��ʵ���ֿ��Լ������ĺ�����\n");

        if((int)me->query_skill("shouya-force", 1) <150)
                return notify_fail("�������ħ�����𻹲�����\n");

        if(!me->is_fighting())
                return notify_fail("�������ҹⵯ��ֻ����ս����ʹ�ã�\n");
        skill = me->query_skill("force");
        force = me->query("max_force");
        me->add("force", -1000);
        me->receive_damage("kee", 100);

        me->start_busy(2);
        message_vision(HIW "
$N������Ц�����һ���������ҹⵯ����
�漴˫���ſ���Ԫ������ͬ����������$N��������ɳ���
һʱ�䣬��ؼ�����һƬ��Ϣ�����գ��·�$N�ܻ���һ�У���Ҳ�����Ѫ��ɫ��
\n"
NOR, me);
        ob = all_inventory(environment(me));
        for(i=0; i<sizeof(ob); i++) {
                if( !living(ob[i]) || ob[i]==me ) continue;
                if( skill/2 + random(skill/2) < (int)ob[i]->query("cps") * 2 ) continue;

                damage = skill + force/5 - ((int)ob[i]->query("max_force") / 20);
                if( damage > 0 ) {
                        ob[i]->receive_damage("kee", damage);
                        if( (int)ob[i]->query("force") < skill * 2 )
                                ob[i]->receive_wound("kee", damage/2);
                        tell_object(ob[i], HIR"��е�һ����Ϣ����������Ԫ�����������ͬ˺��һ�㣬\n��ʹ����е�������Ľ��٣�\n"NOR);
                }
                COMBAT_D->report_status(ob[i]);         
                if( userp(ob[i]) ) ob[i]->fight_ob(me);
                else if( !ob[i]->is_killing(me) ) ob[i]->kill_ob(me);

        }

        return 1;
}

