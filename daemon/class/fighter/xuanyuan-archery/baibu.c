//chaofeng.c yushu 2000.10.25

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        int ii,req,num_anqi,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string anqi_type,b_unit;

   int wound=0;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("��Ҫ����˭��\n");
        
      weapon = me->query_temp("weapon");
 req=(int)me->query_skill("archery", 1)+(int)me->query_skill("xuanyuan-archery", 1);


      if (weapon)  
        {
        if (weapon->query("anqi/allow") != 1) num_anqi=0;
        else num_anqi=weapon->query("anqi/now");
        }

        if (me->query_skill_mapped("force")!="lengquan-force")
                 return notify_fail("�ٲ�����������Ϻõ��ڹ���������\n");
        if(req < 150)
              return notify_fail("�㹦����Ч�ȼ�����150��\n");
      if(req < 150 && weapon->query("anqi/now") ==0)
             return notify_fail("��û�м��������ˣ�\n");
       if (me->query("force")<200)
       return notify_fail("���������̣��޷�����ǿ����\n");

 if (me->query_temp("baibu_busy")) return notify_fail("������Ҫʱ��ѽ��\n");
         me->add("force", -300);

        if(num_anqi <=0) 
            { anqi_type="����"; damage=me->query("force_factor")+10; }
        else if (req < 150)
           { anqi_type=weapon->query("anqi/type"); damage=me->query_temp("apply/damage");}
        else 
            { anqi_type=weapon->query("anqi/type")+"��������";
             damage=me->query_temp("apply/damage")+me->query("force_factor")+10;}
         
       msg = HIW"ֻ��$N����"+weapon->query("name")+HIW"�������£���Ծ��ҫ�۵Ĺ�â������"
                  +anqi_type+HIW"�����������$n������\n" NOR;

         if (num_anqi > 5 || num_anqi == 0) max_hit=5;
        else max_hit=weapon->query("anqi/now");

        num_hit=random(max_hit/2)+(max_hit/2);

        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;

        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}


 if (weapon->query("anqi/type")=="�����") b_unit="֧";
        else b_unit="��";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
          {weapon->delete("anqi/type");  weapon->set("long",weapon->query("orilong"));}
        else weapon->set("long",weapon->query("orilong")+"�����Ѿ�װ��"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"��������uninstall��\n"); 

        if (hitt==0)
	  {
           msg += HIW "$n��æ������һ�࣬�����˷����ļ���\n"NOR;
           message_vision(msg, me, target);
           me->start_busy(random(3));
           if(!target->is_busy())
               target->start_busy(random(3));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
    if (random(damage)>target->query_temp("apply/armor"))  {
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
       wound=1;
  }
 msg += HIW "$n�������������ϱ�"+chinese_number(hitt)+HIW "������"+anqi_type+"��\n"NOR;
           message_vision(msg, me, target);
       me->start_busy(random(2));
     COMBAT_D->report_status(target,wound);
           if(!target->is_busy())
           target->start_busy(random(5));
           }
 msg = HIW "$n����$NЦ������С�ӣ�������û�д�þ������ﶪ������?������ô��ʰ�㣡\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);
me->set_temp("baibu_busy",1);
    call_out("remove_effect",3+random(5),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
 me->delete_temp("baibu_busy");
}
