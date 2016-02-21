#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	int mypot,tapot,time;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����־���ֻ����ս���в���ʹ�á�\n");

	if( (int)me->query_skill("liudu-whip", 1) < 60 ) 
		return notify_fail("�����Ϊ�������ʹ������һ�У�\n");


	if( (int)me->query("sen") < 100 ) 
		return notify_fail("��ľ��񲻹����޷�ʹ����һ�У�\n");

	if( target->is_busy() )
		return notify_fail(target->name()+"�Ѿ���æ�ˣ���󵨵Ĺ����ɡ�\n");

	message_vision(HIW"$Nһ����ȣ�һ��"HIG"�����־���"HIW"����$n��$n��ǰ�·������һ�����ߣ�\n\n"NOR,me, target);
	message_vision(HIG"                          _,..,,,_ \n"NOR,me, target);
	message_vision(HIG"                     '``````^~'-,_`'-,_\n"NOR,me, target);
	message_vision(HIG"       .-~c~-.                    `~:. ^-.\n"NOR,me, target);
	message_vision(HIG"   `~~~-.c    ;                      `:.  `-,     _.-~~^^~:.\n"NOR,me, target);
	message_vision(HIG"         `.   ;      _,--~~~~-._       `:.   ~. .~          `.\n"NOR,me, target);
	message_vision(HIG"          .` ;'   .:`           `:       `:.   `    _.:-,.    `.\n"NOR,me, target);
	message_vision(HIG"        .' .:   :'    _.-~^~-.    `.       `..'   .:      `.    '\n"NOR,me, target);
	message_vision(HIG"       :  .' _:'   .-'        `.    :.     .:   .'`.        :    ;\n"NOR,me, target);
	message_vision(HIG"        `-.__,-~                  ~-.        ,' ':    '.__.`    :'\n"NOR,me, target);
	message_vision(HIG"                                     ~--..--'     ':.         .:'\n"NOR,me, target);
	message_vision(HIG"                                                     ':..___.:'\n"NOR,me, target);
	me->add("sen", -100);

	mypot=(int)me->query_skill("whip");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");
    time=(int)me->query_skill("liudu-whip", 1) /10;
	if ( time > 10 ) time = 10;
	if ( time < 5  ) time = 5;

	if ( random( mypot + tapot ) > tapot ) {
		message_vision(HIW"$N���ŵõ�ʱĿ�ɿڴ�����������߲�ס���������ã�\n"NOR,target);
		target->start_busy(time);
	}else {
	message_vision(HIW"�����б�$N���ƣ����䲻����$n�������˸����ֲ�����\n"NOR,target,
me);
		me->start_busy(2);
	}

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }
	return 1;
}
       