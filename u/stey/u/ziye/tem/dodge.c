// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
       string msg;
       int extra,add_dodge;
       string *mapped;
       mapping map;
       if ( me->query("sen")<30 )
            return notify_fail(RED"��Ԫ�񲻼�,ǿ���˹��Ầ���Լ�!\n"NOR);
       if ( me->query("force")<100 )
            return notify_fail(RED"������������ǿ���˹��Ầ���Լ�!\n"NOR);
        extra = me->query_skill("xiake-bufa",1);
        if (extra < 30) return notify_fail(RED"��ġ����Ͳ��������������죡\n"NOR);
       map = me->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});
        if( member_array("xiake-shengong",mapped)==-1 )
                return notify_fail(HIR+"������ʹ�õ��Ṧ�롾���Ͳ�������ִ�������ʩչ�����Ǻ���������\n"+NOR);
        if( member_array("xiake-shengong",mapped)==-1 )
                return notify_fail(HIR+"��������������������Ͳ�����ϣ�����ʩչ�����Ǻ���������\n"+NOR);
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIR"�����Ǻ�������"+NOR+"ֻ�ܶ�ս���еĶ���ʹ�á�\n"+NOR);
       if( me->query_skill("xiake-bufa",1)<100 )
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/3) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������.\n"NOR,target);
                        target->start_busy(2);
        if((me->query("family/family_name")!="���͵�"))
        {    me->start_busy(random(3));   return 1;   }
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������.\n"+NOR,me);
                        me->start_busy(3);
                  }
         }
      if( (me->query_skill("xiake-bufa",1)<300)&&(me->query_skill("xiake-bufa",1)>100) )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")/2) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������..\n"NOR,target);
        if((me->query("family/family_name")!="���͵�"))
        {    me->start_busy(random(3));   return 1;   }
                        me->start_busy(3);
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������..\n"+NOR,me);
                        me->start_busy(3);
               }
                 }
          if( me->query_skill("xiake-bufa",1)>300 )            
         {
                if(target->is_busy())
                        return notify_fail(target->name()+"�Ѿ���æ�����ˣ�\n");
                message_vision(HIY"\n$N�Ų�������������$n����ת��������\n\n"+NOR,me,target);
                if(random((int)target->query("combat_exp")*7/10) < (int)me->query("combat_exp"))
                {
                        message_vision(HIR"ֻ��"+target->query("name")+"���ܾ�����ǧ��ֻ"HIY"��"HIC"��"HIM"��"HIG"��"HIB"��"HIY",\n
                              ���$N���ŵ��ۻ����ң���Ӧ��Ͼ���ֽŶ�ʱ��������...\n"NOR,target);

                        target->start_busy(4);
        if((me->query("family/family_name")!="���͵�"))
        {    me->start_busy(random(4));   return 1;   }
                }
                else
                {
                        message_vision(HIY"���$N�Լ�ת�˸�ͷ���ۻ����ֽŶ�ʱ��������...\n"+NOR,me);
                        me->start_busy(2);
               }
                 }
       me->receive_damage("sen", 50);
       me->add("force", -100);
        return 1;
}


