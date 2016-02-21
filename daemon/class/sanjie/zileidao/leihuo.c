
// leihuo.c �׻��ɱ
// by stey
 
#include <ansi.h>
 
inherit SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
        int skill, ap, dp;
        int force_wound, kee_wound ;

	me->clean_up_enemy();
	target = me->select_opponent();

        skill = me->query_skill("zileidao",1);

	if( !(me->is_fighting() ))
                return notify_fail("���׻��ɱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
  if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "blade")
   return notify_fail(RED"��ʲô��Ц��ûװ������ôʹ���׻��ɱ����\n"NOR);

	if( skill < 60)
                return notify_fail("��ġ����׵������ȼ�����, ����ʹ�����׻��ɱ����\n");

	if( me->query("force") < 150 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ�ʹ��һ�С��׻��ɱ������$n���ؿڻ�ȥ��\n"NOR;

	message_vision(msg, me, target);

	ap = me->query("combat_exp") + skill * 400;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{
		if(userp(me))
			me->add("force",-100);

                msg = HIG "$nֻ������ǰһ�ڣ����ۡ���һ�����һ����Ѫ��\n"NOR;

		force_wound = 100 + random(skill)*2;
		if(force_wound > target->query("force"))
			force_wound = target->query("force");


		kee_wound = force_wound / 2;
//                if(kee_wound > target->query("kee"))
//                        kee_wound = target->query("kee");

		target->add("force", -force_wound);
		target->add("kee", -kee_wound);
	target->add("eff_kee",-kee_wound);
		target->start_busy(2+random(2));
		me->start_busy(random(3));
	}
	else
	{
		msg = HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me))
			me->add("force",-100);
		me->start_busy(1+random(2));
	}
	message_vision(msg, me, target);

	return 1;
}
