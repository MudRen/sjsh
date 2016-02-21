// nuhuoyanling.c
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	int success_adj, damage_adj;
        string str;

//	success_adj = 200;
//	damage_adj = 190;
        success_adj = 200;
	damage_adj = 190;
 

	if( !target ) target = offensive_target(me);

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("��Ҫ��ŭ��������˭��\n");

        if(me->query("family/family_name")!="��������")
                return notify_fail("���ǽ������˵��Ӳ����á�ŭ�����项��\n");

	if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
		return notify_fail("��ķ���������\n");

	if((int)me->query("sen") < 20 )
		return notify_fail("���޷����о������������Լ��ˣ�\n");

	me->add("mana", -25-2*(int)me->query("mana_factor"));
	me->receive_damage("sen", 10);

	if( random(me->query("max_mana")) < 50 ) {
		write("����û��Ӧ������һ�ΰɣ�\n");
		return 1;
	}

	SPELL_D->attacking_cast(
		me, 
			//attacker 
		target, 
			//target
		success_adj, 	
			//success adjustment
		damage_adj, 	
			//damage adjustment
		"both", 		
			//damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
		HIR "$N˫�ֺ�һ�����˼�������,����ð������,����$n����~!\n" NOR,
			//initial message
		HIR "������˸����ţ����û��$n������\n" NOR, 
			//success message
		HIR "����$n��ǧ��һ��֮�ʶ��˿�����\n" NOR, 
			//fail message
		HIR "����ŭ�����鱻$n�Է���һ��������Ʈ������$N�Ķ��ţ�\n" NOR, 
			//backfire initial message
		HIR "����ո����ţ����û��$n������\n" NOR
			//backfire hit message. note here $N and $n!!!
	);
        if (target->query("eff_kee")<0 || !living(target))  
{str=target->name()+"��"+""HIW""+me->name()+""HIM""+"�ý������˾��С�"HIR"ŭ������"HIM"�������ˡ���˵"+target->name()+"ʬ�嶼�Ѿ��ս���!";
        message("channel:rumor",HIM"��"HIW"��������"HIM"��ĳ�ˣ�"+str+"\n"NOR,users());

        }
        me->start_busy(1+random(1));
	return 3+random(5);
}

