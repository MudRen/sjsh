#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
       object weapon;
            int extra;        
	if( !target ) target = offensive_target(me);
       if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
       return notify_fail("��Ҫ��˭ʩչ��һ��˫�ؼ��ޣ�\n");
       if(!me->is_fighting())
       return notify_fail("˫�ؼ���ֻ����ս����ʹ�ã�\n");
	if(me->query("family/family_name")!="��������")
       return notify_fail("��˫�ؼ��ޡ�ֻ�н������˵��Ӳſ���ʹ�ã�\n");
       if((int)me->query("force") < 800 )
       return notify_fail("�������������\n");
       if((int)me->query_skill("kongshoudao", 1) < 100)
       return notify_fail("��Ŀ��ֵ����𻹲�����ʹ����һ�л������ѣ�\n");
	me->delete("env/brief_message");
	extra = me->query_skill("kongshoudao",1);
	message_vision(HIY "\n$NͻȻ���һ������ȭЮ����֮����$n���ؿڻ�����\n"NOR, me,target);
	me->add_temp("apply/attack", extra);	
	COMBAT_D->do_attack(me, target);
	me->add_temp("apply/attack", -extra);
            if((int)me->query_skill("kongshoudao",1)>=200 && random(me->query("str"))>random(target->query("str")))
            {
            message_vision(HIR "\n����$n��Ϊ$Nȭ������֮ʱ��$N����ȭ��Ȼ����ǰ���ٻ�����
��һ�У����Ǿ�����˫��[˫�ؼ���]��\n"NOR,me,target);
	me->add_temp("apply/attack", extra);
	me->add_temp("apply/damage", extra);	
	COMBAT_D->do_attack(me, target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
            }
	me->start_busy(2+random(1));
	return 1;
}
