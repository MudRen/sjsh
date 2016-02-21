#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"ʮ�ֽ�ͷ","where":"/d/city/center"   ]),
         ([ "sxy":"�׻����","where":"/d/city/baihu-w1"]),   
         ([ "sxy":"�׻����","where":"/d/city/baihu-w2"   ]),   
         ([ "sxy":"����������","where":"/d/city/ximen" ]),   
         ([ "sxy":"������","where":"/d/city/xuanwu-n0"]),   
         ([ "sxy":"��ˮ֮��","where":"/d/changan/wside1"]),   
         ([ "sxy":"��ˮ�ű�","where":"/d/changan/nbridge"]),   
         ([ "sxy":"��ٵ�","where":"/d/changan/broadway1"]),   
         ([ "sxy":"����","where":"/d/changan/nanyue"]),   
         ([ "sxy":"�Ϻ�֮��","where":"/d/changan/southseashore"]),   
         ([ "sxy":"�߼Ҵ���","where":"/d/gao/gate"]),   
         ([ "sxy":"�꾩����","where":"/d/kaifeng/tieta"]),   
         ([ "sxy":"Ң����","where":"/d/kaifeng/yao5"]),   
         ([ "sxy":"��ͤ��","where":"/d/kaifeng/guting3"]),   
         ([ "sxy":"����·","where":"/d/kaifeng/xihu6"]),    
         ([ "sxy":"������","where":"/d/kaifeng/yuwang1"]),    
         ([ "sxy":"������","where":"/d/city/southjie3"]),    
         ([ "sxy":"�������","where":"/d/kaifeng/chengmen"]),    
         ([ "sxy":"�����Ƕ���","where":"/d/city/dongmen"]),    
         ([ "sxy":"���Ͻ�","where":"/d/eastway/wangnan5"])    
                });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIB "���������������ʱ�޵��ˣ����ȥ�����\n" NOR );     
      me->delete("job/sxy");
      me->set("job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "��������سǲ����������Ҵ���ѽ����\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "��Ȼ�������˴�����Ѿ���" + sxy["sxy"] + "���ˣ�\n" NOR );
        ob = new("/d/obj/npc/yaoguai");
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "����س�������ʱ�޵��ˣ����ȥ�����\n" NOR );
      me->delete("job/sxy");
      me->set("job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}

