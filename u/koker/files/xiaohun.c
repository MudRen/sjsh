//��Ȼ������

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
      object weapon=me->query_temp("weapon");
      int enhance,damage;
      string str;

      if (!weapon) return 0;
      if( !target ) target = offensive_target(me);
      if( !target || !target->is_character()||target->is_corpse()||target==me)
          return notify_fail("��Ҫ����˭��\n");
      if (!me->is_fighting())
             return notify_fail("��Ȼ������ֻ����ս����ʹ�ã�\n");
           
     if( time()-(int)me->query_temp("xiaohun_end") < 5 )
                   return notify_fail("����������������\n");      
     //if(me->query("family/family_name") != "��˿��")
       //         return notify_fail("[��Ȼ������]����˿������֮�ܣ�\n");
                
     if (me->query_skill("qingxia-jian",1)<150)
          return notify_fail("�����ϼ����̫����������Ȼ�����ơ�\n");
      if (me->query_skill("lanhua-shou",1)<150) 
          return notify_fail("���������̫����������Ȼ�����ơ�\n");
    if (me->query_skill("jiuyin-xinjing",1)<150)
        return notify_fail("��ľ����ķ���Ϊ���������������Ȼ�����ơ�\n");
     if (me->query_skill_mapped("force")!="jiuyin-xinjing")
            return notify_fail("��Ȼ�����Ʊ�����Ͼ����ķ�����ʹ�á�\n");
     if (me->query_skill_mapped("unarmed")!="lanhua-shou")
            return notify_fail("��Ȼ�����Ʊ�����������ֲ���ʹ�á�\n");
      if (me->query("force")<150)
           return notify_fail("���������̣����Գ��С�\n");
    message_vision(HIM"\n$N���뵱�հ��˲�����Ȼ�����ɵķ�����ơ�"NOR,me);
    //weapon->unequip();
    weapon->set_temp("original/use_apply_skill",weapon->query("use_apply_skill"));
    weapon->set_temp("original/skill_type",weapon->query("apply/skill_type"));
    weapon->set("use_apply_skill",1);
    weapon->set("apply/skill_type","unarmed");
    enhance=me->query_skill("lanhua-shou",1);
    me->add_temp("apply/attack", enhance);  
    damage=me->query_skill("jiuyin-xinjing",1);
    damage=damage/2;
    me->add_temp("apply/damage",damage);        
    COMBAT_D->do_attack(me, target);
    weapon->set("use_apply_skill",weapon->query_temp("original/use_apply_skill"));
    weapon->set("apply/skill_type",weapon->query_temp("original/skill_type"));
    me->add_temp("apply/attack",-enhance);
    me->add_temp("apply/damage",-damage);
    //weapon->wield();
    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+"��"+me->name()+"����˿�����С���Ȼ�����ơ������ˣ�����ʱ�����ϻ��в�������ۣ�";
//                         message("channel:rumor",HIM"����Ѩ���硿ĳ�ˣ�"+str+"\n"NOR,users());
                       }
    me->reset_action();
    me->set_temp("xiaohun_end",time());
    return 1;
}

