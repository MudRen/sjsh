
#include <ansi.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[31mڤ���ٷ�ֻ�ܶ�ս���еĶ���ʹ�á�[37m\n");
//             if(me->query("family/family_name")!="��������")
//             return notify_fail("[ڤ���ٷ���ֻ�н������˵��Ӳſ���ʹ�ã�\n");
    if(me->query("swordman/dead_perform")!=1)
    return notify_fail("�㻹ûѧ�ᡸڤ���ٷ�����\n");
	if((int) me->query_skill("huoxin-sword",1) < 250)
		return notify_fail("�����Ȼ������ȼ��������޷�ʹ��ڤ���ٷ���\n");
  if (me->query_temp("dead_busy")) return notify_fail("��û�취����ʹ��ڤ���ٷ���\n");


	message_vision(RED"\n$NͻȻ�彣���ʣ�����������$n�Ĵ���һ�㣬һ��������Ϣ
��ɱ����$N�����ϻ���ɢ��������\n"NOR,me,target);
       me->start_call_out( (: call_other, __FILE__, "kill_him", me, target :), random(5)+5);
	me->start_busy(5);
       me->set_temp("dead_busy",1);
       call_out("remove_effect",6+random(3),me);
	return 1;
}

void kill_him(object me, object target)
{
	string msg;
         string myname=me->name(), npcname=target->name();
	if(me->is_fighting() && 
	environment(me) == environment(target))
	{
msg = RED "\n$Nʹ������Ȼ����������հ���[ڤ���ٷ�]������֮�����˿��Ƶ�
���б�ɱ����ʽ������" ;
msg +=  "\n\n�ƺ����ž���ʮ�����ж�ħ��ף��һ�㣬��������һ�е���̬������
$n���ʺ���Ѫ��һ���������������ҽж���������$n
�㵹����Ѫ��֮�С�\n" NOR;

	message_vision(msg, me, target);
	target->die();
       {
	 message("channel:rumor",HIM"�����Է��ĳ�ˣ�"+npcname+"��"+myname+"����Ȼ���������߰���[ڤ���ٷ�]ֱ����ȥ�˵�����ʬ������ϻ����Ź����Ц�ݡ�\n"NOR,users());
	 }

	}
	return ;
}
void remove_effect(object me) {
  if (!me) return;
  me->delete_temp("dead_busy");
}

