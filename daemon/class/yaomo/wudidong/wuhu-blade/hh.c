
//hh.c   wosshipg
#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int calculate_damage(object me, object target, int base_damage, int damge_bonus);
int perform(object me, object target)
{
	string msg, str;
	int mydf;
	int ap, dp, pp;
	int youcps, mycor, mystr, youstr;
	int damage_bonus, damage, wound;
	int delay;
	object ob;

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                  return notify_fail("����ս���У���ô��pfm��\n");

mydf=(int)me->query_skill("wuhu-blade",1);
if(mydf<100) 
                return notify_fail("�����Ϊ���������������廢���ŵ��ľ��衣\n");
                  if(me->query("family/family_name")!="�ݿ�ɽ�޵׶�")
                  return notify_fail("�㲻���޵׶��ĵ��ӣ������ô��У�\n");

          mydf=(int)me->query_skill("huntian-qigong",1);
          if(mydf<100) 
                  return notify_fail("�����Ϊ����������������廢���ŵ��ľ��衣\n");
 if(environment(me)!=environment(target))
     notify_fail("��Ҫ�������˲������\n");
	if((int)me->query("force")<500) return
	    notify_fail("������������ˡ�\n");

            msg = HIR "$Nʹ��һ��--������ʳ,�ޱ�����,գ�ۼ�ӳ�������ն��$n����磬\n";
	mycor=me->query_cor();
	youcps=target->query_cps();
	ob=target->query_temp("weapon");
          str="���";
	if(objectp(ob)) str="���е�"+ob->query("name");
	ap=COMBAT_D->skill_power(me, "unarmed", SKILL_USAGE_ATTACK);
	dp=COMBAT_D->skill_power(target,"dodge", SKILL_USAGE_DEFENSE);
	dp/=2;	
	pp=COMBAT_D->skill_power(target,"unarmed", SKILL_USAGE_DEFENSE);
	pp/=2;
	if(objectp(ob)) pp/=2;
	mystr=me->query_str();
	youstr=me->query_str();
	damage_bonus=mystr*(100+me->query("force_factor"))/100;

        if( random(youcps) < 10 || random(ap+dp)>dp) {
                  msg += "$n����"+str+"����������ȴ��$N�õ�������\n";
                  msg += "$N���Ƴ����ʹ���ˡ��廢�𡹣�\n\n" NOR;
                  msg += HIR "$N���еı�����Ȼն��$nͷ������һ��Ҳ��һ������������,���廢���ŵ��еľ���,����:**����Ͽ**";
		if(random(ap+pp)>pp) {
                          msg += "����ڵ�һ������$n�ļ���ϡ�\n" NOR;
			damage=calculate_damage(me, target, 100, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
                                  msg+=COMBAT_D->damage_msg(damage, "���ص�����");
			}
		}
                  else msg+="�����$n�鵲���ˡ�\n" NOR;
                   msg += HIR "\n������$N�ձ������ᵶ����$n�����һ��:Ω�Ҷ���!�����廢���ŵ��еĻ���Ⱥ��!�׺��ޱ�,�������.\n";
                  msg += "ͬʱײ��$n.";
		if(random(ap+pp)>pp) {
			msg += "�������$n��\n" NOR;
			damage=calculate_damage(me, target, 120, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
			if(damage>0) {
				target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
				msg+=COMBAT_D->damage_msg(damage, "����");
			}
		}
		else msg+="�����$n�����ˡ�\n" NOR;
                    msg += CYN "\n$N����˳���ֳ�һ��,����$n�ұۿ��������������·�,�����ޱ�.ԭ�������廢���ŵ��е�**��Х����**,������ÿ���$n,$N��ס���ʹ����֣�";
		if(random(ap+pp)>pp) {
                          msg += "���$nһ��ͷˤ�ڵ��ϡ�\n" NOR;
                        damage=calculate_damage(me, target, 150, damage_bonus);
			wound=random(damage-(int)target->query_temp("apply/armor"));
                        if(damage>0) {
                                target->receive_damage("kee", damage, me);
				if(wound>0) target->receive_wound("kee", wound, me);
                  msg+=COMBAT_D->damage_msg(damage, "�˿�");
                        }
                }
                else msg+="�����$nһ�����ģ�ȴûˤ����\n" NOR;
		message_vision(msg, me, target);
		msg+=COMBAT_D->report_status(target, 0);
	} else {
		msg += "����$p������$P����ͼ�����Խ����\n" NOR;
		message_vision(msg, me, target);
	}
  delay = random(3);
	me->start_busy(delay);
    me->add("force", -100);

	return 1;
}

int calculate_damage(object me, object target, int base_damage, int damage_bonus)
{
	int damage;
	int myexp, youexp;

	damage=base_damage+(damage_bonus+random(damage_bonus))/2;
	myexp=me->query("combat_exp");
	youexp=target->query("combat_exp");
	if(random(youexp)>myexp) {
		damage-=damage/3;
		youexp/=2;
	}
	if (wizardp(me) && me->query("env/combat")=="verbose")
		tell_object(me, sprintf(GRN "damage: %d\n" NOR, damage));

	return damage;
}

